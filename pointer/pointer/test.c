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



int main()
{
	//ram();
	//case2();
	//cal();
	//sub();
	poiter_cal();


	return 0;
}