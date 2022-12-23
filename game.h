#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
enum {
	EXIT,
	PLAY
};

//函数声明
void JudgeFormat(int* p);
//初始化数组
void InitBoard(char board[][COL], int row, int col);
//打印棋盘
void PrintBoard(char board[][COL], int row, int col);
//人机下棋
void PlayerMove(char board[][COL], int row, int col);
void ComputerMove(char board[][COL], int row, int col);
//判断输赢
char IsWin(char board[][COL], int row, int col);
