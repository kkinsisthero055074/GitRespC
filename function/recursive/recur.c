#include "stdio.h"
#include <string.h>


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

//�ݹ麯�� 4.���ַ����ĳ��� 
int stringLenth(char* str)
{
	if (*str =='\0')
		return 0;
	else
	{
		return (stringLenth(str+1)+1);//ָ�����+������++
	}
}


//�ݹ麯�� 5.��ŵ��
void move(int n, char a, char b, char c)
{
	if (n == 1)
		printf("\t%c->%c\n", a, c);//��nֻ��1����ʱ��ֱ�Ӵ�a�ƶ���c
	else
	{
		move(n - 1, a, c, b); //��a��n-1������ͨ��c�ƶ���b
		printf("\t%c->%c\n", a, c); //��a�����һ���̣������̣��ƶ���C
		move(n - 1, b, a, c);
	}
}

//�ݹ麯�� 6.������̨��
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

	//3. ��λ��ӡ
// 	unsigned int x;
// 	printf("input the number:\n");
// 	scanf_s("%u", &x);	
// 	printU(x);

	//4 �ַ�������
// 	char str[] = "KKgg123";
// 	printf("%s\n", str);
// 	int len = stringLenth(str);
// 	printf("the length is %d\n", len);

	//5 ��ŵ��
// 	int n;
// 	printf("������Ҫ�ƶ��Ŀ�����");
// 	scanf_s("%d", &n);
// 	move(n, 'a', 'b', 'c');

	//6. ������̨��
// 	int n;
// 	printf("input the number of n:\n");
// 	scanf_s("%d", &n);
// 	int num=frog(n);
// 	printf("the result is %d\n", num);


	   	  
	return 0;
}