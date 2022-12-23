#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu() {
	printf("*******************************\n");
	printf("********1. play    ************\n");
	printf("********0. exit    ************\n");
	printf("*******************************\n");
}

void game() {
	char board[ROW][COL];
	char ret = 0;
	//初始化数组
	InitBoard(board, ROW, COL);
	//打印棋盘
	PrintBoard(board, ROW, COL);
	while (1) {
		PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf(">玩家赢\n");
	else if (ret == "@")
		printf(">电脑赢\n");
	else
		printf(">平局\n");
	PrintBoard(board, ROW, COL);

}
int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf(">请输入选项:");
		JudgeFormat(&input);
		switch (input) {
		case EXIT://记得加入延时效果
			printf(">退出游戏\n");
			break;
		case PLAY:
			printf(">开始游戏\n");
			game();
			break;
		default:
			printf(">输入错误，必须输入0 or 1\n");
		}
	} while (input);

	return 0;
}