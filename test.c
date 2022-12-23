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
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
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
		printf(">���Ӯ\n");
	else if (ret == "@")
		printf(">����Ӯ\n");
	else
		printf(">ƽ��\n");
	PrintBoard(board, ROW, COL);

}
int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf(">������ѡ��:");
		JudgeFormat(&input);
		switch (input) {
		case EXIT://�ǵü�����ʱЧ��
			printf(">�˳���Ϸ\n");
			break;
		case PLAY:
			printf(">��ʼ��Ϸ\n");
			game();
			break;
		default:
			printf(">������󣬱�������0 or 1\n");
		}
	} while (input);

	return 0;
}