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

	char szInput[256];
	printf("Enter a sentence:");
	scanf_s("%s", szInput, 256);
	printf("The sentence entered is %u characters long.\n", my_strlen(szInput));

	return 0;	
	
}