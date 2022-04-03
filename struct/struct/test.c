#include <stdio.h>
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
int main()
{
	struct Stu s = { {"kkk1",20,61.3},"kka",21,"20220403" };
	printf("%s %d %f %s %d %s\n", s.sb.name, s.sb.age, s.sb.score, s.name, s.age, s.id);//直接访问
	struct Stu* p=&s;
	printf("%s %d %f %s %d %s\n", p->sb.name, p->sb.age, p->sb.score, p->name, p->age, p->id);//指针访问
	/*
	每一个函数调用，都会在内存的栈区上，开辟一块空间！
函数传参的时候，参数是要压栈的，如果传递一个结构体对象的时候，接头体过大，参数压栈的系统开销比较大，所以会导致性能的下降。
结论：接头体传参的时候，最好传接头体的地址

	*/
	return 0;
}