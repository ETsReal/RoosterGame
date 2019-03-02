#include <stdbool.h>
#define ROWS 3
#define COLS 3

void createBoard(char array[ROWS][COLS]);
bool uCanGO(int x, int y, char array[ROWS][COLS]);
bool winDiagonal(int x, int y, char array[ROWS][COLS]);
bool winHorizontal(int x, int y, char array[ROWS][COLS]);
bool winVertical(int x, int y, char array[ROWS][COLS]);
bool winHorizontalMiddle(int x, int y, char array[ROWS][COLS]);
bool winHorizontal2Right(int x, int y, char array[ROWS][COLS]);
bool winHorizontal2Left(int x, int y, char array[ROWS][COLS]);
bool winVerticalMiddle(int x, int y, char array[ROWS][COLS]);
bool winVertical2Up(int x, int y, char array[ROWS][COLS]);
bool winVertical2Down(int x, int y, char array[ROWS][COLS]);
void printBoard(char array[ROWS][COLS]);

