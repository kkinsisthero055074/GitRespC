#include "game.h"

//初始化棋盘的函数实现
void Initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}


//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int rows, int cols)
{
	printf("********扫雷游戏********\n");
// 	//1.1 赋值列号
// 	for (int j = 0; j < rows - 1; j++)
// 	{
// 		board[0][j] = '0'+j;
// 	}
// 	//1.2 赋值行号
// 	for (int i = 1;i < cols-1; i++)
// 	{
// 		board[i][0] = '0' + i;
// 	}

	for (int i = 0; i < rows-1; i++)
	{
		for (int j = 0; j < cols-1; j++)
		{
			if (i == 0)
			{
				printf(" %d ", j);
			}
			else
			{
				if (j == 0)
				{
					printf(" %d ", i);
				}
				else
				{
					printf(" %c ", board[i][j]);
				}			
				
			}
			
		}
		printf("\n");
	}

	printf("********扫雷游戏********\n");

}

//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//布置10个雷
	int count = EASY_COUNT;
	while (count)
	{
		//随机生成下标
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}


//统计坐标周围雷的个数  
//这个函数只是在在函数内部调用，不用到头文件上声明，但是要放在调用函数的上面
//static修饰函数的时候，只能让函数在自己所在的源文件中看到，其他原文件是看不到的
static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}


//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	
	//2. 检查坐标处是不是雷
	 //2.1 是雷  -很遗憾炸死了
	 //2.1 不是雷  -统计坐标周围有几个雷  -存储排查雷的信息到show数组，游戏继续

	//1. 输入排查的坐标
	int x = 0;
	int y = 0;
	int win = 0;
	

	while (win < row*col - EASY_COUNT)
	{
		printf("请输入要排查的坐标：\n");
		scanf_s("%d %d", &x, &y);

		//1.1 判断输入的坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y]=='1')
			{
				printf("很遗憾，你被炸死了！");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//不是雷的情况，统计x,y坐标周围有几个雷
				int count=get_mine_count(mine,x,y);
				show[x][y] = count + '0';
				//显示排查出的信息
				DisplayBoard(show, row, col);

				if (count == 0)
				{
					printf("返回值为0！\n");
					//1.1如果返回的是0，那么显示周边所有的信息
					//1.1.1 下面一行	
					if (x - 1 > 0)
					{
						if (y - 1 > 0)
						{
							count = get_mine_count(mine, x - 1, y - 1);
							show[x - 1][y - 1] = count + '0';
						}

						count = get_mine_count(mine, x - 1, y);
						show[x - 1][y] = count + '0';

						if (y + 1 <= col)
						{
							count = get_mine_count(mine, x - 1, y + 1);
							show[x - 1][y + 1] = count + '0';
						}
					}

					//1.1.2 中间一行
					if (y - 1 > 0)
					{
						count = get_mine_count(mine, x, y - 1);
						show[x][y - 1] = count + '0';
					}
					if (y + 1 <= col)
					{
						count = get_mine_count(mine, x, y + 1);
						show[x][y + 1] = count + '0';
					}

					//1.1.3 下面一行
					if (x + 1 <= row)
					{
						if (y - 1 > 0)
						{
							count = get_mine_count(mine, x + 1, y - 1);
							show[x + 1][y - 1] = count + '0';
						}

						count = get_mine_count(mine, x + 1, y);
						show[x + 1][y] = count + '0';

						if (y + 1 <= col)
						{
							count = get_mine_count(mine, x + 1, y + 1);
							show[x + 1][y + 1] = count + '0';
						}
					}
				}
				DisplayBoard(show, ROWS, COLS);



				win++;
			}
		}
		else
		{
			printf("坐标不合法！请重新输入\n");
		}

	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功！\n");
		DisplayBoard(mine, row, col);

	}

}




