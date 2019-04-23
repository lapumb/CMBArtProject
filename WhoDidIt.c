//***************************************************
// Filename: WhoDidIt.c
//
// Author: Blake Lapum
//***************************************************

#include "WhoDidIt.h"

// Displays the gel electrophoresis
void displayBoard(char board[][SIZE])
{
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf((i == 0 ? "%5d" : "%3d"), i + 1);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%2d", i * 10);
        for (int j = 0; j < SIZE; j++)
        {
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
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = EMPTY;
        }
    }
}

int setStory(char *analyst)
{
    printf("\nForensic analyst %s, thank goodness you are in today! There has been a terrible crime and we need your help!\n", analyst);
    printf("There was a break in at the CMB lab and there are large batches of E-Coli missing. In the wrong hands, there could \n");
    printf("be grave consequences! Luckily, we found traces of blood from the shattered window and we believe it to be the perps. \n \n");
    printf("Can you run gel electrophesis analysis of the fingerprint against several suspects we have and let us know the results? \n");
    printf("Enter Y or N: ");
    //checking if player is willing to play
    char answer;
    int yes = 0;
    while (yes != 1)
    {
        scanf("%c", &answer);
        answer = toupper(answer); //making answer uppercase for comparison reasons
        if (answer == 'N')
        {
            printf("\nYou have chose not to do your job, and in turn there have been multiple E-Coli outbreaks linked to the same \n");
            printf("crime. You have lost your job and now reside on the streets of Allendale. \n\n");
            //yes = 2;
            return 0;
        }
        else if (answer != 'N' && answer != 'Y')
        {
            printf("I did not understand your answer. Please say Y or N: ");
            yes = 0;
        }
        else
        {
            //break out the loop, they answered yes
            yes = 1;
        }
    }

    printf("\nGreat! Run the gel electrophoresis and let us know any results! \n");

    prepareGel();

    return 1; 
}

void gameOver()
{
    char answer;
    printf("To exit, press 'q'. To play again, press any other key: ");
    getchar(); 
    scanf("%c", &answer);
    answer = toupper(answer);

    if (answer != 'Q')
    {
        main();
    }
    else {
        exit(0);
    }
}

int mutateGel(char board[][SIZE])
{
    printf("\n------------------------------------------------------------------------------------------------------------------\n");
    printf("\nEach time you press enter, the process will simulate 5 minutes. To stop the process, enter the 's' key.");
    printf("\nFor the best results, wait 30-35 minutes. If you go over 35 minutes, the samples will run off the gel and you lose.\n\n");

    for (int start = 0; start < SIZE; start++)
    { //starting display
        board[0][start] = FRAGMENT;
    }

    char key;
    int play = 0, count = 0;
    int index = 0;
    int random = rand() % 3; 
    int ranCol = rand() % 8;
    while (play != 1 && count < SIZE)
    {
        count++;
        index++;
        displayBoard(board);
        printf("\nTime Elapsed: %d minutes\n", (count*5)); 
        printf("To stop the process, enter the 's' key. To continue, press ENTER.\n"); 
        scanf("%c", &key);
        key = toupper(key);
        if (key == 'S')
        {
            play = 1;
        }
        else
        {
            for (int m = 0; m < SIZE; m++)
            {                         //cols
                int ran = rand() % 2; //0-1
                board[index + ran][m] = FRAGMENT;

                if (ran == 0 && index > 1)
                {
                    board[index + ran][m - 1] = EMPTY;
                }
 
                if(random == 0) {
                    for(int i = 0; i < SIZE; i++) {
                        board[i][ranCol] = board[i][0]; 
                    }
                }
            }
        }
    }

    return count;
}


int matches(char board[][SIZE])
{
    int count = 0, rowCount = 0; //num matches

    for (int i = 1; i < SIZE; i++)     //col
    {                                  //checking each column against first (row x col)
        for (int j = 0; j < SIZE; j++) //row
        {
            if (board[j][0] == board[j][i])
            {
                rowCount++;
            }
            else
            {
                continue;
            }
        }
        if (rowCount == SIZE)
        {
            count++;
        }
        rowCount = 0; 
    }
    return count;
}

void prepareGel()
{
    //will reach here only if 'Y' is selected
    printf("\nWe have already amplified the DNA samples, so lets start by adding the restriction enzymes. \n");
    printf("We will be using Bam HI, Hin dIII, and Eco RI. \n");
    printf("Press ENTER to add the enzymes to each respected samples. %c", getchar());
    getchar();

    printf("\nNow that we have prepared the samples, lets prepare the gel.\n");
    printf("Press ENTER to prepare the gel.");
    getchar();

    printf("\nNow that we have the gel and the samples prepared, lets fill the wells in the gel with each respected sample. \n");
    printf("Well #0 is the recovered DNA, and each proceeding well is a suspect. \n");
    printf("Press ENTER to run the gel electrophoresis on the samples.");
    getchar();
}

bool guess(char board[][SIZE], int col)
{
    int count = 0;
    col -= 1; 
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == board[i][col])
        {
            count++;
        }
    }

    if (count == SIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}