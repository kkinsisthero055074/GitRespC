#pragma once
#include <stdio.h>
//�����������ʱ����仯
#include <stdlib.h>
#include <time.h>


//���Ŷ���
#define ROW 3
#define COL 3

//����������
//��ʼ������
void InitBoard(char arr[ROW][COL], int row, int col);  //�������п���ʡ�ԣ������в���ʡ��

//��ӡ����
void DisplayBoard(char arr[ROW][COL], int row,int col);

//�������
void PlayerMover(char board[ROW][COL],int row,int col);

//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж��Ƿ�Ӯ����Ϸ 1���Ӯ* 2����Ӯ# 3ƽ��Q 4��Ϸ����C
char IsWin(char board[ROW][COL],int row,int col);