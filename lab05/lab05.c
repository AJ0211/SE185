/*----------------------------------------------------------------------------
-		         SE 185: Lab 05 - Conditionals (What's up?)	    	         -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
double magnitude(double x, double y, double z);
int closeTo(double tolerance, double point, double value);
int isTriangle(int t);
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab05.c -o lab05
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./lab05

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int triangle, circle, x_button, square;
    double ax, ay, az, gx, gy, gz;
	
    while (1)
    {

		char current[7];
		char previous[7];
        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
              &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);
		if(isTriangle(triangle) == 1){
			break;
		}

        /* printf for observing values scanned in from ds4rd.exe,
         * be sure to comment or remove in final program */
       // printf("Echoing output: %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n",
       //        ax, ay, az, gx, gy, gz, triangle, circle, x_button, square);

        /* It would be wise (mainly save time) if you copy your code to calculate
         * the magnitude from lab03-1.c. You will also need to copy your
         * prototypes and functions to the appropriate sections in this program. */

       // printf("\nThe acceleration's current magnitude is: %lf\n",  magnitude(ax, ay, az));
		if((closeTo(.1,1,gy)) == 1){
			strcpy(current,"TOP");
		}
		if((closeTo(.1,-1,gy)) == 1){
			strcpy(current,"BOTTOM");
		}
		if((closeTo(.1,1,gx)) == 1){
			strcpy(current,"LEFT");
		}
		if((closeTo(.1,-1,gx)) == 1){
			strcpy(current,"RIGHT");
		}
		if(closeTo(.1,-1,gz) == 1){
			strcpy(current,"FRONT");
		}
		if((closeTo(.1,1,gz)) == 1){
			strcpy(current,"BACK");
		}
		if(strcmp(current,previous)){
				printf("%s\n",current);
	}
	strcpy(previous,current);
	}
    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int closeTo(double tolerance, double point, double value){
	double test = value - point;
	if(test < 0){
		test *=-1;
}
	if(test <= tolerance){
		return 1;
	}
	else{
		return 0;
	}
}
double magnitude(double x, double y, double z){
   return sqrt(pow(x,2)+pow(y,2)+pow(z,2) );
}
int isTriangle(int t){
	if(t == 1){
		return 1;
	}
	else{
		return 0;
	}
}