#include <stdio.h>
#include <string.h>

//数组案例1： 冒泡排序
void bubble_sort(int arr[],int len) //数组传递的时候，传递的是数组的首地址
{
	
	int temp;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}	
}

int main()
{
	// 	//一维数组定义的两种方式1 2
	// 	int arr[10] = { 1,2,3,4,5,6 };//剩余的位置自动填充的是0；
	// 	int arr2[] = { 10,9,8,7 };
	// 
	// 	char ch1[] = { 'b','i','t' };//这样定义自定是3个字符 b i t不包括\0，如果数组成员数少于规定值也会自动填充\0
	// 	char ch2[] = "bit"; //这样定义是四个字符 b i t \0
	// 	printf("%d\n", strlen(ch1)); //长度不确定，为随机值，因为没找到\0
	// 	printf("%d\n", strlen(ch2)); //长度一定
	// 
	// 
	// 	char ch3[5] = "bit";//这样定义是五个字符 b i t \0 \0
	// 	char ch4[4] = "bitk";
	// 	char ch5[4] = {'a','b','c','d'};
	// 
	// 	printf("%d\n", arr2); //打印整型数组
	// 	printf("%s\n", ch1); //打印结果，后面也会出现乱码
	// 	printf("%s\n", ch4); //打印结果后面会出现乱码
	// 	printf("%s\n", ch5); //打印结果后面同样会出现乱码

	// 	//1.1 一维数组的访问
	// 	char str[] = "123456";	
	// 	int len = sizeof(str) / sizeof(str[0]);
	// 	for (int i = 0; i < len; i++)
	// 	{				
	// 		printf("%c\t", str[i]);
	// 	}

	// 	//1.1.2 一维数组使用指针访问
	// 	char str[] = "12345679";
	// 	char* p = str;
	// 	int len = sizeof(str) / sizeof(str[0]);
	// 	printf("the length is %d\n", len);//说明自动\0占位，但是不显示在字符串的内容中
	// 	
	// 	printf("all the data in str as shown below:\n");
	// 	for (int i = 0; i < len; i++)
	// 	{
	// 		printf("%c\t", *(p + i));
	// 	}
	// 	printf("\n");
	   	 
	// 	//1.2  数组的输出格式
	// 	int i = 360;
	// 	printf("%-6d\n", i);
	// 
	// 	char str1[] = "kkins055074";
	// 	printf("%-20.5s\n", str1);//左对齐20.5表示共输出20位，从字符串中取5位
	// 
	// 	char str2[] = "3698";
	// 	printf("%+20s\n", str2);//右对齐
	// 
	// 	double f = -3.141592658;
	// 	double f2 = 3.1;
	// 
	// 	printf("% .6f\n", f); //空格，若是浮点型为负显示"-"，正显示空格
	// 	printf("% .6f\n", f2); //小数点后面自动补充0
	   
	// 	// 2. 二维数组
	// 	//2.1.1 初始化方式 1
	// 	int arr[3][4] = { 1,2,3,4,5,6,7,8,9 }; //顺序赋值，自动填充0
	// 	//2.1.2 初始化方式 2
	// 	int arr2[3][4] = { {1,2,3},{1,2} };//按照每行赋值，一行赋值不完全自动填充0

// 		//2.2 二维数组的使用
// 		//2.2.1 通过指针调用二维数组的元素，说明二维数组在内存中是连续的
// 	int arr[][4] = { {1,2,3},{4,5 }, { 6 } };
// 	int* p = arr;
// 	for (int i = 0; i < 3; i++)
// 	{
// 		for (int j = 0; j < 4; j++)
// 		{
// 			printf("%d\t", *(p + i * 4 + j));
// 		}
// 		printf("\n");
// 	}
// 	//2.2.2 直接调用数组元素
// 	for (int i = 0; i < 3; i++)
// 	{
// 		for (int j = 0; j < 4; j++)
// 		{
// 			printf("%d\t", arr[i][j]);
// 		}
// 		printf("\n");
// 	}

	//3. 数组作为函数参数
	//数组名是数组首元素的地址
	//但是有两个例外：1.sizeof(数组名)，此时的的数组名表示的是整个数组；2. &数组名，此时的数组名表示的是整个数组-取出的是整个数组的地址
	int arr[] = { 9,8,7,6,5,4,3,2,1,10 };
	//排序为升序冒泡排序
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("the length is %d\n", len);
	bubble_sort(arr,len);//数组传参的时候，传递的是数组的地址
	
	for (int i = 0; i < len; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	
	printf("%p\n", &arr);
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);//以上三个的输出的结果都相同

	printf("%p\n", &arr+1);//和下面两个语句得输出结果不相同，因为增加了整个数组
	printf("%p\n", arr+1);
	printf("%p\n", &arr[0]+1);



	return 0;
}