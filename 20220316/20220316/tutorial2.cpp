#include <stdio.h>

//����1����д������ʾ����ַ��������ƶ������м���
void case1()
{
	char str1[] = { "hello! this is Kang speaking!" };
	char str2[] = { "*****************************" };

	int len = sizeof(str2) / sizeof(str2[0])-1;//���Ȱ������һ������λ\0,���ǽ���λ\0����������
	printf("%d\n", len);


	int i = 0;
	int j = len - 1;

	do 
	{
		str2[i] = str1[i];
		str2[j] = str1[j];
		printf("%s\n", str2);
		i++;
		j--;
	} while (i<j);
	printf("%s\n", str1);

	int num = 0;
	for (int i = 1; i < 100; i++)
	{
		if (str1[i - 1] == '\0')
			break;
		printf("%d %c\n", i, str1[i - 1]);
		num++;
	}
	printf("the num is %d\n", num); //������Ϊ29 ֤���ַ��������Ľ�β��\0
}

//����2�� ģ���û���¼������ֻ�ܵ�¼���Σ����������ȷ����ʾ��¼�ɹ��������������������˳�����
void case2()
{
	char password[] = { "#KKgg6398" };
	char password2[100] = { 0 };
	int len = sizeof(password) / sizeof(char)-1;
	int charNum = 9;
		

	//������Ҫ���������������ܵ�¼��1. �����ַ�����ͬ  2 ÿ���ַ�����ͬ
	int num = 0; //3 ��������������
	while (1)
	{
		printf("please input your password:\n");
		gets_s(password2, 99);
		//1.1 ͳ��������ַ���
		int charNum2 = 0;
		for (int i = 0; i < 99; i++)
		{
			if (password2[i] == '\0')
				break;
			charNum2++;
		}
		
		//2.1 ͨ��equal�ж�ÿ���ַ��Ƿ���ͬ
		bool equal = 1;
		for (int i = 0; i < charNum; i++)
		{
			if (password[i] != password2[i])
				equal = 0;
		}

		if (charNum == charNum2 && equal)//ͬʱ����1 2
		{
			printf("long in successfully!\n");
			break;
		}
		num++;

		if (num > 2)
		{
			printf("more than 3 times! please try next time!\n");
			break;
		}


	}

	   
}

	



int main()
{
	//case1();
	case2();
	

	return 0;
}