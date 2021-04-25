#include <stdio.h>
#include <stdbool.h>

// functions
void drawBoard(void);
int checkWin(void);
void updateBoardValues(void);

//global variables
int playerChoice, playerTurn = 1, winStatus = 0;
char boardValues[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main()
{

    // player one is 1, X and player 2 is 2, O.
    printf("        Tic Tac Toe\n");
    printf("    player 1(X) player 2(O)\n\n");

    while (winStatus == 0)
    {
        drawBoard();

        updateBoardValues();

        winStatus = checkWin();

        if (playerTurn == 1)
        {
            playerTurn = 2;
        }
        else
        {
            playerTurn = 1;
        }
    }
}

void drawBoard()
{

    printf("\t    |   |   \n"
           "\t  %c | %c | %c \n"
           "\t ___|___|___\n"
           "\t    |   |   \n"
           "\t  %c | %c | %c \n"
           "\t ___|___|___\n"
           "\t    |   |   \n"
           "\t  %c | %c | %c \n"
           "\t    |   |   \n\n",
           boardValues[0], boardValues[1],
           boardValues[2], boardValues[3], boardValues[4],
           boardValues[5], boardValues[6], boardValues[7], boardValues[8]);
}

int checkWin()
{

    // horizontal cases
    if (boardValues[0] == boardValues[1] && boardValues[1] == boardValues[2])
    {
        printf("Player %d wins!", playerTurn);
        return 1;
    }
    else if (boardValues[3] == boardValues[4] && boardValues[4] == boardValues[5])
    {
        printf("Player %d wins!", playerTurn);
        return 1;
    }
    else if (boardValues[6] == boardValues[7] && boardValues[7] == boardValues[8])
    {
        printf("Player %d wins!", playerTurn);
        return 1;
    }

    // vertical cases
    if (boardValues[0] == boardValues[3] && boardValues[3] == boardValues[6])
    {
        printf("Player %d wins!", playerTurn);
        return 1;
    }
    else if (boardValues[1] == boardValues[4] && boardValues[4] == boardValues[7])
    {
        printf("Player %d wins!", playerTurn);
        return 1;
    }
    else if (boardValues[2] == boardValues[5] && boardValues[5] == boardValues[8])
    {
        printf("Player %d wins!", playerTurn);
        return 1;
    }

    // diagonal cases
    if (boardValues[0] == boardValues[4] && boardValues[4] == boardValues[8])
    {
        printf("Player %d wins!", playerTurn);
        return 1;
    }
    else if (boardValues[6] == boardValues[4] && boardValues[4] == boardValues[2])
    {
        printf("Player %d wins!", playerTurn);
        return 1;
    }

    // check draw

    return 0;
}

void updateBoardValues()
{
    if (playerTurn == 1)
    {
        printf("Player One choose a number: ");
        scanf("%d", &playerChoice);

        if (boardValues[playerChoice - 1] == 'X' || boardValues[playerChoice - 1] == 'O')
        {
            printf("Illegal move!\n");
        }
        else
        {
            boardValues[playerChoice - 1] = 'X';
        }
    }
    else if (playerTurn == 2)
    {
        printf("Player Two choose a number: ");
        scanf("%d", &playerChoice);
        if (boardValues[playerChoice - 1] == 'X' || boardValues[playerChoice - 1] == 'O')
        {
            printf("Illegal move!\nYour turn is skipped, naughty boy\n");
        }
        else
        {
            boardValues[playerChoice - 1] = 'O';
        }
    }
}