#include <stdio.h>
#include <string.h>

//���鰸��1�� ð������
void bubble_sort(int arr[],int len) //���鴫�ݵ�ʱ�򣬴��ݵ���������׵�ַ
{
	
	int temp;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}	
}

int main()
{
	// 	//һά���鶨������ַ�ʽ1 2
	// 	int arr[10] = { 1,2,3,4,5,6 };//ʣ���λ���Զ�������0��
	// 	int arr2[] = { 10,9,8,7 };
	// 
	// 	char ch1[] = { 'b','i','t' };//���������Զ���3���ַ� b i t������\0����������Ա�����ڹ涨ֵҲ���Զ����\0
	// 	char ch2[] = "bit"; //�����������ĸ��ַ� b i t \0
	// 	printf("%d\n", strlen(ch1)); //���Ȳ�ȷ����Ϊ���ֵ����Ϊû�ҵ�\0
	// 	printf("%d\n", strlen(ch2)); //����һ��
	// 
	// 
	// 	char ch3[5] = "bit";//��������������ַ� b i t \0 \0
	// 	char ch4[4] = "bitk";
	// 	char ch5[4] = {'a','b','c','d'};
	// 
	// 	printf("%d\n", arr2); //��ӡ��������
	// 	printf("%s\n", ch1); //��ӡ���������Ҳ���������
	// 	printf("%s\n", ch4); //��ӡ���������������
	// 	printf("%s\n", ch5); //��ӡ�������ͬ�����������

	// 	//1.1 һά����ķ���
	// 	char str[] = "123456";	
	// 	int len = sizeof(str) / sizeof(str[0]);
	// 	for (int i = 0; i < len; i++)
	// 	{				
	// 		printf("%c\t", str[i]);
	// 	}

	// 	//1.1.2 һά����ʹ��ָ�����
	// 	char str[] = "12345679";
	// 	char* p = str;
	// 	int len = sizeof(str) / sizeof(str[0]);
	// 	printf("the length is %d\n", len);//˵���Զ�\0ռλ�����ǲ���ʾ���ַ�����������
	// 	
	// 	printf("all the data in str as shown below:\n");
	// 	for (int i = 0; i < len; i++)
	// 	{
	// 		printf("%c\t", *(p + i));
	// 	}
	// 	printf("\n");
	   	 
	// 	//1.2  ����������ʽ
	// 	int i = 360;
	// 	printf("%-6d\n", i);
	// 
	// 	char str1[] = "kkins055074";
	// 	printf("%-20.5s\n", str1);//�����20.5��ʾ�����20λ�����ַ�����ȡ5λ
	// 
	// 	char str2[] = "3698";
	// 	printf("%+20s\n", str2);//�Ҷ���
	// 
	// 	double f = -3.141592658;
	// 	double f2 = 3.1;
	// 
	// 	printf("% .6f\n", f); //�ո����Ǹ�����Ϊ����ʾ"-"������ʾ�ո�
	// 	printf("% .6f\n", f2); //С��������Զ�����0
	   
	// 	// 2. ��ά����
	// 	//2.1.1 ��ʼ����ʽ 1
	// 	int arr[3][4] = { 1,2,3,4,5,6,7,8,9 }; //˳��ֵ���Զ����0
	// 	//2.1.2 ��ʼ����ʽ 2
	// 	int arr2[3][4] = { {1,2,3},{1,2} };//����ÿ�и�ֵ��һ�и�ֵ����ȫ�Զ����0

// 		//2.2 ��ά�����ʹ��
// 		//2.2.1 ͨ��ָ����ö�ά�����Ԫ�أ�˵����ά�������ڴ�����������
// 	int arr[][4] = { {1,2,3},{4,5 }, { 6 } };
// 	int* p = arr;
// 	for (int i = 0; i < 3; i++)
// 	{
// 		for (int j = 0; j < 4; j++)
// 		{
// 			printf("%d\t", *(p + i * 4 + j));
// 		}
// 		printf("\n");
// 	}
// 	//2.2.2 ֱ�ӵ�������Ԫ��
// 	for (int i = 0; i < 3; i++)
// 	{
// 		for (int j = 0; j < 4; j++)
// 		{
// 			printf("%d\t", arr[i][j]);
// 		}
// 		printf("\n");
// 	}

	//3. ������Ϊ��������
	//��������������Ԫ�صĵ�ַ
	//�������������⣺1.sizeof(������)����ʱ�ĵ���������ʾ�����������飻2. &����������ʱ����������ʾ������������-ȡ��������������ĵ�ַ
	int arr[] = { 9,8,7,6,5,4,3,2,1,10 };
	//����Ϊ����ð������
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("the length is %d\n", len);
	bubble_sort(arr,len);//���鴫�ε�ʱ�򣬴��ݵ�������ĵ�ַ
	
	for (int i = 0; i < len; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	
	printf("%p\n", &arr);
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);//��������������Ľ������ͬ

	printf("%p\n", &arr+1);//������������������������ͬ����Ϊ��������������
	printf("%p\n", arr+1);
	printf("%p\n", &arr[0]+1);



	return 0;
}