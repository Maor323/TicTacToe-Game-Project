/*in this game you play Tic-tac-toe */
#include "tictactoe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void main()
{
	char ch;
	char** boardGame = getEmptyBoard();
	startBoard(boardGame);
	printBoard(boardGame);
	playersMoves(boardGame);
	freeBoard(boardGame);
	printf("FOR ANOTHER PLAY PRESS 'Y', ELSE PRESS ANY BUTTOM: ");
	fseek(stdin, 0, SEEK_SET);// empty buffer
	ch = getchar();
	while (ch == 'y' || ch == 'Y')
	{
		playAgain();
	}
	printf("GAME OVER, THANK YOU FOR PLAYING!\n");
}