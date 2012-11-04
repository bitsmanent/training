/* See LICENSE file for copyright and license details.
 *
 * Maze generator - Implements the Deep-First Search algorithm.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define N (1<<3)	/* North */
#define S (1<<2)	/* South */
#define W (1<<1)	/* West */
#define E (0x01)	/* East */
#define A (N|S|W|E)	/* All the above */

#define BORDERS		12	/* Unused */
#define WALLS		8
#define SOLUTION	4	/* Unused */
#define BACKTICK	0	/* Unused */

#define ROWS	20
#define COLS	20

#define ISSET(C, W)	(W == (C & W))

/* globals */
int rows, cols;

/* function declarations */
void maze_gen(short int *grid, int TotalCells);
void maze_open(short int *grid);
int nextcell(short int *grid, int cell);
void pulldown(short int *grid, int CurrentCell, int cell);
void push(int *stack, int *top, int cell);
int pop(int *stack, int *top);
void maze_show(short int *grid);

/* function implementations */
int
main(int argc, char *argv[]) {
	short int *grid;
	int c;

	rows = ROWS;
	cols = COLS;

	while((c = getopt(argc, argv, "c:r:h")) != -1) {
		switch(c) {
			case 'c':
				cols = atoi(optarg);
				break;
			case 'r':
				rows = atoi(optarg);
				break;
			case 'h':
				printf(
					"Usage: %s -<hV> [-c cols] [-r rows]\n"
					"\nOptions\n"
					"   -r rows\t: set the rows (default: %d)\n"
					"   -c cols\t: set the columns (default: %d)\n"
					"   -h\t: show this help\n"
					"   -V\t: show the version and exit\n"
					"\n",
				argv[0], ROWS, COLS);
				return 1;
				break;
			default:
				printf("Usage: %s -<hV> [-c cols] [-r rows]\n", argv[0]);
				return 1;
		}
	}

	if(rows <= 0|| cols <= 0) {
		fprintf(stderr, "%s: invalid maze size (columns or rows)\n", argv[0]);
		return 1;
	}

	if((grid = malloc(rows * cols * sizeof(short int))) == NULL) {
		fprintf(stderr, "Sorry, there is not enough memory available.\n");
		return 1;
	}

	srandom(time(NULL));
	memset(grid, '\0', rows * cols);

	maze_gen(grid, rows * cols);
	maze_open(grid);
	maze_show(grid);

	free(grid);

	return 0;
}

void
maze_open(short int *grid) {
	int i;

	for(i = 0; i < 2; i++) {
		switch(1 + random() % 4) {
			case 1: /* north */
				grid[random() % cols] ^= N << WALLS;
				break;
			case 2: /* south */
				grid[cols * (rows - 1) + (random() % cols)] ^= S << WALLS;
				break;
			case 3: /* east */
				grid[(random() % rows) * cols + (cols - 1)] ^= E << WALLS;
				break;
			case 4: /* west */
				grid[(random() % rows) * cols] ^= W << WALLS;
				break;
		}
	}
}

void
push(int *stack, int *top, int cell) {
	stack[(*top)++] = cell;
}

int
pop(int *stack, int *top) {  
	if(! *top) {
		printf("The stack is empty.\n");
		return 0;
	}

	return stack[--(*top)];
}

void
maze_gen(short int *grid, int TotalCells) {
	int CurrentCell = random() / (RAND_MAX / TotalCells + 1);
	int VisitedCells = 1;
	int AdCell; /* Adiacent cell */
	int *stack, top = 0;
	int i;

	if(! (stack = malloc(sizeof(int) * TotalCells)))
		return;

	for(i = 0; i < rows * cols; i++)
		grid[i] = A << WALLS;

	while(VisitedCells < TotalCells) {
		if((AdCell = nextcell(grid, CurrentCell)) != -1) {
			pulldown(grid, CurrentCell, AdCell);

			push(stack, &top, CurrentCell);
			CurrentCell = AdCell;
			++VisitedCells;
		}
		else
			CurrentCell = pop(stack, &top);
	}
}

int
nextcell(short int *grid, int cell) {
	int idx = 0, cells[4] = {0};

	/* TODO: cleanup this code */

	if(cell % cols && cell - 1 >= 0 && ISSET(grid[cell - 1], A << WALLS))
		cells[idx++] = cell - 1;

	if((cell % cols) != (cols - 1) &&
	     cell + 1 < rows * cols && ISSET(grid[cell + 1], A << WALLS))
		cells[idx++] = cell + 1;

	if(cell - cols >= 0 && ISSET(grid[cell - cols], A << WALLS))
		cells[idx++] = cell - cols;

	if(cell + cols < rows * cols && ISSET(grid[cell + cols], A << WALLS))
		cells[idx++] = cell + cols;

	return ! idx ? -1 : cells[random() / (RAND_MAX / idx + 1)];
}

void
pulldown(short int *grid, int CurrentCell, int cell) {

	/* Note: I have to pull down the walls in both CurrentCell and cell in
	 * order be make showmaze() works properly. */

	if(CurrentCell == cell - 1) {
		grid[CurrentCell] ^= E << WALLS;
		grid[cell] ^= W << WALLS;
	}

	else if(CurrentCell == cell + 1) {
		grid[CurrentCell] ^= W << WALLS;
		grid[cell] ^= E << WALLS;
	}

	else if(CurrentCell < cell) {
		grid[CurrentCell] ^= S << WALLS;
		grid[cell] ^= N << WALLS;
	}

	else if(CurrentCell > cell) {
		grid[CurrentCell] ^= N << WALLS;
		grid[cell] ^= S << WALLS;
	}

}

void
maze_show(short int *grid) {
	int i;

	printf(" ");
	for(i = 0; i < cols; i++)
		printf("%c%c", ISSET(grid[i], N << WALLS) ?
			'_' : ' ', (i == cols - 1 ? ' ' : '_'));

	for(i = 0; i < rows * cols; i++) {
		if(!(i % cols)) {
			printf("\n%c", ISSET(grid[i], W << WALLS) ? '|' : ' ');
		}

		printf("%c%c",
			ISSET(grid[i], S << WALLS) ? '_' : ' ',
			ISSET(grid[i], E << WALLS) ? '|' : '_');
	}

	printf("\n");

}
