#include <stdio.h>
//当局部变量和全局变量重名时，优先使用局部变量
int global = 100;
int main()
{
	int global;
	printf("input the vlaue of global:\n");

	scanf_s("%d", &global);

	printf("the value of global is %d\n", global);
	return 0;
}
