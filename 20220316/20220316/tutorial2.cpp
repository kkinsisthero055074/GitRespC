#include <stdio.h>
#include <string.h>

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

//����2�� ģ���û���¼��ֻ�ܵ�¼���Σ�������������1. ������ַ�����ͬ 2.�ַ�������ÿ���ַ�����ͬ
void case2()
{
	char password[] = { "#KKgg6398" };
	int charNum = 9;
	char password2[20] = { 0 };




	int logInNum = 0;//ͨ��logInNumԼ����¼�Ĵ���
	while (1)
	{
		printf("please input your password:\n");
		gets_s(password2, 19);
		//1.1 ͳ��������ַ���
		int charNum2 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (password2[i] == '\0')
			{
				break;
			}
			charNum2++;
		}
		

		//2.1 ͨ��equal�ж�ÿ���ַ��Ƿ��E��ͬ
		bool equal = 1;
		for (int i = 0; i < 9; i++)
		{
			if (password2[i] != password[i])
			{
				equal = 0;
				break;
			}
		}

		//ͬʱ����1 2����ʱ
		if (charNum == charNum2 && equal)
		{
			printf("log in successfull!\n");
			break;
		}

		logInNum++;
		if (logInNum > 2)
		{
			printf("You have tried more than three times!\n");
			break;
		}
	}
}
//����2��ʹ��string.h�Դ���strcmp(str1,str2)���������ַ����Ƚ�
void case2p1()
{
	char password[] = { "#123A" };
	char password2[20] = { 0 };

	for (int i = 0; i < 3; i++)
	{
		printf("input your password!\n");
		gets_s(password2, 19);

		if (strcmp(password2, password) == 0)
		{
			printf("log in successfully!\n");
			break;
		}

		if (i == 3)
		{
			printf("more than 3 times!\n");
			break;
		}
	}
		


	



		
	
}


	



int main()
{
	//case1();
	//case2();
	case2p1();
	

	return 0;
}