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

// Displays the board (as SIZE x SIZE grid) on console
void displayBoard(char board[][SIZE]);

// Initializes the board with start configuration of discs (see project specs)
void initializeBoard(char board[][SIZE]);

#endif /* WHODIDIT_H_ */
