#include <stdio.h>

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

//�ַ�������
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
	case9();

	return 0;
}