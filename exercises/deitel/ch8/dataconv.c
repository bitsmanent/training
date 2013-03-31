/* Exercise 8.36 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
   char data[11] = { 0 }, *tokp;

   printf("Insert data: ");
   gets(data);

   tokp = strtok(data, "/");
   printf("%d ", atoi(tokp)); 

   tokp = strtok(NULL, "/");

   switch(atoi(tokp)) {
      case 1:
	 printf("January");
	 break;
      case 2:
	 printf("February");
	 break;
      case 3:
	 printf("March");
	 break;
      case 4:
	 printf("April");
	 break;
      case 5:
	 printf("Maj");
	 break;
      case 6:
	 printf("June");
	 break;
      case 7:
	 printf("July");
	 break;
      case 8:
	 printf("August");
	 break;
      case 9:
	 printf("September");
	 break;
      case 10:
	 printf("October");
	 break;
      case 11:
	 printf("November");
	 break;
      case 12:
	 printf("December");
	 break;
      default:
	 printf("Unknown month");
   }

   tokp = strtok(NULL, "/");
   printf(" 19%d\n", atoi(tokp));

   return 0;
} /* E0F main */

