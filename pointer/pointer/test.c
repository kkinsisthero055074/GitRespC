#include <stdio.h>
#include <math.h>

//1 ָ��ռ���ڴ�
void ram()
{
	int a1 = 1;
	int* p = &a1;
	double d = 3.14;
	double* p1 = &a1;
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p1));
	//32λ�еĵ�ַ����32λ�����е�ָ�붼��4�ֽ�
	//64λ�еĵ�ַ����64λ�����е�ָ�붼��8�ֽ�
	//���治ͬ���͵�ָ��Ķ���4�ֽ�

	int a = 0x11223344;
	//ʮ�����Ƹ�λ���������15����Ҫ��4��������λ��ʾ������int��������8=4*8/4λʮ��������
	int* pa = &a;
	*pa = 0;	
}
//2.ָ�����͵����壺2.1 ָ�����;��������õ�Ȩ���ж�󣨼���ֵ�ķ�Χ�� 2.2 ָ�����;����ˣ�ָ����һ���Ĳ���
void case2()
{
	int arr[10] = { 0 };
	int *p = arr;
	char *pc = arr;
	printf("%p\n", p);
	printf("%p\n", p + 1);

	printf("%p\n", pc);
	printf("%p\n", pc + 1);
}

//3. ָ������
void cal()
{
	float value[5] = { 1,2,3,4,5 };
	float *vp;

	for (vp = &value[0]; vp < &value[5];)
	{
		*vp++ = 0;
		//vp++ ����������++
	}
	//++ --���ȼ�����* /
	for (int i = 0; i < 5; i++)
	{
		printf("%f ", value[i]);
	}
}

//4. ָ��-ָ��
//ָ��-ָ���ǰ��������ָ�붼��ָ��ͬһ����ַ
void sub()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n", &arr[9] - &arr[0]);
}

//5 ָ������
void poiter_cal()
{
	float value[5] = { 1,2,3,4,5 };
	float* vp = NULL;

	for (vp = &value[5-1]; vp >= &value[0]; vp--)
	{
		*vp = 0;
	}

	for (vp = &value[5-1]; vp >= &value[0]; vp--)
	{
		printf("%f ", *vp);
	}	
	//��ע�涨��
	//����ָ������Ԫ�ص�ָ����ָ���������һ��Ԫ�غ�����Ǹ��ڴ�λ�õ�ָ��Ƚ�,
	//���ǲ�������ָ���һ��Ԫ��֮ǰ���Ǹ��ڴ�λ�õ�ָ����бȽ�
}


//6 ָ��������
void arr()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n", arr[3]);
	printf("%d\n", 3[arr]);
	printf("%d\n", *(arr+3));
	//arr[3]�ᱻ�����*(arr+3)=*(3+arr),����3[arr]Ҳ������[]ֻ�Ǹ�������
	
}

//7 ����ָ��
void doub()
{
	int a = 10;
	int* pa = &a;//һ��ָ��
	int** ppa = &pa;//����ָ��
	int* pch[3] = { NULL,NULL,NULL };//ָ������

}

//8 �ַ�ָ��
void case8()
{
	char str1[] = "hello world.";
	char str2[] = "hello world.";
	char* str3 = "hello world.";
	//ʹ�����ַ�ʽ��ֵ������������Ϊ"hello world."�ַ������ַ�������������ַ�������һ������Ĭ����ͬһ���ַ�������,�洢��ͬһ����ַ�������ַ���������ֵ�ǲ��ܸı�ġ�
	//�����ʱ������磺 const char* str3="hello world."; ��ֹ���ͨ��ָ��ı��ַ���������ֵ��
	char* str4 = "hello world.";

	if (str1==str2)
	{
		printf("str1 and str2 are same\n");
	}
	else
	{
		printf("str1 and str2 are not same\n");
	}

	if (str3 == str4)
	{
		printf("str3 and str4 are same\n");
	}
	else
	{
		printf("str3 and str4 are not same\n");
	}

	//*str3 = "123";
	//��Ϊָ��ָ���ַ�������������ִ���
	printf("%s", str3);
}

//9. �ַ�������
void case9()
{
	int a[5] = { 1,2,3,4,5 };
	int b[] = { 2,3,4,5,6 };
	int c[] = { 3,4,5,6,7 };
	int* arr[3] = { a,b,c };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", *(arr[i] + j));
			//Ҳ������������䣬����*(arr[i]+j)=arr[i][j]
			//printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

// 	int* arr[10];//����ָ�������
// 	char* arr2[4];//һ���ַ�ָ�������
// 	char** arr3[5];//�����ַ�ָ�������

}

//10. ����ָ��
void case10()
{
	//1. ����ָ��Ķ���
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *p = arr; //ȡ��������ĵ�ַ ����������Ԫ�صĵ�ַ
	int(*pr)[10] = &arr;//[]�����ȼ�����*
	//pr����һ������ָ��-���д�ŵ��������ָ��

	printf("%p\n", arr);
	printf("%p\n", &arr);
	printf("%p\n", arr+1);
	printf("%p\n", &arr+1);
	//arr��&arr,��Ȼֵ��һ���ģ��������岻һ����&arr+1��&arr�Ĳ�ֵ��40
	//��������������Ԫ�صĵ�ַ��������2�����⣺
	//1.1. sizeof(������); ��������ʾ���������飬���������������Ĵ�С����λ���ֽ�
	//1.2. &������-��������ʾ�����������飬ȡ�ص�����������ĵ�ַ

	double* d[5];
	double*(*pd)[5] = &d;//ָ������

	//2.����ָ���ʹ��

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", *(*pr + i));
	}
	//2.1 ��������д�����ǲ�����

	//2.2 int(*parr[10])[5]
	//parr��һ���洢10������ָ������飬ÿ��ָ��ָ��5��int���͵�ָ��


	//3. ������ָ���������
	//3.1 һά���鴫��
	//int arr[10]={0};test(arr);�������������ַ�ʽ����
	//void test(int arr[]);
	//void test(int arr[10]);
	//void test(int *arr);

	//int *arr2[20]={0};test2(arr2);�������������ַ�ʽ����
	//void test2(int *arr[20]);
	//void test2(int **arr);

	//3.2 ��ά���鴫��
	//int arr[3][5]={0};test(arr);�������������ַ�ʽ����
	//void test(int arr[3][5]);
	//void test(int arr[][5]);
	//void test(int (*parr)[5]);//��Ϊarr��ʱ�������һ�еĵ�ַ
	//�ܽ᣺��ά���鴫�Σ������β�ֻ��ʡ�Ե�һ��[]������
	//��˶�һ����ά���飬���Բ�֪�������У����Ǳ���֪��һ�ж��ٸ�Ԫ��


}

//11.1 ��ά�����ӡ�ĵ�һ�ַ�ʽ
void print1(int arr[3][4], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", arr[i][j]);
			//printf("%d ",*(arr+i*c+j));
		}
		printf("\n");
	}
}

//11.2 ��ά�����ӡ�ĵڶ��ַ�ʽ
void print2(int(*p)[4], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}


//11. ��ӡ��ά����
void case11()
{
	int arr[3][4] = { {1,2,3,4}, {2,3,4,5}, {3,4,5,6} };
	
	//print1(arr, 3, 4);
	print2(arr, 3, 4);
	//һά�������������ʾ������Ԫ�صĵ�ַ����ά�������������ʾ���ǵ�һ�еĵ�ַ

}

//12  ��˴洢
void case12()
{
	int a = 0x11223344;//ʮ���������ݱ�ʾ������1�����ֱ�ʾ4λ��
	char *p = (char*)&a;//ǿ������ת��
	
	for (int i = 0; i < 4; i++)
	{
		printf("%x ", *(p + i));//ʮ���������
	}
	//����Ľ��Ϊ44 33  22 11 ˵���洢��ʽΪ���

	*p = 0;
	printf("%x\n", a);
}
//13 int �� unsigned int ���ͽ��бȽ�ʱ�漰������ת��
int i;//ȫ�ֱ���������ʼ����Ĭ����0
void case13()
{
	i--;
	//sizeof�������������Ľ����������unsigned int
	//�з��ŵ�int���޷��ŵ�int�Ƚϵ�ʱ����ת�����޷��ŵ�int
	if (i > sizeof(int))
		printf(">\n");
	else
		printf("<\n");
}

//14
void case14()
{
	int a = 0;
	int n = 0;
	printf("input a and n:\n");
	scanf_s("%d %d",&a,&n);
	printf("%d %d\n", a, n);
	int sum = 0;
	int num = 0;

	for (int i = 0; i < n; i++)
	{
		num = num * 10 + a;		
		sum = sum + num;
		
	}
	printf("the sum is %d\n",sum);
}
int case15A(int a)
{
	int bit_num = 0;
	int num = a;
	int sum = 0;

	while (1)
	{
		bit_num++;
		num = num / 10;

		if (num == 0)
		{
			break;
		}
	}
	

	num = a;
	for (int i = 0; i < bit_num; i++)
	{
		sum = sum + pow((num % 10), bit_num);
		num = num / 10;
	}
	return sum;
}

//15 ��ӡˮ�ɻ���
void case15()
{


	for (int i = 1; i < 100000; i++)
	{
		if (case15A(i) == i)
			printf("%d ", i);

	}
}

//����16
void case16()
{
	unsigned long pulArray[] = { 6,7,8,9,10 };
	unsigned long *pulPtr;
	pulPtr = pulArray;
	*(pulPtr + 3) += 3;
	printf("%d,%d\n", *pulPtr, *(pulPtr + 3));
}

//����17 дһ�����򣬿�������һ���ַ�������
void case17(char* p)
{
	char*p0 = p;
	int num = 0;
	int left = 0;
	int right;
	char temp;

	//ͳ�Ƴ��ַ����е�Ԫ������num
	while (1)
	{
		if (*p == '\0')
			break;
		num++;
		p++;
	}

	//���ַ�������
	p =p0;
	right = num - 1;
	while (left<right)
	{
		temp = *(p + left);
		*(p + left) = *(p + right);
		*(p + right) = temp;
		left++;
		right--;
	}

}

//����18
void case18()
{
	char arr[20] = { 0 };
	for (int i = 0; i < 13; i++)
	{
		arr[i] = ' ';
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			arr[6 - j] = '*';
			arr[6 + j] = '*';
		}
		printf("%s\n",arr);
	}
	arr[0] = arr[12] = '*';
	printf("%s\n", arr);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			arr[j] = ' ';
			arr[12-j] = ' ';
		}
		printf("%s\n", arr);
	}

}

//����19 
void case19()
{
	//����
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (j >= 6 - i && j <= 6 + i)
			{
				printf(" *");
			}
			else
				printf("  ");
		}
		printf("\n");
	}
	//����
	for (int i=0;i<6;i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (j <= i || j>=13-i)
			{
				printf("  ");
			}
			else
			{
				printf(" *");
			}

		}
		printf("\n");
			
	}
}

//����20��һƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ���Ժȶ�����ˮ
int  case20(int money)
{
	int sum = money;
	int num = money;

	while (num>1)
	{
		sum = sum + num / 2;
		num = num / 2 + num % 2;
	}
	return sum;
}

//����21 �������飺�����������е�˳�����е�����λ��ȫ�벿��
void case21(int* p,int size)
{
	int temp;
	int num = 0;
	//����滻�ȵȴ���
	for (int i=0;i<size-num;i++)
	{

		if (*(p + i) % 2 == 0)
		{
			temp = *(p + i);
			for (int j = i; j < size - 1; j++)
			{
				*(p + j) = *(p + j + 1);
			}
			*(p + size - 1) = temp;
			num++;
			i--;
		}
	}
	

}

int main()
{
	//ram();
	//case2();
	//cal();
	//sub();
	//poiter_cal();
	//arr();
	//doub();
	//case8();
	//case9();
	//case10();
	//case11();
	//case12();
	//case13();
	//case14();
	//case15();
	//case16();
	
// 	char str[200] = { 0 };
// 	printf("input the string:\n");	
// 	gets_s(str, 199);
// 	printf("%s\n", str);
// 	case17(str);
// 	printf("the result is %s\n", str);
	//case18();
	//case19();
	
// 	int money;
//     printf("input the money:\n");
//   	scanf_s("%d",&money);
// 	printf("the total num is %d", case20(money));

	int arr[] = {1,2,3,4,5,6,7,8,9,10,12,14};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", size);
	case21(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf(" %d", arr[i]);
	}

	
	


	

	return 0;
}