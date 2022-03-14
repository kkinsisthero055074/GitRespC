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


//操作符
void Operator()
{
	//~按位取反
	int a = 0;
	printf("%d\n",~a);

	//返回的值是-1
	//正整数的原码、反码、补码是一致的
	//反码=原码符号位不变，其他位取反
	//补码=反码+1
	//整数在内存中存的是反码

	int b = 1;
	int c;
	c = (++b) + (++b) + (++b);
	printf("c=%d\n", c);
	//不建议这样使用，不同的编译器会产生不同的结果


	//强制类型转换
	int d = (int)3.141592658;
	char c3 = 121;
	printf("d=%d\n", d);
	printf("c=%c\n", c3);

	//逗号表达式
	int da = 0;
	int db = 3;
	int dc = 5;
	int dd = (da = db + 2, dc = da - 4, db = dc + 2);
	printf("dd=%d\n", db);
	//结果为3
	//逗号表达式即是把括号中所有的表达式都执行完，取最后一个表达式的值





}


//重新定义关键字
//关键字
void Key()
{
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			int a = 10;
			a = a + i * 10 + j;
			printf("a=%d ", a);
		}
	}
	printf("\n");

	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			static int a = 10;			
			a = a + i * 10 + j;
			printf("a=%d ", a);
		}
	}
	printf("\n");
	//静态局部变量一直存在，回去后跳过定义
	//超过其作用域还是不能用

	
}

//define是一个预处理指令
//1 define定义符号
#define MIN 100
//2. define定义的宏
#define ADD(X,Y) X+Y
#define ADD2(X,Y) (X+Y)
void Define()
{
	printf("MIN=%d\n", MIN);
	printf("%d\n", 4*ADD(2,3));
	printf("%d\n", 4 * ADD2(2, 3));
	//上面案例说明define定义宏是直接替换的
}

//指针
void Pointer()
{
	int num = 20;
	int *p = &num;
	*p = 30;
	printf("%d\n", num);
	printf("%d\n", sizeof(p));
	//说明：所有类型占内存的空间都是四个字节
}

//结构体
struct Student
{
	char name[20];//C语言中没有字符串类型
	int age;
	double score;

};
void Struct()
{
	struct Student s1 = { "kangkang",32,82.36 };
	printf("%s %d %f\n", s1.name, s1.age, s1.score);
	
	struct Student* pa = &s1;
	printf("%s %d %f\n", pa->name, pa->age,pa->score);



}

int main()
{
	//variable();
	//constant();
	//String();
	//Operator();
	//Key();
	//Define();
	//Pointer();
	Struct();


	return 0;
}