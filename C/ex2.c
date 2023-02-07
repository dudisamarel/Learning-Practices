#include <stdio.h>
#include <stdbool.h>

void printBoard(char **board, int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("|");
        for (int j = 0; j < size; j++)
        {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf(" ");
        for (int j = 0; j < size; j++)
        {
            printf("--- ");
        }
        printf("\n");
    }
    printf("\n");
}

bool checkRow(char **board, int size, char symbol)
{
    int checkRowCounter;
    for (int i = 0; i < size; i++)
    {
        checkRowCounter = 0;
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == symbol)
                checkRowCounter++;
        }
        if (checkRowCounter == size)
            return true;
    }
    return false;
}

bool checkCol(char **board, int size, char symbol)
{
    int checkColCounter;
    for (int i = 0; i < size; i++)
    {
        checkColCounter = 0;
        for (int j = 0; j < size; j++)
        {
            if (board[j][i] == symbol)
                checkColCounter++;
        }
        if (checkColCounter == size)
            return true;
    }
    return false;
}

bool checkDiagonal(char **board, int size, char symbol)
{
    int checkDiagonalCounter = 0;
    for (int i = 0; i < size; i++)
    {
        if (board[i][i] == symbol)
            checkDiagonalCounter++;
        if (checkDiagonalCounter == size)
            return true;
    }
    checkDiagonalCounter = 0;
    for (int i = 0; i < size; i++)
    {
        if (board[i][size - i - 1] == symbol)
            checkDiagonalCounter++;
        if (checkDiagonalCounter == size)
            return true;
    }
    return false;
}

bool checkWinner(char **board, int size, char symbol)
{
    return checkDiagonal(board, size, symbol) || checkCol(board, size, symbol) || checkRow(board, size, symbol);
}

int main()
{
    int n = 3;
    char **board = (char **)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        board[i] = (char *)malloc(n * sizeof(char));
        for (int j = 0; j < n; j++)
            board[i][j] = ' ';
    }

    bool isFinished = false;
    char player = 1;
    char symbol = 'X';
    while (!isFinished)
    {
        int xToSet;
        int yToSet;
        bool valid = false;
        while (!valid)
        {
            printf("player %d enter your x position: ", player);
            scanf_s("%d", &xToSet);
            printf("player %d enter your y position: ", player);
            scanf_s("%d", &yToSet);
            if (xToSet >= 0 && xToSet < n && yToSet >= 0 && yToSet < n)
            {
                if (board[yToSet][xToSet] == ' ')
                {
                    valid = true;
                    board[yToSet][xToSet] = symbol;
                }
                else
                {
                    printf("Already exists\n");
                }
            }
            else
            {
                printf("Out of range\n");
            }
        }
        printBoard(board, 3);
        isFinished = checkWinner(board, 3, symbol);
        if (isFinished)
        {
            printf("player %d Won !", player);
        }
        symbol = symbol == 'X' ? 'O' : 'X';
        player = player == 1 ? 2 : 1;
    }

    return 0;
}