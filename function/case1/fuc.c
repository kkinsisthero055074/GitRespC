#include "stdio.h"
#include "sub.h"


//���뾲̬��
#pragma comment(lib,"sub.lib");
int main()
{
	int x = 5;
	int y = 10;
	int z = sub(x, y);
	printf("%d\n", z);
	return 0;
}