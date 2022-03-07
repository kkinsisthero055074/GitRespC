#include <stdio.h>
//当局部变量和全局变量重名时，优先使用局部变量
//局部变量的作用域就是局部变量所在的范围({}为范围标识),除了范围就不是识别
int global = 100;
int main()
{
	int global;
	printf("input the vlaue of global:\n");

	scanf_s("%d", &global);

	printf("the value of global is %d\n", global);
	return 0;

	{
		int a = 9;
		printf("a=%d", a);
		//在{}范围外就不识别变量a
	}
	

	return 0;
}
