#include <stdio.h>

//1 指针占的内存
void ram()
{
	int a1 = 1;
	int* p = &a1;
	double d = 3.14;
	double* p1 = &a1;
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p1));
	//32位中的地址线是32位，所有的指针都是4字节
	//64位中的地址线是64位，所有的指针都是8字节
	//上面不同类型的指针的都是4字节

	int a = 0x11223344;
	//十六进制个位最大数字是15，需要用4个二进制位表示，所以int最多可以有8=4*8/4位十六进制数
	int* pa = &a;
	*pa = 0;	
}
//2.指针类型的意义：2.1 指针类型决定了引用的权限有多大（即赋值的范围） 2.2 指针类型决定了，指针走一步的步长
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

//3. 指针运算
void cal()
{
	float value[5] = { 1,2,3,4,5 };
	float *vp;

	for (vp = &value[0]; vp < &value[5];)
	{
		*vp++ = 0;
		//vp++ 先运算在再++
	}
	//++ --优先级高于* /
	for (int i = 0; i < 5; i++)
	{
		printf("%f ", value[i]);
	}
}

//4. 指针-指针
//指针-指针的前提是两个指针都是指向同一个地址
void sub()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n", &arr[9] - &arr[0]);
}

//5 指针运算
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
	//标注规定：
	//允许指向数组元素的指针域指向数组最后一个元素后面的那个内存位置的指针比较,
	//但是不允许与指向第一个元素之前的那个内存位置的指针进行比较
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