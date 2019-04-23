//***************************************************
// Filename: main.c
//
// Author: Blake Lapum
//***************************************************

#include "WhoDidIt.h"

// main driver of the game
int main(int argc, char *argv[])
{
	system("cls");

	char board[SIZE][SIZE];
	initializeBoard(board);

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

	int playing = setStory(name); //setting which story we want
	if(playing == 0) {
		gameOver(); 
	}

	int number = mutateGel(board); 
	if (number > SIZE-1)
	{
		printf("\nYou ran the process too long. The simples slid off the end of the gel! \n \n");
		gameOver();
	}
	else if(number < 6) {
		printf("\nYou did not let the gel run long enough and had too many contradicting results.\n \n"); 
		gameOver(); 
	}
	else
	{
		if (matches(board) == 1)
		{
			int col;
			scanf("%d", &col);
			if (guess(board, col))
			{
				printf("\nCongratulations! You Won! What a fantastic forensic analyst you are! \n\n");
				gameOver();
			}
			else
			{
				gameOver();
			}
		}
		else if (matches(board) == 0)
		{
			printf("\nYou did not have any matches. We must not have a lead on the right suspect...\n");
			printf("You did a good job, but we need to try again with new samples.\n \n");
			gameOver();
		}
		else
		{
			printf("\nYou had too many matches! You either prepared the samples wrong or you did not run the samples long enough. \n\n");
			gameOver();
		}
	}

	return EXIT_SUCCESS;
}