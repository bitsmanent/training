/* Exercise 8.28 */

#include <stdio.h>
#include <string.h>

char *strcpy(char *s1, const char *s2);
char *strncpy(char *s1, const char *s2, size_t n);
char *strcat(char *s1, const char *s2);
char *strncat(char *s1, const char *s2, size_t n);

int main(void)
{
   char string1[50] = "this is the first string";
   char string2[] = " and this is the 2nd :-)";

   printf("BeFoRe\n\tstring1[] = %s\n\tstring2[] = %s\n", string1, string2);

   /* Insert the function here */

   printf("\naFTeR\n\tstring1[] = %s\n\tstring2[] = %s\n", string1, string2);


   return 0;
} /* E0F main */

/* Copy s2 to s1 and return s1 */
char *strcpy(char *s1, const char *s2)
{
   int i;

   for(i = 0; ( s1[i] = s2[i] ) != '\0'; i++);

   /* Second version 
      for(i = 0; ( *(s1 + i) = *(s2 + i) ) != '\0'; i++);
   */

   return s1;

} /* eof strcpt(1) */

/* Copy n characters from s2 to s1 and return s1 */
char *strncpy(char *s1, const char *s2, size_t n)
{
   int i;

   for(i = 0; i < (int)n; i++) {
      if( ( s1[i] = s2[i] ) == '\0' )
      /* Second version
      if( ( *(s1 + i) = *(s2 + i) ) == '\0' )
      */
	 break;
   }

   return s1;
} /* eof strncpy() */

/* Append s2 to s1 and return s1 */
char *strcat(char *s1, const char *s2)
{
   int i, j = (int)strlen(s1);

   for(i = 0; ( s1[j + i] = s2[i] ) != '\0'; i++); 
   /* Second version
   for(i = 0; ( *(s1 + j + i) = *(s2 + i) ) != '\0'; i++); 
   */

   return s1;
} /* eof strcat() */

/* Append n characters from s2 to s1 and return s1 */
char *strncat(char *s1, const char *s2, size_t n)
{
   int i, j = (int)strlen(s1);

   for(i = 0; i < (int)n; i++) {
      if( (s1[i + j] = s2[i]) == '\0')
      /* Second version
      if( ( *(s1 + i + j) = *(s2 + i) ) == '\0')
      */
	 break;
   }

   return s1;
} /* eof strncat() */

