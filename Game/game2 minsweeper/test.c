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
	char mine[ROWS][COLS] = {0};//存放布置好的雷的信息
	char show[ROWS][COLS] = {0};//存放排查出的雷的信息

	//初始化棋盘
	Initboard(mine,ROWS,COLS,'0');
	Initboard(show, ROWS, COLS,'*');

	//显示棋盘	
	DisplayBoard(show, ROWS, COLS);

	//布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROWS, COLS);

	//排查雷
	FindMine(mine,show,ROW,COL);




}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("请选择>");
		scanf_s("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("选择错误！请重新输入\n");
			break;
		}

	} while (input);
	return 0;
}