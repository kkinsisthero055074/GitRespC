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

int main()
{
	//variable();
	//constant();
	String();
	return 0;
}