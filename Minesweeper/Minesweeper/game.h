#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define EASY_COUNT 10
#define MID_COUNT 40
#define HARD_CONUT 99

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//��������
void SetMine(char board[ROWS][COLS], int row, int col);

//����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//��������
int GetMineCount(char mine[ROWS][COLS], int x, int y);