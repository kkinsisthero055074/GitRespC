#include <stdio.h>
//���ֲ�������ȫ�ֱ�������ʱ������ʹ�þֲ�����
//�ֲ���������������Ǿֲ��������ڵķ�Χ({}Ϊ��Χ��ʶ),���˷�Χ�Ͳ���ʶ��
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
		//��{}��Χ��Ͳ�ʶ�����a
	}
	

	return 0;
}
