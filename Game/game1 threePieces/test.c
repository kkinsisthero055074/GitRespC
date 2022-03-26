#include <stdio.h>
#include "game.h"

void menu()
{
	printf("*********************************\n");
	printf("*********     1. play   *********\n");
	printf("*********     0. exit   *********\n");
	printf("*********************************\n");
}



void game()
{
	//�������� ��ά����
	char board[ROW][COL];

	//��ʼ������-��ʼ��Ϊȫ��Ϊ�ո�
	InitBoard(board, ROW, COL); //���õ�ʱ�������Ƕ�ά���������

	//��ӡһ������-�����Ǵ�ӡ���̵ĵ�����
	DisplayBoard(board, ROW, COL);

	//�����
	//������

}

int main()
{
	int input = 0;

	do 
	{
		menu();
		printf("please choose:\n");
		scanf_s("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit the game!\n");
			break;
		default:
			printf("error input, please input again!\n");
			break;
		}

	} while (input);



	return 0;
}