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

//5. ͳ�ƶ�������1�ĸ���
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

//6. ��С������
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
//7. ��һ�仰���ã���㲻����,���볤�Ȳ�����100
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

// 	//���������ʾ
// 	int i = 1;
// 	int ret = (++i) + (++i) + (++i); 
// 	//case6:
// 	int a, b;
// 	printf("input a and b:\n");
// 	scanf_s("%d %d", &a, &b);
// 	printf("the least common multi of a and b is %d\n", least_common_multi(a, b));

// 	char arr[101] = { 0 };
// 	printf("input a sentence:\n");
// 	//scanf_s("%[^\n]", arr, 100);//1.1 ����ո���ַ���
// 	gets_s(arr, 100);//1.2 ��gets�������뺬�пո���ַ���
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
// 	//�����л���ִ��󣺾ֲ���������ջ�ջ�ǴӸߵ�ַ��ʼ��
// 	//���release�汾�б����������Ż�����i����arr[]�����ĵĵ͵�ַ
	
	
	

	return 0;	
	
}