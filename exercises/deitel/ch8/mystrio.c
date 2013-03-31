/* Exercise 8.29 */

/* This exercise don't have any sense! */

int getchar(void);
char *gets(char *s);
int putchar(int c);
int puts(const char *s);

int main(void)
{
   char c, str[10];

   printf("Give me a char: ");
   c = getchar();

   printf("\nputchar(): %c\n", putchar(c));

   printf("Give me a string: ");
   gets(str);

   printf("puts(): ");
   puts(str);

   printf("\n");

   return 0;
} /* E0F main */

int getchar(void)
{
   char c;
   scanf("%c", &c);
   return c;
}

char *gets(char *s)
{
   scanf("%s", s);
   return s;
}

int putchar(int c)
{
   printf("%c", c);
   return c;
}

int puts(const char *s)
{
   printf("%s", s);

   if(*s != '\0')
      return 1;

   return -1;
}

