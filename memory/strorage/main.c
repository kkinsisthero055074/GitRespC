#include <stdio.h>



//1. 判断是大端存储还是小端存储
void storage_order()
{
	int a = 1;
	char*p = (char*)&a;//强制类型转换
	if (*p == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
}

//2. 整型提升,根据最高位自动补充1/0。当类型如unsigned chart时，自动补充0
//2.1 char到底是signed char还是unsigned char? 这个取决于编译器
//2.2 int是signed int  short是signed short
void output_result()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;

	printf("a=%d,b=%d,c=%d\n", a, b, c);
}

//3.案例3
void case3()
{
	char a = -128;
	printf("%u", a);
}

//4. 案例4
void case4()
{
	int i = -20;
	unsigned int j = 10;	
	printf("%d\n", i + j);	
}

//5 案例5
void case5()
{
	unsigned int i=0;
	printf("%u", i-1);

	for (i = 9; i >=0; i--)
	{
		printf("%u\n", i);
	}
	//出现死循环，因为unsigned int类型数据，不会出现<0的数字
}

//6. 有符号的整型数字超出最大值
void case6()
{
	int a = 2147483645;
	
	//int最小值为-2147483648 最大值为2147483647，大于最大值，会变成负值，且负值的绝对值会越来越小
	//如果输出是%u 结果会不一样
	//归根接地还是内存二进制加（1/0转换）
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", ++a);
	}
	printf("\n");

	a = -2147483645;

	//int最小值为-2147483648 最大值为2147483647，小于最小值，变成正值，且整数越来小
	//如果输出是%u 结果会不一样
	//归根结底还是内存二进制加（1/0转换）
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", --a);
	}
}

//7char 的取值范围
void case7()
{
	char a = '\0';
	printf("%d\n", a);
	
}

//8 浮点型数据的储存
//8.1 浮点型的存储方式！ 最后M去除最高位1后，是从高位从右向左填充二进制数字的
void case8()
{
	printf("%d\n", sizeof(int));
	int n = 9;
	float* pFloat = (float*)&n;
	printf("n的值为：%d\n", n);
	printf("*pFloat的值为：%f\n",*pFloat);

	*pFloat = 9.0;
	printf("num的值为： %d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);
}

//案例9
void case9()
{
	unsigned char a = 200;
	unsigned char b = 100;
	unsigned char c = 0;
	c = a + b;
	//a+b的时候进行整型数据提升，但是赋值给c的时候又进行了截取
	printf("%d %d", a + b, c);
	//所以输出的结果为300 44
}
//案例10
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
//案例11
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

//案例12  确定嫌疑犯
void case12()
{
	char killer = 0;
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		//表达式直接可以返回1/0
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
		{
			printf("the killer is %c\n", killer);
		}
	}
}
//案例13 
/*
	5名运动员参加了10米台跳水比赛，预测的结果：
	A: B第二，我第三
	B: 我第二，E第四
	C: 我第一，D第二
	D: C最后，我第三
	E: 我第四，A第一；
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