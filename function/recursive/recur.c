#include "stdio.h"

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

	unsigned int x;
	printf("input the number:\n");
	scanf_s("%u", &x);	
	printU(x);
	
	return 0;
}