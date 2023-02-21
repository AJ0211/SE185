/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>   // Google this header file to learn more! :)

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double a, b, c;
    double filler;

    /* Put your code after this line */
	printf("enter the first value: ");
	scanf("%lf" , &a);
	printf("enter the second value: ");
	scanf(" %lf",&b);
	filler = sqrt(a*a + b*b);
	printf("The result is: %lf", filler);


    /* This next line will calculate the square root of whatever value is
     * inside the parenthesis and assigns it to the variable filler. */
 

    return 0;
}
