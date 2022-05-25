#include "tictactoe.h"

//***BOARD
char** getEmptyBoard()
{
	char** new_board = (char**)malloc(sizeof(char*) * ROWS);
	checkAllocationSuccess(new_board);
	int i;
	for (i = 0; i < ROWS; i++) {
		new_board[i] = (char*)malloc(sizeof(char) * (COLS + 1));
		checkAllocationSuccess(new_board[i]);
		new_board[i][COLS] = '\0';
	}
	fillBoard(new_board);
	return new_board;
}
void printBoard(char** board)
{
	int i;
	checkEmptyBoard(board);
	printf("\nPlayer 1 is <X>\n");
	printf("Player 2 is <O>\n");
	for (i = 0; i < ROWS; i++)
	{
		printf("+---+---+---+\n");
		printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
	}
	printf("+---+---+---+\n");
	return;
}
void startBoard(char** board)
{
	int i,j=9;
	checkEmptyBoard(board);
	printf("WELCOME TO THE TICTACTOE GAME!\n");
	printf("follow the moves by the numbers down:\n");
	for (i = 0; i < ROWS; i++)
	{
		printf("+---+---+---+\n");
		printf("| %d | %d | %d |\n", j-2, j-1, j);
		j = j - 3;
	}
	printf("+---+---+---+\n");
	return;
}
void freeBoard(char** board)
{
	int i;
	if (!board)
		return;
	for (i = 0; i < ROWS; i++)
		free(board[i]);
	free(board);
}
void fillBoard(char** board)
{
	int i, j;
	if (!board) {
		printf("Empty Board.");
		return;
	}
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = SPACE;
		}
	}
	return;
}
int checkEmptyCell(int num,char** board)
{
	if (num >= 1 && num <= 3)
	{
		if (board[2][num - 1] != ' ')
			return 0;
	}
	else if (num >= 4 && num <= 6)
	{
		if (board[1][num - 4] != ' ')
			return 0;
	}
	else if (num >= 7 && num <= 9)
	{
		if (board[0][num - 7] != ' ')
			return 0;
	}
	else if (num >= 0 || num <= 9)
		return 0;
	return 1;
}
void putPlayerMoveInBoard(char ch,int value, char** board)
{
	int i, j=1;
	if(value>=1&&value<=3)
		for (i = 0; COLS; i++)
		{
			if (j == value)
			{
				if (ch == PLAYER1)
				{
					board[2][j - 1] = PLAYER1;
					return;
				}
				else
				{
					board[2][j - 1] = PLAYER2;
					return;
				}	
			}	
			j++;
		}
	else if (value >= 4 && value <= 6)
	{
		j = 4;
		for (i = 0; i < ROWS; i++)
		{
			if (j == value)
			{
				if (ch == PLAYER1)
				{
					board[1][j - 4] = PLAYER1;
					return;
				}
				else
				{
					board[1][j - 4] = PLAYER2;
					return;
				}	
			}
			j++;
		}
	}
	else if(value >= 7 && value <= 9)
	{
		j = 7;
		for (i = 0; i < ROWS; i++)
		{
			if (j == value)
			{
				if (ch == PLAYER1)
				{
					board[0][j - 7] = PLAYER1;
					return;
				}
				else
				{
					board[0][j - 7] = PLAYER2;
					return;
				}	
			}
			j++;
		}
	}
}

//**PLAYERS

void playersMoves(char** board)
{
	bool flag = false;
	while (flag == false)
	{
		flag = movesplayer1(board);
		if (allBoardFull(board) == 9)
		{
			printf("IT'S A TIE!\n");
			return;
		}
		if (flag == true)
			return;
		flag = movesplayer2(board);
		if (flag == true)
			return;
	}
}
bool movesplayer1(char** board)
{
	int num, correctInput;
	bool victory;
	printf("\nPlayer number 1:\nPlease enter a number between 1-9: ");
	scanf("%d", &num);
	correctInput = checkEmptyCell(num, board);
	if (correctInput == 0)
	{
		while (correctInput ==0)
		{
			invalidMove(board, &num,&correctInput);
		}
	}
	putPlayerMoveInBoard(PLAYER1, num, board);
	victory=checkVictory(PLAYER1, board);
	clearAndPrint(board);
	if (victory == true)
	{
		printf("\nPLAYER 1 WON!\n");
		return true;
	}
	return false;
}
bool movesplayer2(char** board)
{
	int num, correctInput;
	bool victory;
	printf("\nPlayer number 2:\nPlease enter a number between 1-9: ");
	scanf("%d", &num);
	correctInput = checkEmptyCell(num, board);
	if (correctInput == 0)
	{
		while (correctInput == 0)
		{
			clearAndPrint(board);
			printf("\nINVALID INPUT\nPlayer number 2:\nPlease enter a number between 1-9: ");
			scanf("%d", &num);
			correctInput = checkEmptyCell(num, board);
		}
	}
	putPlayerMoveInBoard(PLAYER2, num, board);
	victory = checkVictory(PLAYER2, board);
	clearAndPrint(board);
	if (victory == true)
	{
		printf("\nPLAYER 2 WON!\n");
		return true;
	}
	return false;
}
bool checkVictory(char ch, char** board)
{
	int i=1, j = 1;
	bool victory = false;
	
	if ((board[i][j] == ch && board[i-1][j - 1] == ch && board[i+1][j+1] == ch)
		||(board[i][j] == ch && board[i + 1][j-1] == ch && board[i - 1][j+1] == ch)
		||(board[i][j] == ch && board[i - 1][j] == ch && board[i + 1][j] == ch)
		|| (board[i][j] == ch && board[i][j-1] == ch && board[i][j+1] == ch))
		victory = true;
	else if ((board[i + 1][j - 1] == ch && board[i][j - 1] == ch && board[i - 1][j - 1] == ch)
		|| (board[i + 1][j - 1] == ch && board[i + 1][j] == ch && board[i + 1][j + 1] == ch)
		|| (board[i - 1][j + 1] == ch && board[i][j + 1] == ch && board[i + 1][j + 1] == ch)
		|| (board[i - 1][j - 1] == ch && board[i - 1][j] == ch && board[i - 1][j + 1] == ch))
		victory = true;
	return victory;
}

//**GENERAL
void checkEmptyBoard(char** board)
{
	if (!board)
	{
		printf("Empty Board\n");
		return;
	}
}
void checkAllocationSuccess(void* ptr)
{
	if (!ptr)
	{
		printf("ERROR ALLOCATION");
		exit(1);
	}
	return;
}
void clearAndPrint(char** board)
{
	clearScreen();
	startBoard(board);
	printBoard(board);
}
void clearScreen()
{
	system("cls");
}
int allBoardFull(char** board)
{
	int i, j, count=0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			if (board[i][j] != ' ')
				count++;
		}
	}
	return count;
}

void playAgain()
{
	char** boardGame;
	char ch;
	clearScreen();
	boardGame = getEmptyBoard();
	startBoard(boardGame);
	printBoard(boardGame);
	playersMoves(boardGame);
	freeBoard(boardGame);
	printf("FOR ANOTHER PLAY PRESS 'Y', ELSE PRESS ANY BUTTOM\n");
	fseek(stdin, 0, SEEK_SET);// empty buffer
	scanf("%c", &ch);
}
void invalidMove(char** board, int* num, int* correctInput)
{
	clearAndPrint(board);
	printf("\nINVALID INPUT\nPlayer number 1:\nPlease enter a number between 1-9: ");
	scanf("%d", &(*num));
	*correctInput = checkEmptyCell(*num, board);
}