#define _CRT_SECURE_NO_WARNINGS

#include"game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;

	for (i = 0; i < rows; i++) {

		for (j = 0; j < cols; j++) {

			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("-----MINESWEEPER-----\n");
	printf("---------------------\n");

	int i, j;

	for (i = 0; i <=col; i++) {
		printf("%d ", i);
	}
	printf("y\n");

	for (i = 1; i <=row; i++) {
		printf("%d ", i);
		for (j = 1; j <=col; j++) {

			printf("%c ", board[i][j]);
		}
		printf("|\n");
	}
	printf("x--------------------\n");
	printf("-----MINESWEEPER-----\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;

	while (count) {

		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == '0') {

			board[x][y] = '1';
			count--;
		}
		
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0');
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;
	
	while (win < row * col - EASY_COUNT) {

		printf("Input the coord which you want to check>");
		scanf("%d %d", &x, &y);

		if ((x >= 1 && x <= row) && (y >= 1 && y <= col)) {

			if (mine[x][y] == '1') {

				printf("Sorry,you try to dance on the mine!\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}

			else {

				//统计周边雷的个数
				int count = GetMineCount(mine, ROW, COL);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				
				win++;
			}
		}
		else {
			printf("Invalid Data,please try again!\n");
		}
	}
	if (win == row * col - EASY_COUNT) {
		printf("You win!\n");
		DisplayBoard(mine, ROW, COL);
	}
}