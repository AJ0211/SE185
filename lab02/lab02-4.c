#include <stdio.h>
#include <math.h>
int main(void){
	printf("6427 + 1725 = %d\n",6427 + 1725);
	printf("(6971 * 3925) - 95 = %d\n",(6971 * 3925) -95);
	printf("79 + 12/5 = %.2f\n",79 + 12/5);
	printf("3640.0/107.9 = %.2f\n" , 3640.0/107.9);
	printf("(22/3) *3 = %d\n", (22/3) *3);
	printf("22/(3*3) = %d\n",22/(3*3)); 
	printf("22/(3*3) = %.2f\n", 22/(3*3));
	printf("22/3*3 = %.2f\n", 22/3*3);
	printf("(22.0/3) *3.0 = %.2f\n", (22.0/3)*3);
	printf("22.0/(3*3.0) = %d\n",22.0/(3*3.0));
	printf("22.0 / 3.0 * 3.0 =  %.2f\n", 22.0/3.0*3.0);
	
	double d = 23.567/M_PI;
	double r = d/2;
	printf("The area of the circle is: %.2f\n", pow(r,2)* M_PI);
	
	printf("14 feet is %.2f meters\n",14 * 0.3048);
	
	printf("76 degrees fahrenheit is %.2f in celsius", (76-32)/1.8);
	return 0;
}