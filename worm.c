/* See LICENSE file for copyright and license details.
 *
 * The Hermit Worm - Commodore64 snake-like game.
 */ 

#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HEAD 'o' /* normal head */
#define WORM 'w' /* worm's body */
#define EATH 'O' /* eating head */

#define MINROW 21
#define MINCOL 80

#define LEVEAT 5 /* Food eated befor to increment the level */
#define LEVMAX 9 /* Max speed (to preserve the refresh delay in auto-mode) */

/* Recursive list */
typedef struct list_t {
   int x;
   int y;
   struct list_t *next;
} List;

/* Routes */
enum { R_UP = 1, R_LEFT, R_DOWN, R_RIGHT } route;

/* function declarations */
void newnode(List **listp, int y, int x);
void wormshow(List *worm, char ch, char chhead);
void moveworm(List **worm, int way);
int isout(List *worm);
int isbite(List *worm);
int iseat(List *worm, int row, int col);
void killworm(List **worm);

/* function implementations */
int
main(int argc, char **argv) {
   int ch = 0, n, eating, trick = 0;
   int erow, ecol; /* eat position */
   int level, tricks, moves, score;

   WINDOW *wstat, *wpos, *wepos; /* Status and positions windows */
   List *worm = NULL, *current; /* THe LiST */

   int auto_mode = 0; /* Play without user interaction */

   level = tricks = moves = score = 0;
   srand( time(NULL) );

   /* check the flag for auto-mode */
   if( argc == 2 && argv[1][0] == '-' && argv[1][1] == 'a' )
      auto_mode = 1;

   initscr(); /* start of session */
   curs_set(0); /* hide the cursor */
   keypad(stdscr, TRUE); /* enable the function keys */
   cbreak();
   noecho();
   nodelay(stdscr, TRUE); /* unlock getch(3) */

   /* Check the terminal size */
   if( LINES < MINROW || COLS < MINCOL ) {
      endwin();
      printf("This game require a terminal size of %dx%d pixel.\n",
	 MINROW, MINCOL);
      printf("Your terminal size is: %dx%d\n", LINES, COLS);
      return -1;
   }

   /* Create the windows */
   wstat = subwin(stdscr, 3, COLS - COLS / 3, 2, COLS / 6); /* status */
   wpos = subwin(stdscr, 3, 9, 2, 3); /* worm position */
   wepos = subwin(stdscr, 3, 9, 2, COLS - 9 - 3); /* eat position */

   /* Add the first position */
   newnode(&worm, 1 + rand() % (COLS - 2), 6 + rand() % (LINES - 7));

   /* start point for the eat */
   erow = 6 + rand() % (LINES - 7);
   ecol = 1 + rand() % (COLS - 2);

   /* choose a random route */
   route = 1 + rand() % 4;

   wormshow(worm, WORM, HEAD); /* put the first WORM */
   mvprintw(erow, ecol, "%d", n = 1); /* put the first eat */

   /* main loop */
   while( (auto_mode ? getch() : (ch = getch())) != 'q' ) {
      /*
       * Auto-mode play
       *
       * NOTE: the worm can to bite himself losing the
       *       game which will be auto-restarted again.
       * 
      */
      if( auto_mode ) {
	 ch = 0; /* don't touch the user moves */

         /* choose the route, if needed */
	 if( worm->x < erow ) {
	    if( route != R_DOWN )
	       ch = 'j';
	 }
	 else if( worm->x > erow ) {
	    if( route != R_UP )
	       ch = 'k';
	 }
	 else if( worm->y < ecol ) {
	    if( route != R_RIGHT )
	       ch = 'l';
	 }
	 else {
	    if( route != R_LEFT )
	       ch = 'h';
	 }
      }

      switch(ch) {
	 case 'h':
	 case KEY_LEFT:
            route = R_LEFT; 
	    ++moves;
	    break;
	 case 'j':
	 case KEY_DOWN:
            route = R_DOWN;
	    ++moves;
	    break;
	 case 'k':
	 case KEY_UP:
            route = R_UP;
	    ++moves;
	    break;
	 case 'l':
	 case KEY_RIGHT:
            route = R_RIGHT;
	    ++moves;
	    break;
	 case 'p':
	 case ' ': /* space bar */
	    /* Pause */
	    nodelay(stdscr, FALSE); /* lock the getch() */

            mvprintw(LINES / 2, COLS / 2, "Pause!");
	    while( (ch = getch()) ) {
	       if( ch == 'p' || ch == ' ' )
		  break;
	       
	       clear();
               mvprintw(LINES / 2, COLS / 2, "Pause!");
	    }

	    nodelay(stdscr, TRUE); /* unlock the getch() */
	    clear();

	    break;
	 case 't': /* Tricks */
	    if( trick ) {
	       nodelay(stdscr, TRUE);
	       trick = 0;
	    }
	    else {
	       nodelay(stdscr, FALSE);
	       trick = 1;
	       ++tricks;
	    }
	    break;
	 case KEY_RESIZE: /* Terminal resize */
  	    nodelay(stdscr, FALSE);

            /* Check the terminal size */
            while( LINES < MINROW || COLS < MINCOL ) {
	       clear();
	       mvprintw(LINES / 2, COLS / 2 - 12, "Terminal size too small!");
	       mvprintw(LINES / 2 + 1, COLS / 2 - 16,
	          "Please, enlarge it and press a key");
	       getch();
            }
	    
	    nodelay(stdscr, TRUE);
	    clear();

	    break;
      } /* eof switch() */
      moveworm(&worm, route); /* move the worm */

      /*
       * Check if the "new" position is already
       * busy or it's out of the window.
      */
      if( isout(worm) || isbite(worm) || (auto_mode && level >= LEVMAX) ) {

	 if( level >= LEVMAX )
	    mvprintw(LINES / 2, COLS / 2 - 5, "Too fast!");
	 else
	    mvprintw(LINES / 2, COLS / 2 - 5, "You lose!");

	 mvprintw(LINES / 2 + 1, COLS / 2 - 10, "Your scores are: %.3d", score);

	 if( auto_mode ) {
	    mvprintw(LINES / 2 + 3, COLS / 2 - 6, "Restarting..");
	    refresh();

            /* reset the game */
	    killworm(&worm);
            newnode(&worm, 1 + rand() % (COLS - 2), 6 + rand() % (LINES - 7));
            erow = 6 + rand() % (LINES - 7);
            ecol = 1 + rand() % (COLS - 2);
	    score = level = eating = tricks = moves = 0;
	    n = 1;

	    sleep(2); /* leave that the user tastes the messsage :-) */
	    continue;
	 }
	 else {
	    mvprintw(LINES / 2 + 2, COLS / 2 - 10, "Press a key to exit..");

	    nodelay(stdscr, FALSE);
	    getch(); /* wait for input */

	    break;
	 }
      }

      eating = n; /* needed for the wormshow() call */

      /* If it's eating */
      while( iseat(worm, erow, ecol) ) {
	 /* Add a node on the top of worm (new head) */ 
	 current = worm;
	 while( current->next != NULL )
	    current = current->next;
	 newnode(&current->next, worm->y, worm->x);

         /* Change the eat's position */
         erow = 6 + rand() % (LINES - 7);
         ecol = 1 + rand() % (COLS - 2);
         ++n; /* Change the eat's number */ 

         score += level + 1; /* increment the points */

         /* Increase the level */
         if( !(n % LEVEAT) ) {
            ++level;
         }
      }

      erase(); /* clear the screen */
      box(stdscr, ACS_VLINE, ACS_HLINE); /* create the borders */
      mvprintw(erow, ecol, "%d", n); /* draw the eat */

      /* Show the status window (and its elemets) */
      mvwprintw(stdscr, 1, COLS / 2 - 37 / 2, /* Copy */
         "The Hermit worm - (C) 2006 Claudio M."); /* left */
      box(wstat, ACS_VLINE, ACS_HLINE); /* status box */
      mvwhline(stdscr, 5, 1, ACS_HLINE, COLS - 2); /* new top limit */

      /* Show the worm position */
      box(wepos, ACS_VLINE, ACS_HLINE); /* status box */
      mvwprintw(stdscr, 1, 3, "Worm Curs");
      mvwprintw(wepos, 1, 2, "%.2dx%.2d", erow, ecol);

      /* Show the eat position */
      box(wpos, ACS_VLINE, ACS_HLINE); /* status box */
      mvwprintw(stdscr, 1, COLS - 12, "Eat Curs");
      mvwprintw(wpos, 1, 2, "%.2dx%.2d", worm->x, worm->y);

      /* Show the informations */
      mvwprintw(wstat, 1, 3,
	 "TS:%.2dx%.2d | " /* Terminal size */
	 "SL:%.2d | "      /* Speed level */
	 "EM:%.2d | "      /* Eats missing */
	 "UM:%.3d | "      /* User moves */
	 "UT:%.2d | "      /* User tricks */
	 "Ss:%.3d",        /* Scores */
	 LINES, COLS, level + 1, LEVEAT - (n % LEVEAT),
	 moves, tricks, score);

      /*
       * Show the whole "new" worm
       * NOTE: this statement is not optimized - trash statement :-)
      */
      if( iseat(worm, erow + 1, ecol) || iseat(worm, erow - 1, ecol) ||
          iseat(worm, erow, ecol + 1) || iseat(worm, erow, ecol - 1) ) {
         wormshow(worm, WORM, EATH);
      }
      else
         wormshow(worm, WORM, HEAD);

      usleep( 100000 - level * 10000 );
   }

   endwin(); /* end of session */

   puts("\nEnd of game.");

   return 0;
} /* E0F main */

/*
 * Returns if the worm is out of the window
*/
int isout(List *worm)
{
    if( worm->x <= 5 || !worm->y || worm->x >= LINES - 1 || worm->y >= COLS - 1)
       return 1;

   return 0;
} /* eof isout() */

/*
 * Return if the worm is eating
*/
int iseat(List *worm, int row, int col)
{
   return (worm->x == row && worm->y == col);
} /* eof iseat() */

/*
 * Check if the worm is biting itself
*/
int isbite(List *worm)
{
   List *current = worm;

   while( (current = current->next) != NULL ) {
      if( worm->x == current->x && worm->y == current->y )
	 return 1;
   }

   return 0;
} /* eof isbite() */

/*
 * Show the worm (call refresh(3))
*/
void wormshow(List *worm, char ch, char chhead)
{
   List *current = worm->next;

   /* show the worm */
   while( current != NULL ) {
      mvprintw(current->x, current->y, "%c", ch);
      current = current->next;
   }
   mvprintw(worm->x, worm->y, "%c", chhead); /* show the head */

   refresh(); /* print the changes */

} /* eof wormshow() */

/*
 * Add a new node to the list
*/
void newnode(List **listp, int y, int x)
{
   List *newPtr;

   /* Allocate the memory */
   if( (newPtr = malloc( sizeof(List) )) == NULL ) {
      printf("Not enough memory to allocate the \"%d.%d\" element\n", x, y);
      return;
   }
   newPtr->next = *listp;
   newPtr->x = x;
   newPtr->y = y;

   *listp = newPtr;

} /* eof newnode() */

/*
 * Move the whole worm
*/
void moveworm(List **worm, int way)
{
   List *current = *worm;
   int n = 1, i;

   /* count the nodes */
   while( (current = current->next) != NULL )
     ++n;

   current = *worm; /* come back to the start point */
   while( --n ) {

      current = *worm;
      i = n;

      while( --i )
         current = current->next;

      /* update the position */
      current->next->x = current->x;
      current->next->y = current->y;
   }

   /* move the head */
   switch(way) {
      case R_UP:
         --( *worm )->x;
         break;
      case R_LEFT:
         --( *worm )->y;
         break;
      case R_DOWN:
         ++( *worm )->x;
         break;
      case R_RIGHT:
         ++( *worm )->y;
         break;
   }

} /* eof moveworm() */

/*
 * Kill the worm: free the whole worm's memory
*/
void killworm(List **worm)
{
   List *current;

   while(*worm != NULL) {
      current = *worm;
      *worm = (*worm)->next;
      free(current);
   }

} /* eof killworm() */

