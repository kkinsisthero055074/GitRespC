#include <stdio.h>
#include <string.h>

int global = 100;
//������������
void variable()
{
	//�������ڴ�ռ�
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

	//�ֲ�������������
	int global;
	printf("input the value of global:\n");

	scanf_s("%d", &global);

	printf("the value of global is %d\n", global);

	{
		int a = 0;
		printf("a=%d", a);
		//�ֲ�������������һ����{}��ʶ��������Χ���������ʶ�����
	}
	

}


//���� 
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
	//1��������const���εı��������г����ԣ����ܸı�����ԣ������ٽ��и�ֵ����������ֵ��ԭ����ֵ����
	
	int b = MAX;
	printf("b=%d\n", MAX);
	//2 ��ʶ��������������ʶ��������ֵ�����޸�

	enum Sex s = MALE;
	enum Sex s1 = FEMALE;
	printf("%d\n", s);
	printf("%d\n", s1);
	//3ö�ٳ�����������{}����ֵ�����������ֵ����Ĭ�ϴ�0��ʼ�ĳ���


}


//�ַ���
void String()
{
	char arr[] = "hello";
	//�ַ����ڽ�β��λ��������һ��\0��Ϊ��β�ı�־

	char arr1[] = "abcd";
	char arr2[] = { 'a','b','c','d' };
	//���ַ�ʽ������ַ������Ȳ�ȷ������ӡ�Ľ��Ҳ���ԣ���Ϊϵͳ���Զ���\0����
	printf("%s\n", arr1);
	printf("%s\n", arr2);

	int len = strlen(arr1);
	printf("%d\n", len);

	len = strlen(arr2);
	printf("%d\n", len);


	//ת���ַ�
	// \? ����д���������ʺ�ʹ�ã���ֹ���Ǳ�����

	printf("c:\test\test.c\n");
	//����д��
	printf("\"c:\\test\\test.c\"\n");
	//��ȷд��

	printf("%c\n", '\101');
	printf("%c\n", '\x41');
	//��ӡ�����ַ�A

	printf("%s\n", "c:\test\328\test.c");

	printf("%d\n", strlen("c:\test\328\test.c"));
	//��������14

}


//������
void Operator()
{
	//~��λȡ��
	int a = 0;
	printf("%d\n",~a);

	//���ص�ֵ��-1
	//��������ԭ�롢���롢������һ�µ�
	//����=ԭ�����λ���䣬����λȡ��
	//����=����+1
	//�������ڴ��д���Ƿ���

	int b = 1;
	int c;
	c = (++b) + (++b) + (++b);
	printf("c=%d\n", c);
	//����������ʹ�ã���ͬ�ı������������ͬ�Ľ��


	//ǿ������ת��
	int d = (int)3.141592658;
	char c3 = 121;
	printf("d=%d\n", d);
	printf("c=%c\n", c3);

	//���ű��ʽ
	int da = 0;
	int db = 3;
	int dc = 5;
	int dd = (da = db + 2, dc = da - 4, db = dc + 2);
	printf("dd=%d\n", db);
	//���Ϊ3
	//���ű��ʽ���ǰ����������еı��ʽ��ִ���꣬ȡ���һ�����ʽ��ֵ





}


//���¶���ؼ���
//�ؼ���
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
	//��̬�ֲ�����һֱ���ڣ���ȥ����������
	//�������������ǲ�����

	
}

//define��һ��Ԥ����ָ��
//1 define�������
#define MIN 100
//2. define����ĺ�
#define ADD(X,Y) X+Y
#define ADD2(X,Y) (X+Y)
void Define()
{
	printf("MIN=%d\n", MIN);
	printf("%d\n", 4*ADD(2,3));
	printf("%d\n", 4 * ADD2(2, 3));
	//���永��˵��define�������ֱ���滻��
}

//ָ��
void Pointer()
{
	int num = 20;
	int *p = &num;
	*p = 30;
	printf("%d\n", num);
	printf("%d\n", sizeof(p));
	//˵������������ռ�ڴ�Ŀռ䶼���ĸ��ֽ�
}

//�ṹ��
struct Student
{
	char name[20];//C������û���ַ�������
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