//#define _CRT_SECURE_NO_WARNINGS 1
////1.使用main函数的参数，实现一个整数计算器，程序可以接受三个参数
//#include<stdio.h>
//#include<stdlib.h>
//int add(int a, int b)
//{
//	return (a + b);
//}
//int sub(int a, int b)
//{
//	return (a - b);
//}
//int mul(int a, int b)
//{
//	return (a*b);
//}
//int Div(int a, int b)
//{
//	return (a / b);
//}
//int main(int argc,char *argv[],char*envp[])
//{
//	int ret = 0;
//	if (argc != 4)
//	{
//		printf("参数错误\n");
//		return 0;
//	}
//	switch (*(argv[1] + 1))
//	{
//	case 'a':
//		ret = add(atoi(argv[2]), atoi(argv[3]));
//		break;
//	case 's':
//		ret = sub(atoi(argv[2]), atoi(argv[3]));
//		break;
//	case 'm':
//		ret = mul(atoi(argv[2]), atoi(argv[3]));
//		break;
//	case 'd':
//		ret = Div(atoi(argv[2]), atoi(argv[3]));
//		break;
//	}
//	printf("ret = %d\n", ret);
//	return 0;
//}
//
//
//////2.写冒泡排序可以排序多个字符串。
////#include<stdio.h>
////#include<string.h>
////void sort(char (*str)[15])
////{
////	int i = 0;
////	int j = 0;
////	char tmp[15];
////	char*t = tmp;
////	for (i = 0; i < 4-1;i++)
////	for (j = 0; j < 4 - i - 1; j++)
////	{
////		if (strcmp(str[j], str[j + 1])>0)
////		{
////			strcpy(t, str[j]);
////			strcpy(str[j], str[j + 1]);
////			strcpy(str[j + 1], t);
////		}
////	}
////}
////int main()
////{
////	int i = 0;
////	char arr[4][15] = { "kabcdef", "cbvcfgs", "abhsxcd","basdz" };
////	char(*p)[15] = { 0 };
////	p = arr;
////	sort(p);
////	printf("the sorted char:\n");
////	for (i = 0; i < 4; i++)
////		printf("%s ", arr[i]);
////	system("pause");
////	return 0;
////}
//////数字排序冒泡法
//////#include<stdio.h>
//////void sort(int arr[],int sz)
//////{
//////	int i = 0,k=0,ret=0;
//////	for (i = 0; i < sz - 1; i++)
//////	{
//////		for (k = 0; k < sz - i - 1; k++)
//////		{
//////			if (arr[k]>arr[k + 1])
//////			{
//////				ret = arr[k];
//////				arr[k] = arr[k + 1];
//////				arr[k + 1] = ret;
//////			}
//////		}
//////	}
//////}
//////void output(int arr[], int sz)
//////{
//////	printf("the sorted numder:\n");
//////	int i = 0;
//////	for (i = 0; i < sz; i++)
//////		printf("%d ", arr[i]);
//////}
//////int main()
//////{
//////	int arr[] = { 9, 7, 5, 6, 8, 4, 3, 2, 1 };
//////	int sz = sizeof(arr) / sizeof(arr[0]);
//////	sort(arr,sz);
//////	output(arr,sz);
//////	system("pause");
//////	return 0;
//////}
////
//////3.使用可变参数实现一个函数求任意多个参数的平均值
////#include<stdio.h>
////#include<stdlib.h>
////#include<stdarg.h>
////int average(int n, ...)
////{
////	int i = 0;
////	int sum = 0;
////	va_list arg;
////	va_start(arg, n);
////	for (i = 0; i < n; i++)
////	{
////		sum = sum + va_arg(arg, int);
////	}
////	va_end(arg);
////	return sum/n;
////}
////int main()
////{
////	int ret=average(3, 1, 2, 3);
////	printf("ret = %d\n", ret);
////	ret = average(5, 2, 3, 4, 5, 6);
////	printf("ret = %d\n", ret);
////	system("pause");
////	return 0;
////}
//////4.使用可变参数实现一个函数求任意多个参数中的最大值。
////#include<stdio.h>
////#include<stdarg.h>
////int Max(int n, ...)
////{
////	int i = 0;
////	va_list arg;
////	va_start(arg, n);
////	int max = va_arg(arg, int);
////	for (i = 1; i < n; i++)
////	{
////		int tmp=va_arg(arg, int);
////		if (max < tmp)
////			max = tmp;
////	}
////	va_end(arg);
////	return max;
////}
////int main()
////{
////	int max = Max(3,-3,-1,-5);
////	printf("max = %d\n", max);
////	max = Max(5, 2, 3, 6, 5, 7);
////	printf("max = %d\n", max);
////	system("pause");
////	return 0;
////}
//////5.思考printf函数的模拟实现。



int main()
{
	char *a = &'d';
	char arr[10];
	strcpy(arr,a);
	return 0;
}