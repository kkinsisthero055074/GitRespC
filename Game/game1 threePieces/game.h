#pragma once
#include <stdio.h>
//���Ŷ���
#define ROW 3
#define COL 3

//����������
//��ʼ������
void InitBoard(char arr[ROW][COL], int row, int col);  //�������п���ʡ�ԣ������в���ʡ��

//��ӡ����
void DisplayBoard(char arr[ROW][COL], int row,int col);