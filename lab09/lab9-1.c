// Lab 09 DS4Talker Skeleton Code       

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses/ncurses.h>
#define WORDLENGTH 11
#define MAXWORDS 100
#define DEBUGM 1   // Set this to 0 to disable debug output

//Compile with gcc -o lab9 lab9.c -lncurses
//Run with ./ds4rd-real.exe -d 054c:05c4 -D DS4_USB -b -j | ./lab9 wordslist-1.txt

// Reads words from the file into WL and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int read_words(char* WL[MAXWORDS], char* file_name);

// modifies str to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* str);


//STRUCTURES
typedef struct cursorCoords_struct{
	int x;
	int y;
	int index;
}curCoords;

//PROTOTYPES
void inputBuffer(int* triangle, int* circle, int* x_button, int* square, int* left_x, int* left_y, int* right_x, int* right_y);
void updateCursor(int x_shift, int y_shift, curCoords* cur);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordcount;
	int i;
	int triangle, circle, x_button, square, left_x, left_y, right_x, right_y;
	char sentence[80] = "";
	char newWord[10];
	int capitalize = 0;
	int useSpace = 1;
	int wordLengths[50];
	int wordLenIndex = 0;
	wordcount = read_words(wordlist, argv[1]);
	if (DEBUGM) {
		printf("Read %d words from %s \n", wordcount, argv[1]);
		for (i = 0; i < wordcount; i++) {
			printf("%s,", wordlist[i]);
		}
		printf("\n");
	}
	initscr();
	refresh();
	int y = 2;
	int x = 7;
	mvprintw(y, x, "%-15s", wordlist[0]);
	x += 18;
	for(i = 1; i < wordcount; i++){
		mvprintw(y, x, "%-15s", wordlist[i]);
		x += 15;
		if(x >= 75){
			y += 2;
			x = 10;
		}
		refresh();
	}
	curCoords cursor;
	cursor.x = 9;
	cursor.y = 2;
	cursor.index = 0;
	while(1){
		scanf ("%d, %d, %d, %d, %d, %d, %d, %d", &triangle, &circle, &x_button, &square, &left_x, &left_y, &right_x, &right_y);
		mvprintw(cursor.y, cursor.x, ">");
		refresh();
		if (left_x > 25){
			updateCursor(15, 0, &cursor);
			inputBuffer(&triangle, &circle, &x_button, &square, &left_x, &left_y, &right_x, &right_y);
		}else if (left_x < -25){
			updateCursor(-15, 0, &cursor);
			inputBuffer(&triangle, &circle, &x_button, &square, &left_x, &left_y, &right_x, &right_y);
		}
		if (left_y > 25){
			updateCursor(0, 2, &cursor);
			inputBuffer(&triangle, &circle, &x_button, &square, &left_x, &left_y, &right_x, &right_y);
		} else if (left_y < -25){
			updateCursor(0, -2, &cursor);
			inputBuffer(&triangle, &circle, &x_button, &square, &left_x, &left_y, &right_x, &right_y);
		}
		if (circle == 1){
			capitalize = 1;
		}
		if (square == 1){
			useSpace = 0;
		}
		if (triangle == 1){
			int curWordLen = 0;
			if (useSpace == 1){
				strcat(sentence, " ");
				curWordLen += 1;			
			}
			strcpy(newWord, wordlist[cursor.index]);
			if (capitalize == 1){
				newWord[0] = toupper(newWord[0]);
			}
			strcat(sentence, newWord);
			curWordLen += strlen(newWord);		
			mvprintw(50, 35, "%s", sentence);
			refresh();
			wordLengths[wordLenIndex] = curWordLen;				
			wordLenIndex++;
			capitalize = 0;
			useSpace = 1;
			inputBuffer(&triangle, &circle, &x_button, &square, &left_x, &left_y, &right_x, &right_y);
		}
		if (x_button == 1){																								
			wordLenIndex--;
			int length = strlen(sentence);
			for (int i = 1; i < wordLengths[wordLenIndex] + 1; i++){
				sentence[length-i] = ' ' ;
			}
			wordLengths[wordLenIndex] = 0;
			mvprintw(50, 35, "%s", sentence);
			trimws(sentence);
			mvprintw(50, 35, "%s", sentence);
			refresh();
			inputBuffer(&triangle, &circle, &x_button, &square, &left_x, &left_y, &right_x, &right_y);
		}
	}
	return 0;
}

// DO NOT MODIFY THIS FUNCTION!
void trimws(char* str) {
	int length = strlen(str);
	int x;
	if (length == 0) return;
	x = length - 1;
	while (isspace(str[x]) && (x >= 0)) {
		str[x] = '\0';
		x -= 1;
	}
}


// DO NOT MODIFY THIS FUNCTION!
int read_words(char* WL[MAXWORDS], char* file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen(file_name, "r");
	while (!feof(fp)) {
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			trimws(line);
			WL[numread] = (char *)malloc(strlen(line) + 1);
			strcpy(WL[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}

//updates cursor
void updateCursor(int x_shift, int y_shift, curCoords* cur){
	if (cur->x != 9 && x_shift < 0){	//shift left	
		mvprintw(cur->y, cur->x, " ");
		refresh();
		cur->x += x_shift;
		cur->index -= 1;
		mvprintw(cur->y, cur->x, ">");
		refresh();
	}
	if (cur->x != 69 && x_shift > 0){	//shift right
		mvprintw(cur->y, cur->x, " ");
		refresh();
		cur->x += x_shift;
		cur->index += 1;
		mvprintw(cur->y, cur->x, ">");
		refresh();
	}
	if (cur->y != 2 && y_shift < 0){	//shift up
		mvprintw(cur->y, cur->x, " ");
		refresh();
		cur->y += y_shift;
		cur->index -= 5;
		mvprintw(cur->y, cur->x, ">");
		refresh();
	}
	if (cur->y != 32 && y_shift > 0){	//shift down
		mvprintw(cur->y, cur->x, " ");
		refresh();
		cur->y += y_shift;
		cur->index += 5;
		mvprintw(cur->y, cur->x, ">");
		refresh();
	}
}

//Makes sure no buttons are pressed before continuing the code
void inputBuffer(int* triangle, int* circle, int* x_button, int* square, int* left_x, int* left_y, int* right_x, int* right_y){
	while (*triangle != 0 || *circle != 0 || *x_button != 0 || *square != 0 || (*left_x > 25 || *left_x < -25)|| (*left_y > 25 || *left_y < -25)){
		scanf ("%d, %d, %d, %d, %d, %d, %d, %d", triangle, circle, x_button, square, left_x, left_y, right_x, right_y);
	}
}
