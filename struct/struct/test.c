#include <stdio.h>
struct B
{
	char name[20];
	int age;
	double score;
};
struct Stu
{
	//��Ա����
	struct B sb;
	char name[20];
	int age;
	char id[20];
}s1��s2;
//s1 s2�ǽṹ������������ǽṹ��ȫ�ֱ���
int main()
{
	struct Stu s = { {"kkk1",20,61.3},"kka",21,"20220403" };
	printf("%s %d %f %s %d %s\n", s.sb.name, s.sb.age, s.sb.score, s.name, s.age, s.id);//ֱ�ӷ���
	struct Stu* p=&s;
	printf("%s %d %f %s %d %s\n", p->sb.name, p->sb.age, p->sb.score, p->name, p->age, p->id);//ָ�����
	/*
	ÿһ���������ã��������ڴ��ջ���ϣ�����һ��ռ䣡
�������ε�ʱ�򣬲�����Ҫѹջ�ģ��������һ���ṹ������ʱ�򣬽�ͷ����󣬲���ѹջ��ϵͳ�����Ƚϴ����Իᵼ�����ܵ��½���
���ۣ���ͷ�崫�ε�ʱ����ô���ͷ��ĵ�ַ

	*/
	return 0;
}