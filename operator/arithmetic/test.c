#include <stdio.h>

//1.算术运算符
void arithmetic()
{
	int a = 3 / 6;
	float f1 = 3 / 6;
	float f2 = 3 / 6.0+1;
	//1.1 要想让表达式返回的值是小数，表达式中类型至少有一个是小数,输出格式中.3表示输出的小数位为3位
	float f3 = 3.0f / 6 + 1;
	//1.2 小数在代码中会被默认为double类型，赋值给float类型的时候可能报错，如果想避免可以写成如1.2f

	printf("a=%d f1=%.1f f2=%.3f f3=%f\n", a, f1, f2,f3);
}

//2. 移位运算符
void move()
{
	int a = 2;
	int a2 = -1;
	int b = a<< 1;
	//2.1 左移运算符：左边抛弃，右边补0；
	int c = a2>> 1;
	//当前的右移操作符使用的：算术右移
	//2.2.1 算术右移：右边丢弃，左边补原符号位（正数位是0）
	//2.2.2 逻辑右移：右边丢弃，左边补充0
	printf("a=%d\n", a);//变量没有变化
	printf("b=%d\n",b);
	printf("c=%d\n", c);
	printf("%d\n", sizeof(a));
}


//3. 位操作符
void rank()
{
	int a = 3;
	int b = 5;
	int c = a & b;//对应的二进制位与
	int d = a | b;//对应的二进制位或
	int e = a ^ b;//对应的二进制位异或 ：相同为0，相异为1
	printf("c=%d\n", c);//结果1
	printf("d=%d\n", d);//结果7
	printf("e=%d\n", e);//结果6	
}

//4. 案例1：a=3;b=5;不适用任何变量使a=5；b=3;
void case1()
{
	int a = 103;
	int b = 1055;
	
// 	a = a + b;
// 	b = a - b;
// 	a = a - b; 
	//这种算法可能造成数据的溢出

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	//公式为a=(a^b)^b;
	printf("a=%d\n", a);
	printf("b=%d\n", b);
}
//5. 统计数字二进制的位数有多少个1
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

//6. 单目操作符
void single()
{
	
	short s = 5;
	int a = 10;
	printf("%d\n", sizeof(s = a + 2));
	printf("%d\n", s);
	//输出结果为2 5，因为sizeof()里面的表达式是不参与计算的！

	int a1 = -1;
	int b1 = ~a1;//正数的原码、反码、补码都一样，输出结果为0！
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