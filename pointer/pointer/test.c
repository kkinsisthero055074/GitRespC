#include <stdio.h>

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

//字符串数组
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
	case9();

	return 0;
}