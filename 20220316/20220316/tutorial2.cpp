#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

	
	
	if (-10)
		printf("-1\n");
	if (0)
		printf("0\n");
	if (20)
		printf("1\n");
	//上面案例说明添加语句返回值不为0即为真，if(条件非0即为真)


	for (int i = 1; i < 4; i++)
	{
		printf("input your password!\n");
		gets_s(password2, 19);

		if (strcmp(password2, password) == 0)//strcmp(str1,str2);字符串标比较函数，返回值<0,>0,=0(说明两个字符串相同)
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



//案例3： 写一个猜数字游戏
//1. 自动产生一个1-100之间的随机数；
//2 猜数字
//a 猜对了，就恭喜你，游戏结束
//b猜错了，会告诉你大了还是小了，继续猜，知道猜对
//3 这个游戏可以一直玩，除非退出游戏
void case3()
{
	srand((unsigned)time(NULL));//随机函数随着时间变化
	int num = rand() % 100;
	int numA;
	while (1)
	{
		printf("input your num：if you want to quit, input Q!\n");
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


//输入10个数，从小到大排序

void case4()
{
	int num[10];
	int temp;

	for (int i = 0; i < 10; i++)
	{
		printf("input %d number:\n", i +1 );
		scanf_s("%d", &num[i]);
	}//输入10个数字

	//排序
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

	//输出结果
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", num[i]);
	}

}

//打印1-100之间所有3的倍数
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

//打印两个数的最大公约数
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

	int num = 1;//最大公约数
	for (int i = 1; i < min + 1; i++)
	{
		if (a%i == 0 && b%i == 0)
		{
			num = i;
		}
	}

	printf("greatest common divisor of %d and %d is %d\n", a, b, num);
}

//打印1000到2000之间的闰年
//闰年1 能被4 不能被100整除 2 能被400整除是闰年
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

//打印100-200之间的素数
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

//乘法口诀表
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


//关机程序：运行起来电脑就会在1分钟内关机，如果输入“我是猪”就取消关机
//c语言提供了一个函数：system()-执行系统命令的
void case10()
{
	char input[50] = { 0 };
	system("shutdown -s -t 60");//-s:shutdown t:time 60表示秒数，这里的时间的单位是秒
								//-r:完全关闭并且重新启动计算机  -p关闭本地计算机，没有超时或警告 -h休眠本地计算机 -f:强制关闭正在运行的应用程序而不事先警告用户

again:
	printf("请注意，您的电脑在1分钟内关机，如果输入；我是猪，就取消关机\n");
	gets_s(input, 49);
	if (strcmp(input, "我是猪") == 0)
	{
		system("shutdown -a"); //-a:表示取消
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