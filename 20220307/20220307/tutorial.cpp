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
	//�ṹ��ָ��
	printf("%s %d %f\n", pa->name, pa->age,pa->score);

	struct Student* pb = &s1;
	printf("%s %d %f\n", (*pb).name, (*pb).age, (*pb).score);

	char str[10] = "kkini";
	printf("%s\n", str);

	char strb[10] = "change";
	strcpy(str, strb);	
	printf("%s\n", str);
	//ʹ�ú���strcpy(�ַ�������,�ַ�������)���ı��ַ����������
	   	  
}

//��֧���if else
void IfEsle()
{
	int a = 0;
	int b = 2;
	if (a == 1)
		if (b == 2)
		{
			printf("hehe\n");
		}			
		else
		{
			printf("haha\n");
		}
			
}
//���ʲô��û��ӡ����Ϊelse���Զ��������if����ϵ


//��֧���switch
void Switch()
{
	int n = 1;
	int m = 2;
	
	switch (n)
	{
	case 1:m++;
	case 2:n++;
	case 3:
		switch (n)
		{
		case 1:
			n++;
		case 2:
			m++;
			n++;
			break;
		}
	case 4:
		m++;
		break;
	default:
		break;
	}
	printf("m=%d,n=%d\n", m, n);
}
//������Ϊ��5,3 break����������ѭ�����߷�֧���


//ѭ�����
void Loop()
{
	int num;
	for (int i = 1; i < 11; i++)
	{
		printf("%d\n", i);

		for (int j = 0; j < 5; j++)
		{
			num = 10 * i + j;
			if (num > 60)
			{
				break;
			}
			printf("%d\t", num);
			
		}
		printf("\n");	
	}
	//˵����break��ѭ�����������������ѭ��

	int i = 1;

	while (i <= 10)
	{
		i++;
		if(i==5)
			continue;
		printf("%d", i);
		
	}
	//continue����������ѭ������Ĵ��룬������һ��ѭ��	
}


void ClearBuf() //������ջ�����
{
	int ch;
	while ((ch = getchar()) != EOF && ch != '\n')
	{
		;
	}
}


void Character()
{
	//1 �ַ��������
	char str[] = "kkinsisthero055074\\nddf";
	printf("%s\n", str);//��ʽ1
	puts(str);//��ʽ2����ַ��������Զ�����

	//2 �ַ���������
	//Ϊ�˷�ֹ��������ݴ��ڱ������ַ�����-1,��ɶ�����ַ�д����ջ�У�����ԭ�ȵ����ݣ�����ʹ��scanf_s("%s",str,n-1)��ggets_s(str,n-1)����
	char str2[8] = { 0 };
	char str3[8] = { 0 };
	printf("input a string:\n");
	scanf_s("%s", str2,7); //1 ����scanf_s("%s",str,n-1)��������(Ԥ��\0)
						   //�����涨������ַ��������洢,������
						   //scanf_s()����ֻ���������ַ���\0�ò��ߣ�����Ҫ�ǲ������棬��ֱ��������һ������ֱ�ӶԱ�����ֵ
							
	ClearBuf();//��ջ�����,scanf_s�������




	printf("input a string:\n");
	gets_s(str3, 7);//2 ����gets_s("%s",str,n-1)��������(Ԥ��\0)��
				   //�����涨������ַ�����ֱ�ӻᱨ��
				 //gets_s(str,n-1)�����������ַ�����\0�����Բ�������Ҳ����

	char ch;
	printf("input again\n");
	ch = getchar();

	printf("%s\n", str2);
	printf("%s\n", str3);
	printf("%c\n", ch);
	

		
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
	//Struct();
	//IfEsle();
	//Switch();
	//Loop();
	Character();
	

	return 0;
}