#include <stdio.h>

//1.���������
void arithmetic()
{
	int a = 3 / 6;
	float f1 = 3 / 6;
	float f2 = 3 / 6.0+1;
	//1.1 Ҫ���ñ��ʽ���ص�ֵ��С�������ʽ������������һ����С��,�����ʽ��.3��ʾ�����С��λΪ3λ
	float f3 = 3.0f / 6 + 1;
	//1.2 С���ڴ����лᱻĬ��Ϊdouble���ͣ���ֵ��float���͵�ʱ����ܱ��������������д����1.2f

	printf("a=%d f1=%.1f f2=%.3f f3=%f\n", a, f1, f2,f3);
}

//2. ��λ�����
void move()
{
	int a = 2;
	int a2 = -1;
	int b = a<< 1;
	//2.1 ���������������������ұ߲�0��
	int c = a2>> 1;
	//��ǰ�����Ʋ�����ʹ�õģ���������
	//2.2.1 �������ƣ��ұ߶�������߲�ԭ����λ������λ��0��
	//2.2.2 �߼����ƣ��ұ߶�������߲���0
	printf("a=%d\n", a);//����û�б仯
	printf("b=%d\n",b);
	printf("c=%d\n", c);
	printf("%d\n", sizeof(a));
}


//3. λ������
void rank()
{
	int a = 3;
	int b = 5;
	int c = a & b;//��Ӧ�Ķ�����λ��
	int d = a | b;//��Ӧ�Ķ�����λ��
	int e = a ^ b;//��Ӧ�Ķ�����λ��� ����ͬΪ0������Ϊ1
	printf("c=%d\n", c);//���1
	printf("d=%d\n", d);//���7
	printf("e=%d\n", e);//���6	
}

//4. ����1��a=3;b=5;�������κα���ʹa=5��b=3;
void case1()
{
	int a = 103;
	int b = 1055;
	
// 	a = a + b;
// 	b = a - b;
// 	a = a - b; 
	//�����㷨����������ݵ����

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	//��ʽΪa=(a^b)^b;
	printf("a=%d\n", a);
	printf("b=%d\n", b);
}
//5. ͳ�����ֶ����Ƶ�λ���ж��ٸ�1
void one()
{
	int a =63;
	int ret= 33;
	int num = 0;
	while (ret--)
	{
		printf("%d\n", a);
		int b = 1;
		if (a & b == 1)
		{
			num++;
		}
		a=a >> 1;
		
	}
	printf("the number is %d\n", num);

}

//6. ��Ŀ������
void single()
{
	
	short s = 5;
	int a = 10;
	printf("%d\n", sizeof(s = a + 2));
	printf("%d\n", s);
	//������Ϊ2 5����Ϊsizeof()����ı��ʽ�ǲ��������ģ�

	int a1 = -1;
	int b1 = ~a1;//������ԭ�롢���롢���붼һ����������Ϊ0��
	printf("%d\n", b1);
}

int main()
{
	//arithmetic();
	//move();
	//rank();
	//case1();
	//one();
	single();
	

	return 0;
}