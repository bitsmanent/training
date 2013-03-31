/* Exercise 7.17 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>

#define LEN 70

void move(int who[]);
void show(int who[]);

int main(void)
{
   int who[2] = { 0, 0 };

   srand( time(NULL) );

   /* Start */
   printf("BANG !!!!!\nAND THEY'RE OF !!!!!");

   while(who[0] <= LEN && who[1] <= LEN) {
      printf("\n\n");

      move(who); /* move the players */
      show(who); /* show current position */

      sleep(1);
   }
   printf("\n\n");

   /* check the winner */
   if(who[0] > LEN && who[1] <= LEN) {
      printf("TORTOISE WINS!!! YAY!!!\n");
   }
   else if(who[1] > LEN && who[0] <= LEN) {
      printf("Hare wins. Yuch.\n");
   }
   else { /* There is no winner! */
      printf("who[0] = %d && who[1] = %d\n", who[0], who[1]);
      if( rand() % 2 ) {
         printf("It's a tie!\n");
      }
      else {
	 printf("I want to win the turtle!! :-)\n");
      }
   }

   return 0;
} /* E0F main */

/* Move the players */
void move(int who[])
{
   int i = 1 + rand() % 10;

   /* Move the turtle (who[0]) */
   if(i <= 5) /* 50% limped fast */
      who[0] += 3;

   else if(i >= 6 && i <= 7)/* 20% slide */
      who[0] -= 6;

   else /* i >=8: 30% limpied slow */
      ++who[0];

   /* Check if the turtle is out of path */
   if(who[0] < 0)
      who[0] = 0;


   /* Move the hare (who[1]) */
   if(i <= 2) /* 20% (sleep) */
      ; /* stay in the same position */

   else if(i >= 3 && i <= 4) /* 20% long jump */
      who[1] += 9;

   else if(i == 5) /* 10% Long slide */
      who[1] -= 12;

   else if(i >= 6 && i <= 8) /* 30% short jump */
      ++who[1]; 

   else /* i >= 9: 20% short slide */
      who[1] -= 2;

   /* Check if the hare is out of path */
   if(who[1] < 0)
      who[1] = 0;


} /* eof move() */

/* Show the situation ;) */
void show(int who[])
{
   int i;

   /* Show the turtle position */
   for(i = 0; i < LEN; i++) {

      /* If are both here */
      if(i == who[0] && i == who[1]) {
	 printf("OUCH!!!");
	 i += 6; /* Align the path */ 
      }

      /* If is the turtle */
      else if(i == who[0]) 
	 printf("T");
      
      /* If is the hare */
      else if(i == who[1])
	 printf("L");

      /* If is empty */
      else
	 printf(".");

   }

} /* eof show() */

