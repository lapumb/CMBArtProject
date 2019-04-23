//***************************************************
// Filename: main.c
//
// Author: Blake Lapum
//***************************************************

#include "WhoDidIt.h"

// main driver of the game
int main(int argc, char *argv[])
{

	int ran = rand() % NUMBER_OF_STORIES; //random num between 0-5

	char board[SIZE][SIZE];
	initializeBoard(board);
	displayBoard(board);

	char name[256]; //pointer to a string

	printf("<<<<< Welcome to the game of 'Who Did It?', forensic analyst! >>>>>\n \n");
	printf("Please enter your forensic analysis name: ");
	scanf("%[^\n]%*c", name); //reads the full line / name

	//setting name to uppercase just for simplicity
	int i = 0;
	while (name[i])
	{
		name[i] = toupper(name[i]);
		i++;
	}

	setStory(ran, name); //setting which story we want

	//printf("%s", name);

	return EXIT_SUCCESS;
}