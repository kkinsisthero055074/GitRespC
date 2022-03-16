#include <stdio.h>

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

//案例2： 模拟用户登录，并且只能登录三次，如果密码正确则提示登录成功，如果三次输入错误则退出程序
void case2()
{
	char password[] = { "#KKgg6398" };
	char password2[100] = { 0 };
	int len = sizeof(password) / sizeof(char)-1;
	int charNum = 9;
		

	//分析需要满足两个条件才能登录：1. 输入字符数相同  2 每个字符数相同
	int num = 0; //3 次数不超过三次
	while (1)
	{
		printf("please input your password:\n");
		gets_s(password2, 99);
		//1.1 统计输入的字符数
		int charNum2 = 0;
		for (int i = 0; i < 99; i++)
		{
			if (password2[i] == '\0')
				break;
			charNum2++;
		}
		
		//2.1 通过equal判断每个字符是否相同
		bool equal = 1;
		for (int i = 0; i < charNum; i++)
		{
			if (password[i] != password2[i])
				equal = 0;
		}

		if (charNum == charNum2 && equal)//同时满足1 2
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