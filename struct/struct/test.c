#include <stdio.h>
#include <assert.h>
#include <string.h>
struct B
{
	char name[20];
	int age;
	double score;
};
struct Stu
{
	//成员变量
	struct B sb;
	char name[20];
	int age;
	char id[20];
}s1，s2;
//s1 s2是结构体变量，而且是结构体全局变量
//1.
void test01()
{
	printf("kk0.\n");
}

//2.
void test02()
{
	test01();
}

//3. 模拟字符串赋值函数
//const修饰的变量称为常变量，变量的值不能更改
//const int* p=&a;const修饰指针变量的时候，如果放在*的左边，表示指针指向的内是不能修改的，但是指针里的地址是可以更改的
//int* const p=&a;const修饰指针变量的时候，如果放在*的右边，表示指针里的资质是不能被修改的，但是指针指向的内容是可以更改的
// const int* const p=&a;值和指针里的地址都不能更改
char* my_strcpy(char* dest,const char* str)
{
	assert(str != NULL);//断言，条件为假调试中会报错
	assert(dest != NULL);//断言
	char* ret = dest;
	while (*dest++=*str++)
	{
		;//hello的拷贝
	}
	//1.while(条件)，其中条件可以为赋值，判断赋值是0 或 非0
	//2. '\0'的返回值即是0
	
	return ret;//返回目标空间的其实地址
}

//4. 模拟字符串长度函数strlen();
size_t my_strlen(const char*  dest)
{
	assert(dest != NULL);//条件为假，调试中会报错！
	size_t num = 0;
	while(*dest++ != '\0')
	{
		num++;
	}
	return num;
}

//5. 统计二进制中1的个数
size_t bi_num(int a)
{
	int num = 0;
	for (int i = 0; i < 32; i++)
	{
		if (a & 1 == 1)
		{
			num++;
		}
		a=a >> 1;
	}
	return num;

}

//6. 最小公倍数
int least_common_multi(int a,int b)
{
	int max = (a > b) ? a : b;
	int multi = 0;
	for (int i = 1;; i++)
	{
		if (a*i%b == 0)
		{
			multi = a * i;
			break;
		}
	}
	return multi;
}
//7. 将一句话倒置，标点不倒置,输入长度不超过100
void upside_down(char* p)
{
	int arr[60] = {0};
	int num = -1;

	for (int i=0;i<100;i++)
	{
		if (*(p + i) == ' ')
		{
			num++;
			arr[num] = i;
		}
		else if (*(p+i)=='\0')
		{
			num++;
			arr[num] = i;
			break;
		}
	}

	printf("%d\n", num);
	printf("%d\n", arr[num - 1]);
	printf("%d\n", arr[num ]);

	while (num)
	{
		for (int i=arr[num-1]+1;i<arr[num];i++)
		{
			printf("%c", *(p+i));
		}
		printf(" ");
		num--;
	}
	for (int i = 0; i < arr[0]; i++)
	{
		printf("%c", *(p + i));
	}





}


int main()
{
// 	struct Stu s = { {"kkk1",20,61.3},"kka",21,"20220403" };
// 	printf("%s %d %f %s %d %s\n", s.sb.name, s.sb.age, s.sb.score, s.name, s.age, s.id);//直接访问
// 	struct Stu* p=&s;
// 	printf("%s %d %f %s %d %s\n", p->sb.name, p->sb.age, p->sb.score, p->name, p->age, p->id);//指针访问
// 	
// 																							  /*
// 	每一个函数调用，都会在内存的栈区上，开辟一块空间！
// 函数传参的时候，参数是要压栈的，如果传递一个结构体对象的时候，接头体过大，参数压栈的系统开销比较大，所以会导致性能的下降。
// 结论：接头体传参的时候，最好传接头体的地址
// 
// 	*/

	//test02();
	//case3();
	
// 	char arr[20] = "xxxxxxxxx";
// 	char arr2[] = "hello123456789";
// 	printf("%s\n", my_strcpy(arr, arr2));

// 	char szInput[256];
// 	printf("Enter a sentence:");
// 	scanf_s("%s", szInput, 256);
// 	printf("The sentence entered is %u characters long.\n", my_strlen(szInput));
// 	printf("input a num:\n");
// 	int a = 0;
// 	int b = 0;
// 	printf("input the number of a and b:\n");
// 	scanf_s("%d %d", &a, &b);
// 	int c = a ^ b;
// 	printf("numbers of differenet bit is %d\n", bi_num(c));

// 	//错误代码演示
// 	int i = 1;
// 	int ret = (++i) + (++i) + (++i); 
// 	//case6:
// 	int a, b;
// 	printf("input a and b:\n");
// 	scanf_s("%d %d", &a, &b);
// 	printf("the least common multi of a and b is %d\n", least_common_multi(a, b));

// 	char arr[101] = { 0 };
// 	printf("input a sentence:\n");
// 	//scanf_s("%[^\n]", arr, 100);//1.1 输入空格的字符串
// 	gets_s(arr, 100);//1.2 用gets函数输入含有空格的字符串
// 	printf("%s", arr);
// 	//upside_down(arr);

// 	int i = 0;
// 	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
// 	printf("%p\n", &i);
// 	printf("%p\n", &arr[9]);
// 	for (int i = 0; i < 12; i++)
// 	{
// 		arr[i] = 0;
// 		printf("hehe\n");
// 	}
// 	//调试中会出现错误：局部变量放在栈里，栈是从高地址开始的
// 	//如果release版本中编译器会做优化，把i放在arr[]变量的的低地址
	
	
	

	return 0;	
	
}