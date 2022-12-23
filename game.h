#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
enum {
	EXIT,
	PLAY
};

//��������
void JudgeFormat(int* p);
//��ʼ������
void InitBoard(char board[][COL], int row, int col);
//��ӡ����
void PrintBoard(char board[][COL], int row, int col);
//�˻�����
void PlayerMove(char board[][COL], int row, int col);
void ComputerMove(char board[][COL], int row, int col);
//�ж���Ӯ
char IsWin(char board[][COL], int row, int col);
