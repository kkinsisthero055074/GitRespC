#include "game.h"
//��Ҫ����ͷ�ļ�������ʹ��ͷ�ļ��ж���ĳ���

//����ʵ�֣���ʼ������
void InitBoard(char arr[ROW][COL], int row, int col)//��ά�����β��б�������������
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			arr[i][j] = ' ';
	}
}


//����ʵ�֣� ��ӡ����
void DisplayBoard(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);	
			if(j<col-1)
			printf("|");
		}
		printf("\n");
		for (int j = 0; j < col; j++)
		{
			if(i<row-1)
			printf("---");
			if (j < col - 1&& i<row -1)
			printf("|");
		}
		printf("\n");



// 		printf(" %c | %c | %c \n",arr[i][0],arr[i][1],arr[i][2]);
// 		if(i<row-1)
// 		printf("---|---|---\n");
		
	}
	
}