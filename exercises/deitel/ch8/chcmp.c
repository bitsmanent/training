/* Exercise 8.5 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
   char c;

   puts("Give me a char");
   c = getchar();
   putchar('\n');

   /* Start the comparision */
   printf("%c %s an alpha character (%u)\n",
      c, isalpha((int)c) ? "is" : "is not", isalpha((int)c));
   printf("%c %s an upper character (%u)\n",
      c, isupper((int)c) ? "is" : "is not", isupper((int)c));
   printf("%c %s a lower character (%u)\n",
      c, islower((int)c) ? "is" : "is not", islower((int)c));
   printf("%c %s a digit character (%u)\n",
      c, isdigit((int)c) ? "is" : "is not", isdigit((int)c));
   printf("%c %s a hex digit character (%u)\n",
      c, isxdigit((int)c) ? "is" : "is not", isxdigit((int)c));
   printf("%c %s an alnum character (%u)\n",
      c, isalnum((int)c) ? "is" : "is not", isalnum((int)c));
   printf("%c %s a space character (%u)\n",
      c, isspace((int)c) ? "is" : "is not", isspace((int)c));
   printf("%c %s a punctuation character (%u)\n",
      c, ispunct((int)c) ? "is" : "is not", ispunct((int)c));
   printf("%c %s a printer character (%u)\n",
      c, isprint((int)c) ? "is" : "is not", isprint((int)c));
   printf("%c %s a graphic character (%u)\n",
      c, isgraph((int)c) ? "is" : "is not", isgraph((int)c));
   printf("%c %s a control character (%u)\n",
      c, iscntrl((int)c) ? "is" : "is not", iscntrl((int)c));
   printf("%c %s a blank character (%u)\n",
      c, isblank((int)c) ? "is" : "is not", isblank((int)c));
   printf("%c %s an ASCII character (%u)\n",
      c, isascii((int)c) ? "is" : "is not", isascii((int)c));

   printf("%c to upper is %c\n", c, toupper((int)c));
   printf("%c to lower is %c\n", c, tolower((int)c));
   printf("%c to ASCII is %c\n", c, toascii((int)c));

   return 0;
} /* E0F main */

