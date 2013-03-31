/* Exercise 8.30 */

/* WRONG!! WRONG!! WRONG!! */

#include <stdio.h>

int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);

int main(void)
{
   char string1[] = "abcdef";
   char string2[] = "abcdea";

   printf("strcmp() = %d\n", strcmp(string1, string2) );
   printf("strncmp() = %d\n", strncmp(string1, string2, 4) ); 

   return 0;
} /* E0F main */

/* Compare two strings */
int strcmp(const char *s1, const char *s2)
{
   int i;
   long n1 = 0, n2 = 0;

   for(i = 0; s1[i] != '\0'; i++)
      n1 += s1[i];

   for(i = 0; s2[i] != '\0'; i++)
      n2 += s2[i];

   /* Second version
   for(i = 0; *(s1 + i) != '\0'; i++)
      n1 += *(s1 + i);

   for(i = 0; *(s2 + i) != '\0'; i++)
      n2 += *(s2 + i);
   */

   return n1 - n2;

} /* eof strcmp() */

/* Compare n characters of two strings */
int strncmp(const char *s1, const char *s2, size_t n)
{
   int i;
   long n1 = 0, n2 = 0;

   for(i = 0; i < (int)n; i++) {
      if( s1[i] == '\0' )
	 break;

      n1 += s1[i];
      n2 += s2[i];

      /* Second version
      if( *(s1 + i) == '\0' )
	 break;

      n1 += *(s1 + i);
      n2 += *(s2 + i);
      */
   }

   return n1 - n2;

}

