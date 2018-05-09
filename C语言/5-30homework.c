#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int find_diffchar(char drs[],int len)
//{
//	int i = 0,j=0;
//	int arr2[20] = { 0 };
//	for (i = 0; i < len; i++)
//	{
//		int k = 0;
//		for (j = 0; j < len; j++)
//		{
//			if (drs[i] == drs[j])
//				k++;
//			arr2[i] = k;
//		}
//	}
//	for (i = 0; i < len; i++)
//	{
//		if (arr2[i] == 1)
//			return i;
//	}
//	return -1;
//}
//int main()
//{
//	char arr[] = "aabcdbceefft";
//	int len = strlen(arr);
//	int ret = 0;
//	ret = find_diffchar(arr, len);
//	if (ret == -1)
//		printf("没找到");
//	else
//	    printf("第一个只出现一次的字母是：%c\n", arr[ret]);
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
int find(char *str)
{
	char*tmp = str;
	int arr2[256] = { 0 };
	while (*tmp)
	{
		arr2[*tmp]++;
		tmp++;
	}
	tmp = str;
	while (*tmp)
	{
		if (arr2[*tmp] == 1)
			return *tmp;
		tmp++;
	}
	return -1;
}
int main()
{
	char arr[] = "abcdeffgabcdeghhuu";
	char ret=find(arr);
	if (ret == -1)
		printf("没找到\n");
	else
	printf("只出现一次的第一个字母是：%c\n", ret);
	system("pause");
	return 0;
}

