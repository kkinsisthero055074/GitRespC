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

//�ݹ麯�� 7�� �ַ�����������
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


//�ݹ麯�� 8����һ������ûλ��֮��
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


//�ݹ麯�� 9����дһ������ʵ��n��k�η���ʹ�õݹ�ʵ��
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


//1-100�г��ֵ�9�Ĵ���
void nine()
{
	int num = 0;
	for (int i = 1; i < 101; i++)
	{
		if (i / 10 == 9) //10λ
		{
			num++;
		}
		if (i % 10 == 9) //��λ
		{
			num++;
		}
	}
	
	printf("the total number is: %d\n", num);

}

//���㹫ʽ1-1/2+1/3-1/4.........-1/100
void forma()
{
	double sum = 0;

	for (int i = 1; i < 101; i++)
	{
		if (i % 2)
		{
			sum = sum + 1.0 / i;//ע��Ҫ������Ľ��ΪС˵����д�ɣ�1.0/i��
		}
		else
		{
			sum = sum - 1.0 / i;
		}
	}
	printf("the result is %lf\n", sum);
}

//��Ļ������˷��ھ�
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
// 	printf("input the value of x��\n");
// 	scanf_s("%d", &x);
// 	printf("the total sum of x is %d\n", recur_sum(x));
	
	int n, k;
	printf("input n and k\n");
	scanf_s("%d %d", &n, &k);
	printf("the result is %d\n", recur_fac(n, k));


	   	  
	return 0;
}