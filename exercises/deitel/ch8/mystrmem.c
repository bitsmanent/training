/* Exercise 8.32 */

#include <stdio.h>

void *memcpy(void *s1, const void *s2, size_t n);
void *memmove(void *s1, const void *s2, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
void *memchr(const void *s, int c, size_t n);
void *memset(void *s, int c, size_t n);

int main(void)
{
   char strsrc[] = "this is a string!";
   char strdst[40] = { 0 }, *strp;
   int n;

   strp = memcpy(strdst, strsrc, sizeof(strdst));
   printf("memcpy(): %s\n", strp);

   strp = memmove(strdst, "\"ab\"", 4);
   printf("memmove(): %s\n", strp);

   n = memcmp(strdst, strsrc, 5);
   printf("memcmp(): %d\n", n);

   strp = memchr(strsrc, 'a', sizeof(strsrc));
   printf("memchr(): %s\n", strp);

   strp = memset(strdst, 'x', 4);
   printf("memset(): %s\n", strdst);

   return 0;
} /* E0F main */

/* copy n bytes from s2 to s1 */
void *memcpy(void *s1, const void *s2, size_t n)
{
   int i;
   char *dst = s1;
   const char *src = s2;

   for(i = 0; i < (int)n && (*dst++ = *src++) != '\0'; i++)
      ; /* Empty body */

   return s1;
} /* eof memcpy() */

/* copy n bytes from s2 to s1. works even
 * if s2 and s1 represents the same array */
void *memmove(void *s1, const void *s2, size_t n)
{
   int i;
   char *dst = s1, *tmp;
   const char *src = s2;

   for(i = 0; i < (int)n; i++)
      *(tmp + i) = *(src + i);

   for(i = 0; i < (int)n; i++)
      *dst++ = *tmp++;

   return s1;
} /* eof memmove() */

/* compare n bytes of s1 and s2 */
int memcmp(const void *s1, const void *s2, size_t n)
{
   int i;
   const char *s = s1, *d = s2;

   long n1 = 0, n2 = 0;

   for(i = 0; i < (int)n && s[i] != '\0' && d[i] != '\0'; i++) {
      n1 += s[i];
      n2 += d[i];
   }

   return n1 - n2;
} /* eof memcmp() */

/* locate the character c to the string s */
void *memchr(const void *s, int c, size_t n)
{
   int i;
   char *p = (char *)s;

   for(i = 0; i < (int)n && p[i] != '\0'; i++) {
      if( p[i] == (unsigned char)c ) {
	 return &p[i];
      }
   }

   return NULL;
} /* eof memchr() */

/* writes n bytes of c to s */
void *memset(void *s, int c, size_t n)
{
   int i;
   char *p = s;

   for(i = 0; i < (int)n; i++) {
      p[i] = (unsigned char)c;
   }

   return s;
} /* eof memset() */

