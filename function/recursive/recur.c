#include "stdio.h"
#include <string.h>


//递归函数  1 阶乘函数 n!=n*(n-1) 可以归总为 F(n)=n*F(n-1);
int recur(int x)
{
	if (x == 0)
	{
		return 1;
	}
	else
	{
		return x * recur(x - 1);
	}

}

//递归函数  2.F(0)=F(1)=1,F(n)=F(n-1)+F(n-2) n>=2;
int F(int x)
{
	if (x == 0 || x == 1)
	{
		return 1;
	}
	else
	{
		return F(x - 1)+F(x - 2);
	}
}

//递归函数 3. 逐位打印无符号的整型
void printU(unsigned int x)
{
	if (x / 10 ==  0)
	{
		printf("%d ", x);
		
	}
	else
	{
		printU(x / 10);
		printf("%d ", x % 10);		
	}
}

//递归函数 4.求字符串的长度 
int stringLenth(char* str)
{
	if (*str =='\0')
		return 0;
	else
	{
		return (stringLenth(str+1)+1);//指针变量+，不能++
	}
}


//递归函数 5.汉诺塔
void move(int n, char a, char b, char c)
{
	if (n == 1)
		printf("\t%c->%c\n", a, c);//当n只有1个的时候直接从a移动到c
	else
	{
		move(n - 1, a, c, b); //把a的n-1个盘子通过c移动到b
		printf("\t%c->%c\n", a, c); //把a的最后一个盘（最大的盘）移动到C
		move(n - 1, b, a, c);
	}
}

//递归函数 6.青蛙跳台阶
int frog(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	else
	{
		return (frog(n - 1) + frog(n - 2));
	}	
}

//递归函数 7： 字符串逆向排序
int reverse_string(char* string)
{
	int num = 0;
	if (*string == '\0')
	{
		return 0;
	}
	
	else
	{
		return(reverse_string(string+1)+1);
	}

	return num;
}


//递归函数 8：求一个数的没位数之和
int recur_sum(int num)
{
	if (num<10)
	{
		return num;
	}
	else
	{
		return num % 10 + recur_sum(num / 10);

	}
}


//递归函数 9：编写一个函数实现n的k次方，使用递归实现
int recur_fac(int n,int k)
{
	if (k == 0)
	{
		return 1;
	}
	else
	{
		return recur_fac(n, k - 1)*n;
	}
}


//1-100中出现的9的次数
void nine()
{
	int num = 0;
	for (int i = 1; i < 101; i++)
	{
		if (i / 10 == 9) //10位
		{
			num++;
		}
		if (i % 10 == 9) //各位
		{
			num++;
		}
	}
	
	printf("the total number is: %d\n", num);

}

//计算公式1-1/2+1/3-1/4.........-1/100
void forma()
{
	double sum = 0;

	for (int i = 1; i < 101; i++)
	{
		if (i % 2)
		{
			sum = sum + 1.0 / i;//注意要想输出的结果为小说必须写成：1.0/i；
		}
		else
		{
			sum = sum - 1.0 / i;
		}
	}
	printf("the result is %lf\n", sum);
}

//屏幕上输入乘法口诀
void multi()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d * %d = %d\t", j, i, i*j);
		}
		printf("\n");
	}
}

int main()
{
// 	//1 求阶乘
// 	int x;
// 	printf("input the number:\n");
// 	scanf_s("%d", &x);
// 	int y = recur(x);
// 	printf("%d\n", y);

// 	//2. F函数
// 	int x;
// 	printf("input the number:\n");
// 	scanf_s("%d", &x);
// 	int y = F(x);
// 	printf("%d\n", y);

	//3. 逐位打印
// 	unsigned int x;
// 	printf("input the number:\n");
// 	scanf_s("%u", &x);	
// 	printU(x);

	//4 字符串长度
// 	char str[] = "KKgg123";
// 	printf("%s\n", str);
// 	int len = stringLenth(str);
// 	printf("the length is %d\n", len);

	//5 汉诺塔
// 	int n;
// 	printf("请输入要移动的块数：");
// 	scanf_s("%d", &n);
// 	move(n, 'a', 'b', 'c');

	//6. 青蛙跳台阶
// 	int n;
// 	printf("input the number of n:\n");
// 	scanf_s("%d", &n);
// 	int num=frog(n);
// 	printf("the result is %d\n", num);

	//nine();
	//forma();
	//multi();

// 	char str[] = "1234567";	
// 	int length = reverse_string(str);
// 
// 	char c;
// 	for (int i = 1; i < length / 2+1 ; i++)
// 	{
// 		c = *(str + i - 1);
// 		*(str + i - 1) = *(str + length - 1 - i + 1);
// 		*(str + length - 1 - i + 1) = c;
// 	}
// 	printf("%s\n", str);

// 	int x;
// 	printf("input the value of x：\n");
// 	scanf_s("%d", &x);
// 	printf("the total sum of x is %d\n", recur_sum(x));
	
	int n, k;
	printf("input n and k\n");
	scanf_s("%d %d", &n, &k);
	printf("the result is %d\n", recur_fac(n, k));


	   	  
	return 0;
}