/* Exercise 8.31 */

#include <stdio.h>
#include <string.h>

char *strchr(const char *s, int c);
size_t strcspn(const char *s1, const char *s2);
size_t strspn(const char *s1, const char *s2);
char *strpbrk(const char *s1, const char *s2);
char *strrchr(const char *s, int c);
char *strstr(const char *S1, const char *s2);
char *strtok(char *s1, const char *s2);

int main(void)
{
   char string[] = "yet another test string";
   char match[] = "not";
   char search = 'n';
   char *p;
   int size;
 
   p = strchr(string, search);
   printf("strchr(string, search): %s\n", p);

   size = strcspn(string, match); 
   printf("strcspn(string, match): %d\n", size);

   size = strspn(string, match); 
   printf("strspn(string, match): %d\n", size);

   p = strpbrk(string, match);
   printf("strpbrk(string, match): %s\n", p);

   p = strrchr(string, search);
   printf("strrchr(string, search): %s\n", p);

   p = strstr(string, match);
   printf("strstr(string, match): %s\n", p);

   printf("\nTokenize..\n");
   p = strtok(string, " ");
   while( p != NULL ) {
      printf("strtok(string, \" \"): %s\n", p);
      p = strtok(NULL, " ");
   }

   return 0;
}

/* locate the first occurrence of c to s and returns
 * a pointer to c if will be found or NULL if not */
char *strchr(const char *s, int c)
{
   int i;

   for(i = 0; i < (int)strlen(s); i++) {
      if(s[i] == c)
	 return (char *)&s[i];
   }

   return NULL;

} /* eof strchr() */ 

/* returns the size of initial segment of s1 which
 * don't contains nobody of the characters in s2 */
size_t strcspn(const char *s1, const char *s2)
{
   int i, j;

   for(i = 0; s1[i] != '\0'; i++) {
      for(j = 0; s2[j] != '\0'; j++) {

	 if(s1[i] == s2[j])
	    return i + 1;

      }
   }

   return -1;
} /* eof strcspn() */

/* returns the size of initial segment of s1 which
 * contains only the characters in the string s2 */
size_t strspn(const char *s1, const char *s2)
{
   int i, j, f;

   for(i = 0, f = 1; s1[i] != '\0' && f; i++) {

      f = 0;

      for(j = 0; s2[j] != '\0'; j++) {
	 if(s1[i] == s2[j]) {
	    f = 1;
	    break;
	 }
      }
   }

   return i - 1;
} /* eof strspn() */

/* locate to s1 one of the characters
 * in s2 and returns a pointer to it */
char *strpbrk(const char *s1, const char *s2)
{
   int i, j;

   for(i = 0; s1[i] != '\0'; i++) {
      for(j = 0; s2[j] != '\0'; j++) {
	 if(s1[i] == s2[j])
	    return (char *)&s1[i];
      }
   }

   return NULL;
} /* eof strpbrk() */

/* locate the latest occurrence of c in
 * the string s and return its position */
char *strrchr(const char *s, int c)
{
   int i;

   for(i = (int)strlen(s) - 1; i >= 0; i--) {
      if(s[i] == c)
	 return (char *)&s[i];
   }

   return NULL;
} /* eof strrchr() */

/* locate the string s2 to s1 and return its position */
char *strstr(const char *s1, const char *s2)
{
   int i, j;

   for(i = 0; s1[i] != '\0'; i++) {
      if(s1[i] == s2[0]) {

	 for(j = 0; s2[j] != '\0'; j++) {
	    if(s1[i + j] != s2[j]) 
	       break;
	 }

	 if(j == (int)strlen(s2))
	    return (char *)&s1[i];

      }
   }

   return NULL;
} /* eof strstr() */

/* tokenize s1 using the separator(s) in s2 */
char *strtok(char *s1, const char *s2)
{
   int i, f, d;
   static char *last; 

   /* To be continue.. */ 
   if(s1 == NULL) {
      if(last == NULL)
	 return NULL;
      s1 = last;

   }

   /* loop the string */
   for(i = d = 0; s1[i] != '\0'; i++) {

      /* search the separator(s) */
      if(strchr(s2, s1[i]) != NULL)
	 f = 1;
      else
	 f = 0;

      /* search the first non-separator character */
      if(!d && !f) {
	 s1 = &s1[i];
	 d = 1; /* skip this block the next loop */
	 continue;
      }

      /* check if the latest token */
      if(s1[i + 1] == '\0') {
	 f = 1;
	 ++i;
      }

      /* search "the next" separator */ 
      if(d && f) {
	 if(s1[i] != '\0') {
	    s1[i] = '\0';
            last = &s1[i + 1];
	 }
	 else
	    last = NULL;
	 return s1;
      }
   }

   return NULL;
} /* eof strtok() */

