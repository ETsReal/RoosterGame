#include <stdio.h>
#include <stdlib.h>
#include "JogoGalo.h"


void createBoard(char array[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            array[i][j] = '.';
        }
    }
}

void printBoard(char array[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}
bool winHorizontalMiddle(int x, int y, char array[ROWS][COLS])
{   
    char same = array[x][y];
    if(array[x][y - 1] == same && array[x][y + 1] == same)
    {
        return true;
    }
    return false;
}
bool winHorizontal2Right(int x, int y, char array[ROWS][COLS])
{
    char same = array[x][y];
    if(array[x][y + 1] == same && array[x][y + 2] == same)
    {
        return true;
    }
    return false;
}
bool winHorizontal2Left(int x, int y, char array[ROWS][COLS])
{
    char same = array[x][y];
    if(array[x][y - 1] == same && array[x][y - 2] == same)
    {
        return true;
    }
    return false;
}

bool winHorizontal(int x, int y, char array[ROWS][COLS])
{
    if(winHorizontalMiddle(x, y, array) == true || winHorizontal2Left(x, y, array) == true || winHorizontal2Right(x, y, array) == true)
    {
        return true;
    }
    return false;
}

bool winVerticalMiddle(int x, int y, char array[ROWS][COLS])
{
    char same = array[x][y];
    if(array[x - 1][y] == same && array[x + 1][y] == same)
    {
        return true;
    }
    return false;
}
bool winVertical2Up(int x, int y, char array[ROWS][COLS])
{
    char same = array[x][y];
    if(array[x - 1][y] == same && array[x - 2][y] == same)
    {
        return true;
    }
    return false;
}
bool winVertical2Down(int x, int y, char array[ROWS][COLS])
{
    char same = array[x][y];
    if(array[x + 1][y] == same && array[x + 2][y] == same)
    {
        return true;
    }
    return false;
}


bool winVertical(int x, int y, char array[ROWS][COLS])
{
    if(winVerticalMiddle(x, y, array) == true || winVertical2Up(x, y, array) == true || winVertical2Down(x, y, array) == true)
    {
        return true;
    }
    return false;
}


bool uCanGO(int x, int y, char array[ROWS][COLS])
{
    if(array[x][y] == '.')
    {
        return true;
    }
    return false;
}

void play(char array[ROWS][COLS])
{
    int option;
    int draw = -1;
    bool xPlay = true;
    printf("Welcome Players! Lets gonna play!\n");
    printf("1 - Play\n");
    printf("2 - Exit\n");
    scanf("%d", &option);

    while(option != 2)
    {   
        draw++;
        if(draw == 9)
        {   
            printf("Empatado!\n");
            exit(0);
        }
        printf("\n");
        printf("\n");
        printBoard(array);
        printf("\n");
        printf("\n");
        if(xPlay == true)   
        {   
            int x;
            int y;
            printf("X where do you wanna mark your play?\n");
            printf("X: ");
            scanf("%d", &x);
            printf("Y: ");
            scanf("%d", &y);
            if(uCanGO(x, y, array) == true)
            {   
                array[x][y] = 'X';
                if(winVertical(x, y, array) == true || winHorizontal(x, y, array))
                {
                    printf("CONGRATULATIONS X U WON THE GAME!!!\n");
                    exit(0);
                }
                
            }
            else
            {
                printf("U CANT MARK!!\n");
            }
            xPlay = false;
        }
        else
        {
            int x;
            int y;
            printf("Y where do you wanna mark your play?\n");
            printf("X: ");
            scanf("%d", &x);
            printf("Y: ");
            scanf("%d", &y);
            if(uCanGO(x, y, array) == true)
            {   
                array[x][y] = 'Y';
                if(winVertical(x, y, array) == true || winHorizontal(x, y, array)) 
                {
                    printf("CONGRATULATIONS Y U WON THE GAME!!!\n");
                    exit(0);
                }
            }
            else
            {
                printf("U CANT MARK!!\n");
            }
            xPlay = true;
        }
    }
}


int main(void)
{
    char array[ROWS][COLS];
    createBoard(array);
    play(array);
}


