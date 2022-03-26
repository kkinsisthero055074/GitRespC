#include "game.h"
//需要包含头文件，才能使用头文件中定义的常量

//函数实现：初始化棋盘
void InitBoard(char arr[ROW][COL], int row, int col)//二维数组形参中必须包括数组的列
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			arr[i][j] = ' ';
	}
}


//函数实现： 打印棋盘
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