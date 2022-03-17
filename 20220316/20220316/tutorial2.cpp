#include <stdio.h>
#include <string.h>

//案例1：编写代码演示多个字符从两端移动，向中间汇聚
void case1()
{
	char str1[] = { "hello! this is Kang speaking!" };
	char str2[] = { "*****************************" };

	int len = sizeof(str2) / sizeof(str2[0])-1;//长度包括最后一个结束位\0,但是结束位\0不属于内容
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
	printf("the num is %d\n", num); //输出结果为29 证明字符数组最后的结尾是\0
}

//案例2： 模拟用户登录，只能登录三次，满足三个条件1. 输入的字符数相同 2.字符数组中每个字符都相同
void case2()
{
	char password[] = { "#KKgg6398" };
	int charNum = 9;
	char password2[20] = { 0 };




	int logInNum = 0;//通过logInNum约束登录的次数
	while (1)
	{
		printf("please input your password:\n");
		gets_s(password2, 19);
		//1.1 统计输入的字符数
		int charNum2 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (password2[i] == '\0')
			{
				break;
			}
			charNum2++;
		}
		

		//2.1 通过equal判断每个字符是否都鞥相同
		bool equal = 1;
		for (int i = 0; i < 9; i++)
		{
			if (password2[i] != password[i])
			{
				equal = 0;
				break;
			}
		}

		//同时满足1 2条件时
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
//案例2，使用string.h自带的strcmp(str1,str2)函数进行字符串比较
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