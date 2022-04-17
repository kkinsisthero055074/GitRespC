#include <stdio.h>
#include <math.h>

//1 指针占的内存
void ram()
{
	int a1 = 1;
	int* p = &a1;
	double d = 3.14;
	double* p1 = &a1;
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p1));
	//32位中的地址线是32位，所有的指针都是4字节
	//64位中的地址线是64位，所有的指针都是8字节
	//上面不同类型的指针的都是4字节

	int a = 0x11223344;
	//十六进制个位最大数字是15，需要用4个二进制位表示，所以int最多可以有8=4*8/4位十六进制数
	int* pa = &a;
	*pa = 0;	
}
//2.指针类型的意义：2.1 指针类型决定了引用的权限有多大（即赋值的范围） 2.2 指针类型决定了，指针走一步的步长
void case2()
{
	int arr[10] = { 0 };
	int *p = arr;
	char *pc = arr;
	printf("%p\n", p);
	printf("%p\n", p + 1);

	printf("%p\n", pc);
	printf("%p\n", pc + 1);
}

//3. 指针运算
void cal()
{
	float value[5] = { 1,2,3,4,5 };
	float *vp;

	for (vp = &value[0]; vp < &value[5];)
	{
		*vp++ = 0;
		//vp++ 先运算在再++
	}
	//++ --优先级高于* /
	for (int i = 0; i < 5; i++)
	{
		printf("%f ", value[i]);
	}
}

//4. 指针-指针
//指针-指针的前提是两个指针都是指向同一个地址
void sub()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n", &arr[9] - &arr[0]);
}

//5 指针运算
void poiter_cal()
{
	float value[5] = { 1,2,3,4,5 };
	float* vp = NULL;

	for (vp = &value[5-1]; vp >= &value[0]; vp--)
	{
		*vp = 0;
	}

	for (vp = &value[5-1]; vp >= &value[0]; vp--)
	{
		printf("%f ", *vp);
	}	
	//标注规定：
	//允许指向数组元素的指针域指向数组最后一个元素后面的那个内存位置的指针比较,
	//但是不允许与指向第一个元素之前的那个内存位置的指针进行比较
}


//6 指针与数组
void arr()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n", arr[3]);
	printf("%d\n", 3[arr]);
	printf("%d\n", *(arr+3));
	//arr[3]会被编译成*(arr+3)=*(3+arr),所以3[arr]也成立，[]只是个操作符
	
}

//7 二级指针
void doub()
{
	int a = 10;
	int* pa = &a;//一级指针
	int** ppa = &pa;//二级指针
	int* pch[3] = { NULL,NULL,NULL };//指针数组

}

//8 字符指针
void case8()
{
	char str1[] = "hello world.";
	char str2[] = "hello world.";
	char* str3 = "hello world.";
	//使用这种方式赋值，编译器会认为"hello world."字符串是字符量常量，如果字符串内容一样，会默认是同一个字符串常量,存储在同一个地址，并且字符串常量的值是不能改变的。
	//定义的时候最好如： const char* str3="hello world."; 防止后边通过指针改变字符串常量的值。
	char* str4 = "hello world.";

	if (str1==str2)
	{
		printf("str1 and str2 are same\n");
	}
	else
	{
		printf("str1 and str2 are not same\n");
	}

	if (str3 == str4)
	{
		printf("str3 and str4 are same\n");
	}
	else
	{
		printf("str3 and str4 are not same\n");
	}

	//*str3 = "123";
	//因为指针指向字符串常量，会出现错误！
	printf("%s", str3);
}

//9. 字符串数组
void case9()
{
	int a[5] = { 1,2,3,4,5 };
	int b[] = { 2,3,4,5,6 };
	int c[] = { 3,4,5,6,7 };
	int* arr[3] = { a,b,c };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", *(arr[i] + j));
			//也可以是下面语句，即：*(arr[i]+j)=arr[i][j]
			//printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

// 	int* arr[10];//整形指针的数组
// 	char* arr2[4];//一级字符指针的数组
// 	char** arr3[5];//二级字符指针的数组

}

//10. 数组指针
void case10()
{
	//1. 数组指针的定义
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *p = arr; //取的是数组的地址 数组名是首元素的地址
	int(*pr)[10] = &arr;//[]的优先级高于*
	//pr就是一个数组指针-其中存放的是数组的指针

	printf("%p\n", arr);
	printf("%p\n", &arr);
	printf("%p\n", arr+1);
	printf("%p\n", &arr+1);
	//arr和&arr,虽然值是一样的，但是意义不一样，&arr+1和&arr的差值是40
	//数组名是数组首元素的地址，但是有2个例外：
	//1.1. sizeof(数组名); 数组名表示是整个数组，计算的是整个数组的大小，单位是字节
	//1.2. &数组名-数组名表示的是整个数组，取回的是整个数组的地址

	double* d[5];
	double*(*pd)[5] = &d;//指针数组

	//2.数组指针的使用

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", *(*pr + i));
	}
	//2.1 可以这样写，但是不建议

	//2.2 int(*parr[10])[5]
	//parr是一个存储10个数组指针的数组，每个指针指向5个int类型的指针


	//3. 数组与指针参数传递
	//3.1 一维数组传参
	//int arr[10]={0};test(arr);可以以下面三种方式传递
	//void test(int arr[]);
	//void test(int arr[10]);
	//void test(int *arr);

	//int *arr2[20]={0};test2(arr2);可以以下面两种方式传递
	//void test2(int *arr[20]);
	//void test2(int **arr);

	//3.2 二维数组传参
	//int arr[3][5]={0};test(arr);可以以下面两种方式传递
	//void test(int arr[3][5]);
	//void test(int arr[][5]);
	//void test(int (*parr)[5]);//因为arr此时代表的是一行的地址
	//总结：二维数组传参，函数形参只能省略第一个[]的数字
	//因此对一个二维数组，可以不知道多少行，但是必须知道一行多少个元素


}

//11.1 二维数组打印的第一种方式
void print1(int arr[3][4], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", arr[i][j]);
			//printf("%d ",*(arr+i*c+j));
		}
		printf("\n");
	}
}

//11.2 二维数组打印的第二种方式
void print2(int(*p)[4], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}


//11. 打印二维数组
void case11()
{
	int arr[3][4] = { {1,2,3,4}, {2,3,4,5}, {3,4,5,6} };
	
	//print1(arr, 3, 4);
	print2(arr, 3, 4);
	//一维数组的数组名表示的是首元素的地址，二维数组的数组名表示的是第一行的地址

}

//12  大端存储
void case12()
{
	int a = 0x11223344;//十六进制数据表示方法（1个数字表示4位）
	char *p = (char*)&a;//强制类型转换
	
	for (int i = 0; i < 4; i++)
	{
		printf("%x ", *(p + i));//十六进制输出
	}
	//输入的结果为44 33  22 11 说明存储方式为大端

	*p = 0;
	printf("%x\n", a);
}
//13 int 和 unsigned int 类型进行比较时涉及的类型转换
int i;//全局变量，不初始化，默认是0
void case13()
{
	i--;
	//sizeof这操作符，算出的结果的类型是unsigned int
	//有符号的int和无符号的int比较的时候先转换成无符号的int
	if (i > sizeof(int))
		printf(">\n");
	else
		printf("<\n");
}

//14
void case14()
{
	int a = 0;
	int n = 0;
	printf("input a and n:\n");
	scanf_s("%d %d",&a,&n);
	printf("%d %d\n", a, n);
	int sum = 0;
	int num = 0;

	for (int i = 0; i < n; i++)
	{
		num = num * 10 + a;		
		sum = sum + num;
		
	}
	printf("the sum is %d\n",sum);
}
int case15A(int a)
{
	int bit_num = 0;
	int num = a;
	int sum = 0;

	while (1)
	{
		bit_num++;
		num = num / 10;

		if (num == 0)
		{
			break;
		}
	}
	

	num = a;
	for (int i = 0; i < bit_num; i++)
	{
		sum = sum + pow((num % 10), bit_num);
		num = num / 10;
	}
	return sum;
}

//15 打印水仙花数
void case15()
{


	for (int i = 1; i < 100000; i++)
	{
		if (case15A(i) == i)
			printf("%d ", i);

	}
}

//案例16
void case16()
{
	unsigned long pulArray[] = { 6,7,8,9,10 };
	unsigned long *pulPtr;
	pulPtr = pulArray;
	*(pulPtr + 3) += 3;
	printf("%d,%d\n", *pulPtr, *(pulPtr + 3));
}

//案例17 写一个程序，可以逆序一个字符的内容
void case17(char* p)
{
	char*p0 = p;
	int num = 0;
	int left = 0;
	int right;
	char temp;

	//统计出字符串中的元素数！num
	while (1)
	{
		if (*p == '\0')
			break;
		num++;
		p++;
	}

	//将字符串逆序
	p =p0;
	right = num - 1;
	while (left<right)
	{
		temp = *(p + left);
		*(p + left) = *(p + right);
		*(p + right) = temp;
		left++;
		right--;
	}

}

//案例18
void case18()
{
	char arr[20] = { 0 };
	for (int i = 0; i < 13; i++)
	{
		arr[i] = ' ';
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			arr[6 - j] = '*';
			arr[6 + j] = '*';
		}
		printf("%s\n",arr);
	}
	arr[0] = arr[12] = '*';
	printf("%s\n", arr);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			arr[j] = ' ';
			arr[12-j] = ' ';
		}
		printf("%s\n", arr);
	}

}

//案例19 
void case19()
{
	//上面
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (j >= 6 - i && j <= 6 + i)
			{
				printf(" *");
			}
			else
				printf("  ");
		}
		printf("\n");
	}
	//下面
	for (int i=0;i<6;i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (j <= i || j>=13-i)
			{
				printf("  ");
			}
			else
			{
				printf(" *");
			}

		}
		printf("\n");
			
	}
}

//案例20：一瓶汽水1元，2个空瓶可以换一瓶汽水，给20元可以喝多少汽水
int  case20(int money)
{
	int sum = money;
	int num = money;

	while (num>1)
	{
		sum = sum + num / 2;
		num = num / 2 + num % 2;
	}
	return sum;
}

//案例21 输入数组：来调整数组中的顺序所有的奇数位于全半部门
void case21(int* p,int size)
{
	int temp;
	int num = 0;
	//标记替换等等次数
	for (int i=0;i<size-num;i++)
	{

		if (*(p + i) % 2 == 0)
		{
			temp = *(p + i);
			for (int j = i; j < size - 1; j++)
			{
				*(p + j) = *(p + j + 1);
			}
			*(p + size - 1) = temp;
			num++;
			i--;
		}
	}
	

}

int main()
{
	//ram();
	//case2();
	//cal();
	//sub();
	//poiter_cal();
	//arr();
	//doub();
	//case8();
	//case9();
	//case10();
	//case11();
	//case12();
	//case13();
	//case14();
	//case15();
	//case16();
	
// 	char str[200] = { 0 };
// 	printf("input the string:\n");	
// 	gets_s(str, 199);
// 	printf("%s\n", str);
// 	case17(str);
// 	printf("the result is %s\n", str);
	//case18();
	//case19();
	
// 	int money;
//     printf("input the money:\n");
//   	scanf_s("%d",&money);
// 	printf("the total num is %d", case20(money));

	int arr[] = {1,2,3,4,5,6,7,8,9,10,12,14};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", size);
	case21(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf(" %d", arr[i]);
	}

	
	


	

	return 0;
}