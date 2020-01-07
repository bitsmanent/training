/* Simple shell written in C.
 * Compile with: cc -std=c99 -pedantic -Wall -O0 -o gsh gsh.c -lreadline */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <err.h>
#include <errno.h>
#include <signal.h>
#include <wordexp.h>
#include <sys/wait.h>
#include <pwd.h>

/* Avoid some NetBSD obscure build time warning */
#if defined(__NetBSD__)
# define _FUNCTION_DEF
# define USE_VARARGS
# define PREFER_STDARG
#endif

#include <readline/readline.h>
#include <readline/history.h>

#ifdef PATH_MAX
static int      pathmax = PATH_MAX;
#else
static int      pathmax = 0;
#endif
#define PATH_MAX_GUESS  1024

#define SH_NAME		"gsh"
#define SH_VERSION	"0.01"

typedef struct {
	const char *name;
	void (*func)(int argc, char *argv[]);
	const char *desc;
	const char *args;
} keyword;

/* globals */
typedef void builtin(int, char *[]);
builtin
	do_exit,
	do_echo,
	do_putenv,
	do_setenv,
	do_unsetenv,
	do_getenv,
	do_help,
	do_cd
;
static const keyword tblkeys[] = {
	/* Command, Function,  Description, Arguments */
	{ "exit", do_exit, "Exit from the shell", "[exit code]" },
	{ "echo", do_echo, "Show a message", "[message]" },
	{ "putenv", do_putenv, "Set the enviroment given variable(s)", "<variable>=<value> [...]" },
	{ "setenv", do_setenv, "Set an environment variable", "<variable> <value>" },
	{ "unsetenv", do_unsetenv, "Unset the environment given variable(s)", "<variable> [...]" },
	{ "getenv", do_getenv, "Print the value of the given environment variable(s)", "<variable> [...]" },
	{ "cd", do_cd, "Change the current working directory", "[pathname | -]" },
	{ "help", do_help, "Show this help", "[command]" },
	{ NULL, NULL, NULL, NULL }
};

/* function declarations */
int sh_init(void);
int run_cmd(int argc, char *argv[]);
int run_key(int argc, char *argv[]);
void remove_comment(char *p);
void hdr_sigint(int sig);
void cmdhelp(const char *cmd, int descr);
void sigint_handler(int signum);
void execute_command(char *command);
char *strip_spaces(char *string);
char *path_alloc(size_t *size);

/* function implementations */
void
remove_comment(char *p) {
	register int i = 0;
	while(p[i] && p[i] != '#')
		++i;
	if(p[i])
		p[i] = '\0';
}

void
cmdhelp(const char *cmd, int descr) {
	int i;
	for(i = 0; tblkeys[i].name; i++) {
		if(!strncmp(tblkeys[i].name, cmd, strlen(tblkeys[i].name))) {
			if(descr)
				printf("%s\n", tblkeys[i].desc);
			printf("Usage: %s %s\n", tblkeys[i].name, tblkeys[i].args);
			break;
		}
	}
	if(!tblkeys[i].name)
		warnx("%s: unknown command", cmd);
}

char *
strip_spaces(char *string) {
	char *s, *e;
	for(s = string; *s == ' ' && *s; s++)
		;
	if(!*s)
		return s;
	for(e = s + strlen(s) - 1; *e == ' '; e--)
		;
	*(e + 1) = '\0';
	return s;
}

char *
path_alloc(size_t *size) {
	char *ptr;
	if(!pathmax) {
		errno = 0;
		if((pathmax = pathconf("/", _PC_PATH_MAX)) < 0) {
			if(!errno)
				pathmax = PATH_MAX_GUESS;
			else
	    			warnx("pathconf caused error while reading _PC_PATH_MAX");
		}
		else
			++pathmax;
	}
	if((ptr = malloc(pathmax + 1)) == NULL)
		warnx("cannot allocate the pathname");
	if(size != NULL)
		*size = pathmax + 1;
	return(ptr);
}
void
do_exit(int argc, char *argv[]) {
	if(argc > 2) {
		cmdhelp(argv[0], 0);
		return;
	}
	exit((argv && argv[1] ? atoi(argv[1]) : EXIT_SUCCESS));
}

void
do_echo(int argc, char *argv[]) {
	int i = 0;
	while(argv[++i]) {
		printf("%s", argv[i]);
		if(i == argc)
			break;
		printf(" ");
	}
	printf("\n");
}

void
do_putenv(int argc, char *argv[]) {
	size_t envsz;
	int i;
	char *envstr;
	if(argc == 1) {
		cmdhelp(argv[0], 0);
		return;
	}
	for(i = 0; i < argc; i++) {
		envsz = strlen(argv[i]) + 1;
		if((envstr = malloc(envsz)) == NULL)
			return;
		strncpy(envstr, argv[i], envsz);
		if(putenv(envstr))
			free(envstr);
	}
}

void
do_setenv(int argc, char *argv[]) {
	if(argc != 3) {
		cmdhelp(argv[0], 0);
		return;
	}
	setenv(argv[1], argv[2], 1);
}

void
do_unsetenv(int argc, char *argv[]) {
	if(argc == 1) {
		cmdhelp(argv[0], 0);
		return;
	}
	while( --argc && ! unsetenv(argv[argc]) )
		;
}

void
do_getenv(int argc, char *argv[]) {
	int i;
	if(argc == 1) {
		cmdhelp(argv[0], 0);
		return;
	}
	for(i = 1; i < argc; i++)
		printf("%s\n", getenv(argv[i]));
}

void
do_cd(int argc, char *argv[]) {
	struct passwd *pwd;
	size_t tplen;
	char *tp, *path;
	if(argc > 2) {
		cmdhelp(argv[0], 0);
		return;
	}
	if(!(path = argv[1])) {
		if(!(path = getenv("HOME"))) {
			if((pwd = getpwuid(getuid())) != NULL)
				path = pwd->pw_dir;

			else {
				/* This should never happen */
				warnx("%s: cannot get the user home directory", argv[0]);
				return;
			}
		}
	}
	if(*path == '-' && !path[1]) {
		if(!(path = getenv("OLDPWD")))
			return;
		printf("%s\n", path); /* TODO: An option should toggle this call */
	}
	tp = path_alloc(&tplen);
	getcwd(tp, tplen);
	if(chdir(path)) {
		warn("cd: %s", path);
		return;
	}
	setenv("OLDPWD", tp, 1);
}

void
do_help(int argc, char *argv[]) {
	int i;
	if(argc >= 2) {
		cmdhelp(argv[1], argc == 2);
		return;
	}
	printf("\n%s v.%s\n\n", SH_NAME, SH_VERSION);
	for(i = 0; tblkeys[i].name; i++)
		printf(" %-9s%s\n", tblkeys[i].name, tblkeys[i].desc);
	printf("\n");
}

int
run_key(int argc, char *argv[]) {
	register int i;
	for(i = 0; tblkeys[i].name; i++) {
		if(!strncmp(tblkeys[i].name, argv[0], strlen(tblkeys[i].name))) {
			tblkeys[i].func(argc, argv);
			return 0;
		}
	}
	return 1;
}

int
run_cmd(int argc, char *argv[]) {
	register pid_t pid;
	if((pid = fork()) == -1)
		return -1;
	else if(pid == 0) {
		execvp(argv[0], argv);

		/* Exit status
		 *    126: The program is not executable
		 *    127: The program was not found
		 *      1: any other error */
		if(errno == ENOENT)
			errx(127, "%s: command not found", argv[0]);
		else
			err((errno == EACCES ? 126 : 1), "%s", argv[0]);
	}
	else {
		while(waitpid(pid, NULL, 0) == -1) {
			if(errno != EINTR)
			return -1;
		}
	}
	return 0;
}

/* XXX clean things up here */
void
sigint_handler(int signum) {
	char *p;
	if(!*(p = strip_spaces(rl_line_buffer)))
		return;
	add_history(p);			/* Store it anyway */
	*rl_line_buffer = '\0';		/* Clear the buffer */
	rl_point =rl_end = 0;		/* Reset the offsets */
	rl_redisplay();			/* Update the line */
	printf("(interrupt)\n");	/* Show a message */
	rl_initialize();		/* (Re)Initialize the state */
	rl_redisplay();			/* Update the line */
}

int
sh_init() {
	signal(SIGINT, sigint_handler);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);

	putenv((char *)"PS1=$ ");
	putenv((char *)"IFS= \n\t");

	/* Set the default PATH, if unset (LFS 1.2) */
	if(!getenv("PATH"))
		putenv((char *)"PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin");

	/* XXX startup file? */

	return 0;
}

void
execute_command(char *command) {
	wordexp_t wordv;
	register int wordc, wret;
	if((wret = wordexp(command, &wordv, 0))) {
		switch(wret) {
			case WRDE_BADCHAR:
				warnx("illegal character");
				break;
			case WRDE_NOSPACE:
				warnx("out of memory");
				break;
			case WRDE_SYNTAX:
				warnx("syntax error");
				break;
		}

		return;
	}
	if(!wordv.we_wordv[0]) {
		wordfree(&wordv);
		return;
	}
	for(wordc = 0; wordv.we_wordv[wordc]; wordc++)
		;
	if(run_key(wordc, wordv.we_wordv)) {
		if(run_cmd(wordc, wordv.we_wordv))
			warn("run_cmd");
	}
	wordfree(&wordv);
}

int
main(void) {
	char *buf, *p;
	if(sh_init())
		return 1;
	while(1) {
		if((buf = readline(getenv("PS1"))) == NULL)
			break;
		remove_comment(p);
		if(*(p = strip_spaces(buf))) {
			add_history(p);
			execute_command(p);
		}
		free(buf);
	}
	printf("\n");
	return 0;
}
