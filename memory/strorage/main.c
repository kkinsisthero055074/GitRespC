#include <stdio.h>



//1. �ж��Ǵ�˴洢����С�˴洢
void storage_order()
{
	int a = 1;
	char*p = (char*)&a;//ǿ������ת��
	if (*p == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
}

//2. ��������,�������λ�Զ�����1/0����������unsigned chartʱ���Զ�����0
//2.1 char������signed char����unsigned char? ���ȡ���ڱ�����
//2.2 int��signed int  short��signed short
void output_result()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;

	printf("a=%d,b=%d,c=%d\n", a, b, c);
}

//3.����3
void case3()
{
	char a = -128;
	printf("%u", a);
}

//4. ����4
void case4()
{
	int i = -20;
	unsigned int j = 10;	
	printf("%d\n", i + j);	
}

//5 ����5
void case5()
{
	unsigned int i=0;
	printf("%u", i-1);

	for (i = 9; i >=0; i--)
	{
		printf("%u\n", i);
	}
	//������ѭ������Ϊunsigned int�������ݣ��������<0������
}

//6. �з��ŵ��������ֳ������ֵ
void case6()
{
	int a = 2147483645;
	
	//int��СֵΪ-2147483648 ���ֵΪ2147483647���������ֵ�����ɸ�ֵ���Ҹ�ֵ�ľ���ֵ��Խ��ԽС
	//��������%u ����᲻һ��
	//����ӵػ����ڴ�����Ƽӣ�1/0ת����
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", ++a);
	}
	printf("\n");

	a = -2147483645;

	//int��СֵΪ-2147483648 ���ֵΪ2147483647��С����Сֵ�������ֵ��������Խ��С
	//��������%u ����᲻һ��
	//�����׻����ڴ�����Ƽӣ�1/0ת����
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", --a);
	}
}

//7char ��ȡֵ��Χ
void case7()
{
	char a = '\0';
	printf("%d\n", a);
	
}

//8 ���������ݵĴ���
//8.1 �����͵Ĵ洢��ʽ�� ���Mȥ�����λ1���ǴӸ�λ�������������������ֵ�
void case8()
{
	printf("%d\n", sizeof(int));
	int n = 9;
	float* pFloat = (float*)&n;
	printf("n��ֵΪ��%d\n", n);
	printf("*pFloat��ֵΪ��%f\n",*pFloat);

	*pFloat = 9.0;
	printf("num��ֵΪ�� %d\n", n);
	printf("*pFloat��ֵΪ��%f\n", *pFloat);

}

int main()
{
	//storage_order();
	//output_result();
	//case3();
	//case4();
	//case5();
	//case6();
	//case7();
	case8();


	return 0;
}