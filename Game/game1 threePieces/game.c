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


//玩家下棋的函数实现
void PlayerMover(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("玩家走>\n");

		printf("请输入下棋的坐标：>");
		scanf_s("%d %d", &x, &y);

		//判断输入值的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//玩家下棋
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';				
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入\n");
		}

	}

}


//电脑下棋的函数实现
void ComputerMove(char board[ROW][COL], int row, int col)
{

	printf("电脑走>\n");
	while (1)
	{		
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//判断是否赢了游戏 1玩家赢* 2电脑赢# 3平局Q 4游戏继续C
char IsWin(char board[ROW][COL], int row, int col)
{
	//1 行是否成直线
	for (int i = 0; i < row; i++)
	{
		int numPlayer = 0;
		int numComputer = 0;
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == '*')
			{
				numPlayer++;
			}
			if (board[i][j] == '#')
			{
				numComputer++;
			}
		}
		if (numPlayer == col)
		{
			return '*';
		}
		if (numComputer == col)
		{
			return '#';
		}
	}






	//2 列是否为直线
	for (int j = 0; j < col; j++)
	{
		int numPlayer = 0;
		int numComputer = 0;
		for (int i = 0; i < row; i++)
		{
			if (board[i][j] == '*')
			{
				numPlayer++;
			}
			if (board[i][j] == '#')
			{
				numComputer++;
			}
		}
		if (numPlayer == row)
		{
			return '*';
		}
		if (numComputer == row)
		{
			return '#';
		}
	}



	//3 对角是否为直线
	//3.1 从上到下对角线
	int numPlayer = 0;
	int numComputer = 0;
	for (int i = 0; i < row; i++)
	{
		if (board[i][i] == '*')
		{
			numPlayer++;
		}
		if (board[i][i] == '#')
		{
			numComputer++;
		}
	}
	if (numPlayer == row)
	{
		return '*';
	}
	if (numComputer == row)
	{
		return '#';
	}





	//3.2 从下到上对角线
	numPlayer = 0;
	numComputer = 0;
	for (int i = 0; i < row; i++)
	{
		if (board[row-1-i][i] == '*')
		{
			numPlayer++;
		}
		if (board[row-1-i][i] == '#')
		{
			numComputer++;
		}
	}
	if (numPlayer == row)
	{
		return '*';
	}
	if (numComputer == row)
	{
		return '#';
	}

	//4 游戏还没有结束
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 'C';
		}
	}

	return 'Q';


}