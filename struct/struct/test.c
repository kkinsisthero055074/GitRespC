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
	//��Ա����
	struct B sb;
	char name[20];
	int age;
	char id[20];
}s1��s2;
//s1 s2�ǽṹ������������ǽṹ��ȫ�ֱ���
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

//3. ģ���ַ�����ֵ����
//const���εı�����Ϊ��������������ֵ���ܸ���
//const int* p=&a;const����ָ�������ʱ���������*����ߣ���ʾָ��ָ������ǲ����޸ĵģ�����ָ����ĵ�ַ�ǿ��Ը��ĵ�
//int* const p=&a;const����ָ�������ʱ���������*���ұߣ���ʾָ����������ǲ��ܱ��޸ĵģ�����ָ��ָ��������ǿ��Ը��ĵ�
// const int* const p=&a;ֵ��ָ����ĵ�ַ�����ܸ���
char* my_strcpy(char* dest,const char* str)
{
	assert(str != NULL);//���ԣ�����Ϊ�ٵ����лᱨ��
	assert(dest != NULL);//����
	char* ret = dest;
	while (*dest++=*str++)
	{
		;//hello�Ŀ���
	}
	//1.while(����)��������������Ϊ��ֵ���жϸ�ֵ��0 �� ��0
	//2. '\0'�ķ���ֵ����0
	
	return ret;//����Ŀ��ռ����ʵ��ַ
}

//4. ģ���ַ������Ⱥ���strlen();
size_t my_strlen(const char*  dest)
{
	assert(dest != NULL);//����Ϊ�٣������лᱨ��
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
// 	printf("%s %d %f %s %d %s\n", s.sb.name, s.sb.age, s.sb.score, s.name, s.age, s.id);//ֱ�ӷ���
// 	struct Stu* p=&s;
// 	printf("%s %d %f %s %d %s\n", p->sb.name, p->sb.age, p->sb.score, p->name, p->age, p->id);//ָ�����
// 	
// 																							  /*
// 	ÿһ���������ã��������ڴ��ջ���ϣ�����һ��ռ䣡
// �������ε�ʱ�򣬲�����Ҫѹջ�ģ��������һ���ṹ������ʱ�򣬽�ͷ����󣬲���ѹջ��ϵͳ�����Ƚϴ����Իᵼ�����ܵ��½���
// ���ۣ���ͷ�崫�ε�ʱ����ô���ͷ��ĵ�ַ
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