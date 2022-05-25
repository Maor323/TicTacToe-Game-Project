#ifndef _tictactoe_
#define _tictactoe_
#define _CRT_SECURE_NO_WARNINGS

/***** INCLUDES *****/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/***** DEFINES *****/
#define ROWS 3
#define COLS 3
#define SPACE ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

/***** TYPEDEFS *****/

/***** FUNCTIONS *****/
char** getEmptyBoard();
void printBoard(char** board);
void freeBoard(char** board);
void checkAllocationSuccess(void* ptr);
void fillBoard(char** board);
void startBoard(char** board);
//void clearAndPrint(char** board);
void checkEmptyBoard(char** board);
void playersMoves(char** board);
int checkEmptyCell(int num, char** board);
void putPlayerMoveInBoard(char ch, int value, char** board);
bool movesplayer1(char** board);
bool movesplayer2(char** board);
void clearAndPrint(char** board);
void clearScreen();
bool checkVictory(char ch, char** board);
int allBoardFull(char** board);

void playAgain();
void invalidMove(char** board, int* num, int* correctInput);


#endif // !_tictactoe_
