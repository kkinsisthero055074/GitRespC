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


//�������ĺ���ʵ��
void PlayerMover(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("�����>\n");

		printf("��������������꣺>");
		scanf_s("%d %d", &x, &y);

		//�ж�����ֵ�ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�������
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';				
				break;
			}
			else
			{
				printf("���걻ռ�ã�����������\n");
			}
		}
		else
		{
			printf("��������Ƿ�������������\n");
		}

	}

}


//��������ĺ���ʵ��
void ComputerMove(char board[ROW][COL], int row, int col)
{

	printf("������>\n");
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

//�ж��Ƿ�Ӯ����Ϸ 1���Ӯ* 2����Ӯ# 3ƽ��Q 4��Ϸ����C
char IsWin(char board[ROW][COL], int row, int col)
{
	//1 ���Ƿ��ֱ��
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






	//2 ���Ƿ�Ϊֱ��
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



	//3 �Խ��Ƿ�Ϊֱ��
	//3.1 ���ϵ��¶Խ���
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





	//3.2 ���µ��϶Խ���
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

	//4 ��Ϸ��û�н���
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