#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void menu()
{
	printf("********************************\n");
	printf("*********    1. play    ********\n");
	printf("*********    0. exit    ********\n");
	printf("********************************\n");

}

void game()
{
	char mine[ROWS][COLS] = {0};//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = {0};//����Ų�����׵���Ϣ

	//��ʼ������
	Initboard(mine,ROWS,COLS,'0');
	Initboard(show, ROWS, COLS,'*');

	//��ʾ����	
	DisplayBoard(show, ROWS, COLS);

	//������
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROWS, COLS);

	//�Ų���
	FindMine(mine,show,ROW,COL);




}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("��ѡ��>");
		scanf_s("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("ѡ���������������\n");
			break;
		}

	} while (input);
	return 0;
}