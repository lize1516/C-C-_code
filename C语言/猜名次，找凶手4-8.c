#define _CRT_SECURE_NO_WARNINGS 1
////猜名次
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 1) + (a == 3)) &&\
//							((b == 2) + (e == 4))\
//							&& ((c == 1) + (d == 2))\
//							&& ((c == 5) + (d == 3))\
//							&& ((e == 4) + (a == 1)))
//		if (a!=b&&a!=b&&a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&c!=d&&c!=e&&d!=e)
//			printf("a=%d  b=%d  c=%d  d=%d  e=%d\n", a, b, c, d, e);
//						}	
//					}
//				}
//			}
//		}
//	system("pause");
//	return 0;
//	}
////找凶手
//#include<stdio.h>
//#include <stdlib.h>
//int main()
//{
//	char killer;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
//			printf("killer:%c\n", killer);
//	}
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0, k=0, j=0;
	int arr[10] = {0};
	printf("请输入十个数：\n");
	
		for (i = 1; i <= 10; i++)
		{
			scanf("%d", &arr[i]);
		}
		for (j = 1; j <= 9; j++)
		{
			for (i = 1; i <= 10 - j; i++)
			{
				if (arr[i] > arr[i + 1])
				{
					k = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = k;
				}
			}
		}
		printf("the sorted number:\n");
	for (i = 1; i <= 10; i++)
		printf("%d  ", arr[i]);
	system("pause");
	return 0;
}