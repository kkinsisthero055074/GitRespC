#include "stdio.h"

//�ݹ麯��  1 �׳˺��� n!=n*(n-1) ���Թ���Ϊ F(n)=n*F(n-1);
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

//�ݹ麯��  2.F(0)=F(1)=1,F(n)=F(n-1)+F(n-2) n>=2;
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

//�ݹ麯�� 3. ��λ��ӡ�޷��ŵ�����
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
// 	//1 ��׳�
// 	int x;
// 	printf("input the number:\n");
// 	scanf_s("%d", &x);
// 	int y = recur(x);
// 	printf("%d\n", y);

// 	//2. F����
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