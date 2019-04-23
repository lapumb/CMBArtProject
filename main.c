//***************************************************
// Filename: main.c
//
// Author: Blake Lapum
//***************************************************

#include "WhoDidIt.h"

// function prototypes
bool isCmdLineArgsValid(int argc, char *argv[]);
bool isInteger(const char *s);

// main driver of the game
int main(int argc, char *argv[]) {

	char board[SIZE][SIZE];
	initializeBoard(board);

	char *name; //pointer to a string 

	printf("<<<<< Welcome to the game of WhoDidIt, forensic analyst %c >>>>>\n");
	printf("please enter your forensic analysis name: "); 
	scanf("%s \n", &name); 

	return EXIT_SUCCESS;
}