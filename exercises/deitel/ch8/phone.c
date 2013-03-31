/* Exercise 8.14 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
   char phone[] = "(123) 456-78990", *tokp;
   int prefix;
   long int number;

   tokp = strtok(phone, ")");
   prefix = atoi(++tokp);

   tokp = strtok(NULL, "-");
   number = atoi( strcat(++tokp, strtok(NULL, " ")) );

   printf("Prefix: %d\n", prefix);
   printf("Number: %ld\n", number);

   return 0;
} /* E0F main */

