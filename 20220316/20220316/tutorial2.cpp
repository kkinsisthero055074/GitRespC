#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

	
	
	if (-10)
		printf("-1\n");
	if (0)
		printf("0\n");
	if (20)
		printf("1\n");
	//���永��˵�������䷵��ֵ��Ϊ0��Ϊ�棬if(������0��Ϊ��)


	for (int i = 1; i < 4; i++)
	{
		printf("input your password!\n");
		gets_s(password2, 19);

		if (strcmp(password2, password) == 0)//strcmp(str1,str2);�ַ�����ȽϺ���������ֵ<0,>0,=0(˵�������ַ�����ͬ)
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



//����3�� дһ����������Ϸ
//1. �Զ�����һ��1-100֮����������
//2 ������
//a �¶��ˣ��͹�ϲ�㣬��Ϸ����
//b�´��ˣ����������˻���С�ˣ������£�֪���¶�
//3 �����Ϸ����һֱ�棬�����˳���Ϸ
void case3()
{
	srand((unsigned)time(NULL));//�����������ʱ��仯
	int num = rand() % 100;
	int numA;
	while (1)
	{
		printf("input your num��if you want to quit, input Q!\n");
		if (getchar() == 'Q')
		{
			printf("quite sucessfuly!\n");
			break;
		}
		scanf_s("%d", &numA, 1);
		
		if (numA > num)
		{
			printf("the number you input is bigger!\n");
			continue;
		}
		else if (numA < num)
		{
			printf("the number you input is smaller!\n");
			continue;
		}
		else
		{
			printf("congratulation! right!\n");
			break;
		}
	}
	
}


//����10��������С��������

void case4()
{
	int num[10];
	int temp;

	for (int i = 0; i < 10; i++)
	{
		printf("input %d number:\n", i +1 );
		scanf_s("%d", &num[i]);
	}//����10������

	//����
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (num[i] > num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}

	//������
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", num[i]);
	}

}

//��ӡ1-100֮������3�ı���
void case5()
{
	for (int i = 1; i < 101; i++)
	{
		if (i % 3 == 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");

}

//��ӡ�����������Լ��
void case6()
{
	int a, b;
	int min;
	printf("input two integers:\n");
	scanf_s("%d %d", &a, &b);

	min = a;
	if (a > b)
	{
		min = b;
	}

	int num = 1;//���Լ��
	for (int i = 1; i < min + 1; i++)
	{
		if (a%i == 0 && b%i == 0)
		{
			num = i;
		}
	}

	printf("greatest common divisor of %d and %d is %d\n", a, b, num);
}

//��ӡ1000��2000֮�������
//����1 �ܱ�4 ���ܱ�100���� 2 �ܱ�400����������
void case7()
{
	for (int i = 1000; i < 2051; i++)
	{
		if (i % 400 == 0)
		{
			printf("%d ", i);
		}
		else if (i % 4==0 && i % 100 != 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}

//��ӡ100-200֮�������
void case8()
{
	for (int i = 100; i <= 200; i++)
	{
		int count = 0;
		for (int j = 2; j < i ; j++)
		{
			if (i%j == 0)
			{
				count++;
			}
		}
		if (count == 0)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
}

//�˷��ھ���
void case9()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d * %d = %d\t",j,i,i*j);
		}
		printf("\n");
	}

}


//�ػ����������������Ծͻ���1�����ڹػ���������롰��������ȡ���ػ�
//c�����ṩ��һ��������system()-ִ��ϵͳ�����
void case10()
{
	char input[50] = { 0 };
	system("shutdown -s -t 60");//-s:shutdown t:time 60��ʾ�����������ʱ��ĵ�λ����
								//-r:��ȫ�رղ����������������  -p�رձ��ؼ������û�г�ʱ�򾯸� -h���߱��ؼ���� -f:ǿ�ƹر��������е�Ӧ�ó���������Ⱦ����û�

again:
	printf("��ע�⣬���ĵ�����1�����ڹػ���������룻��������ȡ���ػ�\n");
	gets_s(input, 49);
	if (strcmp(input, "������") == 0)
	{
		system("shutdown -a"); //-a:��ʾȡ��
	}
	else
	{
		goto again;
	}
}

int main()
{
	//case1();
	//case2();
	//case2p1();
	//case3();
	//case4();
	//case5();
	//case6();
	//case7();
	//case8();
	//case9();
	case10();
	

	return 0;
}