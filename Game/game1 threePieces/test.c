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
	//储存数据 二维数组
	char board[ROW][COL];

	//初始化棋盘-初始化为全部为空格
	InitBoard(board, ROW, COL); //调用的时候里面是二维数组的名字
	   
	//打印一下棋盘-本质是打印棋盘的的内容
	DisplayBoard(board, ROW, COL);
	char ret;


	while (1)
	{
		//玩家下棋	
		PlayerMover(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		
		//判断玩家是否赢得游戏
		ret=IsWin(board,ROW,COL);
		if (ret == '*')
		{
			printf("玩家赢了\n");
			break;
		}		
		if (ret == 'Q')
		{
			printf("平局\n");
			break;
		}



		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL); 
		//判断电脑是否赢得游戏
		ret = IsWin(board, ROW, COL);

		if (ret == '#')
		{
			printf("电脑赢了\n");
			break;
		}
		else if(ret=="Q")
		{			
			printf("平局\n");
			break;
			
		}
		/*DisplayBoard(board, ROW, COL);*/
	}

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL)); //随机变量随着时间而变化

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