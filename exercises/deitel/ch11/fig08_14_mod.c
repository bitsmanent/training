/* Exercise 11.15 */

/* Fig. 8.14: fig08_14.c
   Using getchar and puts */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{ 
   char c;              /* variable to hold character input by user */
   char sentence[ 80 ]; /* create char array */
   int i = 0;           /* initialize counter i */
   FILE *in = stdin, *out = stdout;
   char input[15], output[15];

   fputs( "enter your choice: ", out );
   scanf("%d%*c", &i);

   if(i == 1) {
      fputs( "Input file: ", out );
      scanf("%s", input);

      if( (in = fopen(input, "r")) == NULL) {
	 printf("%s: cannot open the file\n", input);
	 exit(-1);
      }

      fputs( "Output file: ", out );
      scanf("%s", output);

      if( (out = fopen(output, "w")) == NULL) {
	 printf("%s: cannot open the file\n", output);
	 exit(-1);
      }
   }
   else 
      /* prompt user to enter line of text */
      puts( "Enter a line of text:" ); 

   i = 0;

   /* use getchar to read each character */
   while( ( c = fgetc(in) ) != '\n') {
      sentence[ i++ ] = c; 
   } /* end while */

   sentence[ i++ ] = '\n'; /* insert a newline */
   sentence[ i ] = '\0'; /* terminate string */
   
   /* use puts to display sentence */
   fputs( "\nThe line entered was:\n", out ); 
   fputs( sentence, out );

   return 0; /* indicates successful termination */

} /* end main */

