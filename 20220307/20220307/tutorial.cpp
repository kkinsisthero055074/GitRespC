#include <stdio.h>
#include <string.h>

int global = 100;
//变量的作用域
void variable()
{
	//变量的内存空间
	printf("char: ");
	printf("%d\n", sizeof(char));

	printf("short: ");
	printf("%d\n", sizeof(short));

	printf("int: ");
	printf("%d\n", sizeof(int));

	printf("long: ");
	printf("%d\n", sizeof(long));

	printf("long long: ");
	printf("%d\n", sizeof(long long));

	printf("float: ");
	printf("%d\n", sizeof(float));

	printf("double: ");
	printf("%d\n", sizeof(double));

	//局部变量的作用域
	int global;
	printf("input the value of global:\n");

	scanf_s("%d", &global);

	printf("the value of global is %d\n", global);

	{
		int a = 0;
		printf("a=%d", a);
		//局部变量的作用域一般用{}标识，超出范围后编译器不识别变量
	}
	

}


//常量 
#define	MAX 10000
enum Sex
{
	MALE=3, FEMALE=5, SECRET
};
void constant()
{
	const int va = 10;

	printf("input the value of va:");
	scanf_s("%d", &va);
	printf("the value of va is: %d\n", va);
	//1常变量：const修饰的变量，具有常属性（不能改变的属性）不能再进行赋值，就算输入值，原来的值不变
	
	int b = MAX;
	printf("b=%d\n", MAX);
	//2 标识符常量，兵器标识符常量的值不能修改

	enum Sex s = MALE;
	enum Sex s1 = FEMALE;
	printf("%d\n", s);
	printf("%d\n", s1);
	//3枚举常量，可以在{}赋初值，如果不赋初值，会默认从0开始的常量



}


//字符串
void String()
{
	char arr[] = "hello";
	//字符串在结尾的位置隐藏了一个\0作为结尾的标志

	char arr1[] = "abcd";
	char arr2[] = { 'a','b','c','d' };
	//这种方式定义的字符串长度不确定，打印的结果也不对，因为系统会自动给\0结束
	printf("%s\n", arr1);
	printf("%s\n", arr2);

	int len = strlen(arr1);
	printf("%d\n", len);

	len = strlen(arr2);
	printf("%d\n", len);


	//转义字符
	// \? 在书写连续过个问号使用，防止他们被解析

	printf("c:\test\test.c\n");
	//错误写法
	printf("\"c:\\test\\test.c\"\n");
	//正确写法

	printf("%c\n", '\101');
	printf("%c\n", '\x41');
	//打印的是字符A

	printf("%s\n", "c:\test\328\test.c");

	printf("%d\n", strlen("c:\test\328\test.c"));
	//输出结果是14

}

int main()
{
	//variable();
	//constant();
	String();
	return 0;
}