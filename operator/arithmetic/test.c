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

	int a2 = 10;
	printf("%p\n", &a2);//输出地址

	//强制类型转换
	double f = (double)1 / 3;
	printf("%f\n", f);

}

//7 逻辑运算符
void logic()
{
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	i = a++&&++b&&d++;
	printf(" a=%d\n b=%d\n c=%d\n d=%d\n", a, b, c, d);
	//因为逻辑运算&&找到0就停止运算，所以a++后面的式子都没有运算
	//输出结果为：a=1 b=2 c=3 d=4

	i = a++||++b||d++;
	printf("\n a=%d\n b=%d\n c=%d\n d=%d\n", a, b, c, d);
	//因为逻辑运算符||找到1就会停止运算，所以a++后面的式子都没有运算
	//输出结果为：a=2 b=2 c=3 d=4

	int f = c || d;
	printf("f=%d\n", f);
	//逻辑|| 和逻辑&& 输出结果为1/0

}

//8 逗号表达式
void dot()
{
	int a = 3;
	int b = 5;
	int c = 0;
	int d = (c = 5, a = c + 3, b = a - 4, c += 5);
	printf("c=%d\nd=%d\n", c,d);
	//逗号表达式返回的是最后一个表达式的结果，最后一个表达式可能受前边表达式的影响
	//输出的结果为c=10 d=10	
}

//9.结构体成员
struct Book
{
	char name[20];
	char id[20];
	double price;
};
void str()
{
	struct Book book1 = { "C语言","C123456",56.7 };
	printf("%s\n%s\n%.2f\n", book1.name, book1.id, book1.price);

	struct Book* p = &book1;
	printf("%s\n%s\n%.2f\n", p->name,p->id, p->price);

	printf("%d %d\n", sizeof(char), sizeof(int));
}


//10 整型提升
void case10()
{
// 	//char和short类型在内存中分别占1个字节和2个字节，但是计算的时候占4个字节（需要整型提升），%d显示的时候也是四个字节
// 	char a = 3;
// 	//内存中:00000011
// 	//计算时候00000000 00000000 00000000 00000011
// 	char b = 127;
// 	//内存中:01111111
// 	//计算时候00000000 00000000 00000000 01111111
// 	char c = a + b;
// 	//计算时候00000000 00000000 00000000 00000011
// 	//计算时候00000000 00000000 00000000 01111111
// 	//计算时候00000000 00000000 00000000 10000010
// 	//内存中存的是10000010
// 	//%d显示的时候 补码：11111111 11111111 11111111 10000010
// 	//%d显示的时候 反码：11111111 11111111 11111111 10000001
// 	//%d显示的时候 原码：10000000 00000000 00000000 01111110
// 	//-126
// 	printf("%d\n", c);
// 	//输出结果为-126
// 
// // 	//负数的整型提升
// // 	char c1 = -1;
// // 	//变量c1的二进制（补码）中只有8个比特位：
// // 	//11111111
// // 	//因为char为有符号的char
// // 	//所以整型提升的时候，高位补充符号位，即为1；
// // 	//提升之后的结果为11111111111111111111111111111111
// // 
// // 	//正数的整型提升
// // 	char c2 = 1;
// // 	//变量c2的二进制（补码）中只有8个比特位00000001
// // 	//所以整型提升的时候，高位补充符号位，即为0；
// // 	//提升之后的结果为00000000000000000000000000000001
// // 
// // 	//无符号的整型提升，高位补0


	char a = 0xb6;
	short b = 0xb600;
	int c = 0xb6000000;
	int d = 0xb600-16*16*16*8;
	if (a == 0xb6)//char a超过16*8=128整型提升后就会变为负数
		printf("a");
	if (b == 0xb600)//int b超过16*16*16*8，整型提升后就会编程负数
		printf("b");
	if (c == 0xb6000000)
		printf("c");
	//所以结果只是输出c,a和b不输出
	printf("\n%d\n", d);//16进制输出的格式为%x

	char c2 = 1;
	printf("%u\n", sizeof(c2));
	printf("%u\n", sizeof(+c2));
	printf("%u\n", sizeof(-c2));
	//输出结果为1 4 4


}

int main()
{
	//arithmetic();
	//move();
	//rank();
	//case1();
	//one();
	//single();
	//logic();
	//dot();
	//str();
	case10();
	

	return 0;
}