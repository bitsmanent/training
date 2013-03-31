/* Exercise 5.25 */

float smallfloat(float, float, float);

int main()
{
   float num1, num2, num3;

   printf("Give me 3 float numbers: ");
   scanf("%f%f%f", &num1, &num2, &num3);
   printf("Smallest is %.2f\n", smallfloat(num1, num2, num3));

   return 0;
} /* E0F main */

/* return the smallest of three float numbers */
float smallfloat(float x, float y, float z)
{
   if(x <= y && x <= z)
      return x;
   else if(y < z)
      return y;
   else
      return z;

} /* eof smallfloat() */

