#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void JudgeFormat(int* p) {
	int ch, n;
	n = scanf("%d", p);
	while (n == 0) {
		fprintf(stderr,">��ʽ���󣬱���������\n");
		do {
			ch = getchar();
		} while ((ch != EOF) && (ch != '\n'));

		n = scanf("%d", p);
	}
	if (n != 1) {
		fprintf(stderr, ">�������\n");
		exit(EXIT_FAILURE);
	}
}
void InitBoard(char board[][COL], int row, int col) {
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			board[i][j] = ' ';
		}
	}
}
void PrintBoard(char board[][COL], int row, int col) {
	int i, j, k;
	for (i=0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1) {
			for (k = 0; k < col; k++) {
				printf("������");
				if (k < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[][COL], int row, int col) {
	int x, y;
	printf(">�����:\n");
	while (1) {
		printf(">�����������:>");
		scanf("%d %d", &x, &y);

		//�жϺϷ���
		if (x >= 0 && x <= row && y >= 0 && y <= col) {
			//�ж������Ƿ�Ϊ��
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf(">���걻ռ�ã�����������\n");
			}
		}
		else {
			printf(">�����������Ч������������\n");
		}
	}

}
void ComputerMove(char board[][COL], int row, int col) {
	//��ʾ
	//���������x,y
	//�ж�
	printf(">������:\n");
	while (1) {
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ') {
			board[x][y] = '@';
			break;
		}
	}

}
int IsFull(char board[][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char IsWin(char board[][COL], int row, int col) {
	//�ж�����
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]
			&& board[i][2] != ' ') {
			return board[i][0];
		}
	}
	//�ж�����
	for (int i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]
			&& board[2][i] != ' ') {
			return board[0][i];
		}
	}
	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
		return board[1][1];
	//�ж�ƽ��
	
	int ret = IsFull(board, row, col);
	if (ret) 
		return 'Q';
	else
		return 'C';
}