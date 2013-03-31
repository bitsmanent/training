/* Exercise 8.26 */

#include <stdio.h>

int isdigit(int c);
int isalpha(int c);
int isalnum(int c);
int isxdigit(int c);
int islower(int c);
int isupper(int c);
int tolower(int c);
int toupper(int c);
int isspace(int c);
int iscntrl(int c);
int ispunct(int c);
int isprint(int c);
int isgraph(int c);

int main(void)
{
   char c;

   printf("Give me a char: ");
   scanf("%c", &c);

   printf("The char %c (%d) %s %s\n", c, c,
      isdigit(c) ? "is" : "is not", "a digit");

   printf("The char %c (%d) %s %s\n", c, c,
      isalpha(c) ? "is" : "is not", "alphabetic");

   printf("The char %c (%d) %s %s\n", c, c,
      isalnum(c) ? "is" : "is not", "alphanumeric");

   printf("The char %c (%d) %s %s\n", c, c,
      isxdigit(c) ? "is" : "is not", "hexadecimal");

   printf("The char %c (%d) %s %s\n", c, c,
      islower(c) ? "is" : "is not", "lower");

   printf("The char %c (%d) %s %s\n", c, c,
      isupper(c) ? "is" : "is not", "upper");

   printf("The char %c (%d) to lower is %c\n", c, c, tolower(c));
   printf("The char %c (%d) to upper is %c\n", c, c, toupper(c));

   printf("The char %c (%d) %s %s\n", c, c,
      iscntrl(c) ? "is" : "is not", "of control");

   printf("The char %c (%d) %s %s\n", c, c,
      ispunct(c) ? "is" : "is not", "a punctuation");

   printf("The char %c (%d) %s %s\n", c, c,
      isprint(c) ? "is" : "is not", "printing");

   printf("The char %c (%d) %s %s\n", c, c,
      isspace(c) ? "is" : "is not", "a space");

   printf("The char %c (%d) %s %s\n", c, c,
      isgraph(c) ? "is" : "is not", "a graph");

   return 0;

} /* E0F main */

/*
 * All the follow functions return true if the
 * test pass and false if the test don't pass.
*/

/* Check if c is a decimal character */
int isdigit(int c)
{
   if( c >= 48 && c <= 59 )
      return 1; /* True */
   return 0; /* False */

} /* eof isdigit() */

/* Check if c is an alphanumeric character */
int isalpha(int c)
{
   if( islower(c) || isupper(c) )
      return 1; /* True */
   return 0; /* False */
} /* eof isaplha() */

/* Check if c is an alphanumeric character */
int isalnum(int c)
{
   if( isalpha(c) || isdigit(c) )
      return 1; /* True */
   return 0; /* False */
} /* eof isalnum() */

/* Check if c is a hexadecimal character */
int isxdigit(int c)
{
   if( isdigit(c) || (tolower(c) >= 97 && tolower(c) <= 102) )
      return 1; /* True */
   return 0; /* False */
} /* eof isxdigit() */

/* Check if c is a lowercase character */
int islower(int c)
{
   if( c >= 97 && c <= 122 )
      return 1; /* True */
   return 0; /* False */
} /* eof islower() */

/* Check if c is an uppercase character */
int isupper(int c)
{
   if( c >= 65 && c <= 90 )
      return 1; /* True */
   return 0; /* False */
} /* eof isupper() */

/* If c is upper then will be converted
 * to lower else nothing will be done. */
int tolower(int c)
{
   if( isupper(c) )
      return c + 32;
   return c;
} /* eof tolower() */

/* If c is lower then will be converted
 * to upper else nothing will be done. */
int toupper(int c)
{
   if( islower(c) )
      return c - 32;
   return c;
} /* eof toupper() */

/* Check if c is a whitespace character */
int isspace(int c)
{
   if( (c >= 9 && c <= 13) || c == 32 )
      return 1; /* True */
   return 0; /* False */
} /* eof isspace() */

/* Check if c is a control character */ 
int iscntrl(int c)
{
   if( c < 32 || c > 126 )
      return 1; /* True */
   return 0; /* False */
} /* eof iscntrl() */

/* Check if c is a punctuation character: exlude the '(' and ')' */
int ispunct(int c)
{
   if( isprint(c) && c != 40 && c != 41 )
      return 1; /* True */
   return 0; /* False */
} /* eof ispunct() */

/* Check if c is a printing character */
int isprint(int c)
{
   if( !iscntrl(c) )
      return 1; /* True */
   return 0; /* False */
} /* eof isprint() */

/* Check if c is a graph character: exclude the space (' ') */
int isgraph(int c)
{
   if( isprint(c) && c != 32 )
      return 1; /* True */
   return 0; /* False */
}

