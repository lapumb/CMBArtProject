//***************************************************
// Filename: WhoDidIt.c
//
// Author: Blake Lapum 
//***************************************************

#include "WhoDidIt.h"

// Displays the board (as SIZE x SIZE grid) on console
void displayBoard(char board[][SIZE])
{
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf((i == 0 ? "%5d" : "%3d"), i+1);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%2d", i*100);
        for (int j = 0; j < SIZE; j++) {
            printf("%3c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Initializes the board with start configuration of discs (see project specs)
void initializeBoard(char board[][SIZE])
{
    //initializing all empty discs (8x8)
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY; 
        }
    }
}

void setStory(int random, char *analyst) {
	switch(random) {
		case 0: 
            printf("\nForensic analyst %s, there has been a crime at Grand Valley State University!\n", analyst); 
			break; 
		case 1:
            printf("\nForensic analyst %s, there has been a crime at Grand Valley State University!\n", analyst); 
			break; 
		case 2:
            printf("\nForensic analyst %s, there has been a crime at Grand Valley State University!\n", analyst); 
			break;
		
		case 3:
            printf("\nForensic analyst %s, there has been a crime at Grand Valley State University!\n", analyst); 
			break; 
		
		case 4:
            printf("\nForensic analyst %s, there has been a crime at Grand Valley State University!\n", analyst); 
			break; 

		case 5: 
            printf("\nForensic analyst %s, there has been a crime at Grand Valley State University!\n", analyst); 
			break; 

		default:
            printf("The switch statement should not make it here. \n \n"); 
			break; 
	}
}