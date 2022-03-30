#include "game.h"

//��ʼ�����̵ĺ���ʵ��
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


//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int rows, int cols)
{
	printf("********ɨ����Ϸ********\n");
// 	//1.1 ��ֵ�к�
// 	for (int j = 0; j < rows - 1; j++)
// 	{
// 		board[0][j] = '0'+j;
// 	}
// 	//1.2 ��ֵ�к�
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

	printf("********ɨ����Ϸ********\n");

}

//������
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//����10����
	int count = EASY_COUNT;
	while (count)
	{
		//��������±�
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}


//ͳ��������Χ�׵ĸ���  
//�������ֻ�����ں����ڲ����ã����õ�ͷ�ļ�������������Ҫ���ڵ��ú���������
//static���κ�����ʱ��ֻ���ú������Լ����ڵ�Դ�ļ��п���������ԭ�ļ��ǿ�������
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


//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	
	//2. ������괦�ǲ�����
	 //2.1 ����  -���ź�ը����
	 //2.1 ������  -ͳ��������Χ�м�����  -�洢�Ų��׵���Ϣ��show���飬��Ϸ����

	//1. �����Ų������
	int x = 0;
	int y = 0;
	int win = 0;
	

	while (win < row*col - EASY_COUNT)
	{
		printf("������Ҫ�Ų�����꣺\n");
		scanf_s("%d %d", &x, &y);

		//1.1 �ж�����������Ƿ�Ϸ�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y]=='1')
			{
				printf("���ź����㱻ը���ˣ�");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//�����׵������ͳ��x,y������Χ�м�����
				int count=get_mine_count(mine,x,y);
				show[x][y] = count + '0';
				//��ʾ�Ų������Ϣ
				DisplayBoard(show, row, col);

				if (count == 0)
				{
					printf("����ֵΪ0��\n");
					//1.1������ص���0����ô��ʾ�ܱ����е���Ϣ
					//1.1.1 ����һ��	
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

					//1.1.2 �м�һ��
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

					//1.1.3 ����һ��
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
			printf("���겻�Ϸ�������������\n");
		}

	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ���\n");
		DisplayBoard(mine, row, col);

	}

}




