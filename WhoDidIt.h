//***************************************************
// Filename: WhoDidIt.h
//
// Author: Blake Lapum
//***************************************************

#ifndef WHODIDIT_H_

#define WHODIDIT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 8 //size of gel electrophoresis

#define EMPTY ' ' //an empty cell

#define FRAGMENT '-' //a fragment

#define NUMBER_OF_STORIES 5 //number of stories available

// Displays the board (as SIZE x SIZE grid) on console
void displayBoard(char board[][SIZE]);

// Initializes the board with start configuration of discs (see project specs)
void initializeBoard(char board[][SIZE]);

//setting the story setting for the crime
int setStory(char *analyst);

//mutating the gel electrophoresis
int mutateGel(char board[][SIZE]);

void setGel(char board[][SIZE]); 

//return matches (per column/well)
int matches(char board[][SIZE]); 

//is game over, if so, press any key except 'q' to replay
void gameOver();

//if game is won
void gameWon(); 

//if there is a match, what is the column num?
bool guess(char board[][SIZE], int col);

//prepares sample for processing
void prepareGel();  

#endif /* WHODIDIT_H_ */
