#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#define MAX(x,y) (x)>(y)?(x):(y)
//int main()
//{
//	int x = 0, y = 0;
//	int max = 0;
//	scanf("%d%d", &x, &y);
//	max=MAX(x, y);
//	printf("%d\n", max);
//	system("pause");
//	return 0;
//}
////��ת����
//#include <stdio.h>
//#include<stdlib.h>
//void revolve(char arr[],int k,int sz)
//{
//	int i = 0;
//	while (k)
//	{
//		char drs = arr[0];
//		for (i = 0; i < sz - 1; i++)
//		{
//			arr[i] = arr[i + 1];
//		}
//		arr[i]=drs;
//		k--;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int k = 0;
//	int sz = sizeof(arr) / sizeof(arr[0])-1;
//	printf("��������ת�ַ�������\n");
//	scanf("%d", &k);
//	revolve(arr, k,sz);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}
//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void revolve(char arr[], int k, int sz)
{
	int i = 0;
	while (k)
	{
		char drs = arr[0];
		for (i = 0; i < sz - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[i] = drs;
		k--;
	}
}
int compare(char arr[], char arr2[],int len)
{
	int i = 1;
	while (i <= len)
	{
		int p = 0;
		revolve(arr, 1,len);
		if (strcmp(arr, arr2) == 0)
			return 1;
		/*while ((*arr == *arr2) && (*arr!='\0'))
		{
			p++;
			arr++;
			arr2++;
		}
		if (p==len)
			return 1;*/
		i++;
	}
	if (i >= len)
		return 0;
}
int main()
{
	char arr[] = "abcdef";
	char arr2[] = "befabc";
	int k = sizeof(arr) / sizeof(arr[0]) - 1;//����arrԪ�ظ���
	int ret=compare(arr, arr2,k);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
