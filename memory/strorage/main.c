#include <stdio.h>



//1. �ж��Ǵ�˴洢����С�˴洢
void storage_order()
{
	int a = 1;
	char*p = (char*)&a;//ǿ������ת��
	if (*p == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
}

//2. ��������,�������λ�Զ�����1/0����������unsigned chartʱ���Զ�����0
//2.1 char������signed char����unsigned char? ���ȡ���ڱ�����
//2.2 int��signed int  short��signed short
void output_result()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;

	printf("a=%d,b=%d,c=%d\n", a, b, c);
}

//3.����3
void case3()
{
	char a = -128;
	printf("%u", a);
}

//4. ����4
void case4()
{
	int i = -20;
	unsigned int j = 10;	
	printf("%d\n", i + j);	
}

//5 ����5
void case5()
{
	unsigned int i=0;
	printf("%u", i-1);

	for (i = 9; i >=0; i--)
	{
		printf("%u\n", i);
	}
	//������ѭ������Ϊunsigned int�������ݣ��������<0������
}

//6. �з��ŵ��������ֳ������ֵ
void case6()
{
	int a = 2147483645;
	
	//int��СֵΪ-2147483648 ���ֵΪ2147483647���������ֵ�����ɸ�ֵ���Ҹ�ֵ�ľ���ֵ��Խ��ԽС
	//��������%u ����᲻һ��
	//����ӵػ����ڴ�����Ƽӣ�1/0ת����
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", ++a);
	}
	printf("\n");

	a = -2147483645;

	//int��СֵΪ-2147483648 ���ֵΪ2147483647��С����Сֵ�������ֵ��������Խ��С
	//��������%u ����᲻һ��
	//�����׻����ڴ�����Ƽӣ�1/0ת����
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", --a);
	}
}

//7char ��ȡֵ��Χ
void case7()
{
	char a = '\0';
	printf("%d\n", a);
	
}

//8 ���������ݵĴ���
//8.1 �����͵Ĵ洢��ʽ�� ���Mȥ�����λ1���ǴӸ�λ�������������������ֵ�
void case8()
{
	printf("%d\n", sizeof(int));
	int n = 9;
	float* pFloat = (float*)&n;
	printf("n��ֵΪ��%d\n", n);
	printf("*pFloat��ֵΪ��%f\n",*pFloat);

	*pFloat = 9.0;
	printf("num��ֵΪ�� %d\n", n);
	printf("*pFloat��ֵΪ��%f\n", *pFloat);
}

//����9
void case9()
{
	unsigned char a = 200;
	unsigned char b = 100;
	unsigned char c = 0;
	c = a + b;
	//a+b��ʱ����������������������Ǹ�ֵ��c��ʱ���ֽ����˽�ȡ
	printf("%d %d", a + b, c);
	//��������Ľ��Ϊ300 44
}
//����10
void case10()
{
	char a = '\0';
	printf("%d\n", a);
}

void print11(int* p,int row,int col)
{
	
	for (int i = 0; i < row; i++)
	{
		int k = row - i;
		while (k--)
		{
			printf(" ");
		}


		for (int j = 0; j < col; j++)
		{
			if (*(p + i * col + j) == 0)
			{
				break;
			}
			printf("%d ", *(p + i * col + j));

		}
		printf("\n");
	}


}
//����11
void case11()
{
	int arr[10][10] = { {1},{1,1},{1,2,1} };
	int *p = &arr;

	for (int i = 3; i < 10; i++)
	{
		arr[i][0] = 1;
		arr[i][i ] = 1;
		for (int j = 1; j < i ; j++)
		{
			arr[i][j] = arr[i - 1][j-1] + arr[i - 1][j ];
		}
	}
	print11(p, 10, 10);


}

//����12  ȷ�����ɷ�
void case12()
{
	char killer = 0;
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		//���ʽֱ�ӿ��Է���1/0
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
		{
			printf("the killer is %c\n", killer);
		}
	}
}
//����13 
/*
	5���˶�Ա�μ���10��̨��ˮ������Ԥ��Ľ����
	A: B�ڶ����ҵ���
	B: �ҵڶ���E����
	C: �ҵ�һ��D�ڶ�
	D: C����ҵ���
	E: �ҵ��ģ�A��һ��
*/
void case13()
{
	for (int a = 1; a < 6; a++)
	{
		for (int b=1;b<6;b++)
		{
			for (int c=1;c<6;c++)
			{
				for (int d=1;d<6;d++)
				{
					for (int e=1;e<6;e++)
					{
						if (((b==2)+(a==3)==1)
							&& ((b == 2) + (e == 4) == 1)
							&& ((c == 1) + (d == 2) == 1)
							&& ((c == 5) + (d == 3) == 1)
							&& ((e == 4) + (a == 1) == 1)
							)
						{
							printf("%d %d %d %d %d\n", a, b, c, d, e);
						}
					

					}

				}
			}
		}
	}
	

	
}

int main()
{
	//storage_order();
	//output_result();
	//case3();
	//case4();
	//case5();
	//case6();
	//case7();
	//case8();
	//case9();
	//case10();
	//case11();
	//case12();
	case13();


	return 0;
}