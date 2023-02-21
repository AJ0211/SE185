/*----------------------------------------------------------------------------
-		                    SE 185: Lab 06 - Bop-It!	    	             -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
int isTriangle(int t);
int buttonsPressed(int t, int c, int x, int s);

/*----------------------------------------------------------------------------
-	                            Notes                                        -
-----------------------------------------------------------------------------*/
// Compile with gcc lab06.c -o lab06
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./lab06

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	int count = 0;
	int print = 0;
	bool track;
	int triangle, circle, x_button, square, button, currentTime;
	int timeCheck = 2500;
	bool check = false;
	int check2 = currentTime + timeCheck;
    srand(time(NULL)); /* This will ensure a random game each time. */
	printf("This is a Bop-It Game!\n");
	printf("Please press the triangle Button to begin!\n");
	while(1){
	scanf("%d, %d, %d, %d, %d",&currentTime, &triangle, &circle, &x_button, &square);
	if(triangle){
		check = true;
		check2 = currentTime + timeCheck;
		break;
	}
	}

		while(check == true){
			if(buttonsPressed(triangle, circle, x_button, square) == 0){
				track = false;
			}
			else{
				track = true;
			}
			if(button == 1){
				if(print == 0){
				printf("\nPress the triangle button\n");
				printf("You have %d milliseconds to respond!\n", timeCheck);
				print = 1;
				}
				scanf("%d, %d, %d, %d, %d",&currentTime, &triangle, &circle, &x_button, &square);
				if(currentTime >  check2){
					printf("\nOut of time");
					break;
				}
				if(buttonsPressed(triangle, circle, x_button, square) != 0 && !track){
				if(triangle != 1){
					printf("\nWrong button");
					break;
				}
				else{
					count++;
					timeCheck -= 100;
					button = rand() % 4 + 1;
					check2 = currentTime + timeCheck;
					print = 0;
				}
				}
			}
			
			
			else if(button == 2){
				if(print == 0){
				printf("\nPress the circle button\n");
				printf("You have %d milliseconds to respond!\n", timeCheck);
				print = 1;
				}
				scanf("%d, %d, %d, %d, %d",&currentTime, &triangle, &circle, &x_button, &square);
				if(currentTime >  check2){
					printf("\nOut of time");
					break;
				}
				if(buttonsPressed(triangle, circle, x_button, square) != 0 && !track){
				if(circle != 1){
					printf("\nWrong button");
					break;
				}
				else{
					count++;
					timeCheck -= 100;
					button = rand() % 4 + 1;
					check2 = currentTime + timeCheck;
					print = 0;
					
				}
				}
			}
			else if(button == 3){
				if(print == 0){
				printf("\nPress the x button\n");
				printf("You have %d milliseconds to respond!\n", timeCheck);
				print = 1;
				}
				scanf("%d, %d, %d, %d, %d",&currentTime, &triangle, &circle, &x_button, &square);
				if(currentTime >  check2){
					printf("\nOut of time");
					break;
				}
				if(buttonsPressed(triangle, circle, x_button, square) != 0 && !track){
				if(x_button != 1){
					printf("\nWrong button");
					break;
				}
				else{
					count++;
					timeCheck -= 100;
					button = rand() % 4 + 1;
					check2 = currentTime + timeCheck;
					print = 0;
				}
				}
			}
			else{
				if(print == 0){
				printf("\nPress the square button\n");
				printf("You have %d milliseconds to respond!\n", timeCheck);
				print = 1;
				}
				scanf("%d, %d, %d, %d, %d",&currentTime, &triangle, &circle, &x_button, &square);

				if(currentTime >  check2){
					printf("\nOut of time");
					break;
				}
				if(buttonsPressed(triangle, circle, x_button, square) != 0 && !track){
				if(square != 1){
					printf("\nWrong button");
					break;
				}

				else{
					count++;
					timeCheck -= 100;
					button = rand() % 4 + 1;
					check2 = currentTime + timeCheck;
					print = 0;
				}
			}
			}
		}
		printf("\nyou made it through %d rounds", count);
    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int buttonsPressed(int t, int c, int x, int s){
	return t + c + x + s;
}