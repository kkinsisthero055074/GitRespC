#include <stdio.h>
//���ֲ�������ȫ�ֱ�������ʱ������ʹ�þֲ�����
int global = 100;
int main()
{
	int global;
	printf("input the vlaue of global:\n");

	scanf_s("%d", &global);

	printf("the value of global is %d\n", global);
	return 0;
}
