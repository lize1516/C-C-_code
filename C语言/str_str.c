#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//strcat
//int main()
//{
//	char arr[20] = "ni hao:";
//	char *p = "you are handsome!";
//	strcat(arr, p);
//	printf("%s\n",arr );
//	system("pause\n");
//	return 0;
//
//
//}
//char * str_cat(char *des, char *src)
//{
//	while (*des != '\0')
//		des++;
//	while (*des++ = *src++)
//		;
//	return des;
//}
//int main()
//{
//	char arr[40] = "abcdefg!";
//	char *b = " handsome";
//	str_cat(arr,b);
//	printf("%s\n",arr);
//	system("pause\n");
//	return 0;
//}
//char * __cdecl strcat(char * dst, const char * src)
//{
//	char * cp = dst;          //保存dst指针
//	while (*cp)
//		cp++;                 //查找dst字符串的末尾
//	while (*cp++ = *src++); //拷贝src字符串到dst后面
//	return(dst);            //返回dst字符串
//
//函数比较strcmp
//int main()
//{
//	char *a= "aeaaa";
//	char *b="abcde";
//	printf("%d\n", strcmp(a, b));
//	system("pause\n");
//	return 0;
//}
//int str_cmp(char * dest1, char *dest2)
//{
//	while (*dest1 == *dest2)
//	{
//		dest1++; dest2++;
//		if ((*dest1 == '\0') && (*dest2 == '\0'))
//			return 0;
//	}
//		if (*dest1 > *dest2)
//			return 1;
//		else if (*dest1 < *dest2)
//			return -1;
//}
//int main()
//{
//	int ret = 0;
//	char *a1 = "2345679";
//	char *a2 = "234568";
//	ret=str_cmp(a1, a2);
//	printf("%d\n", ret);
//	system("pause\n");
//	return 0;
//}
//strstr
//int main()
//{
//	char arr1[] = "ni shi shei wo bu yao ni";
//	char arr2[] = "shi";
//	printf("%s\n", strstr(arr1, arr2));
//	system("pause\n");
//	return 0;
//
//}
char *str_str(char *dest, char *src)
{
	int i = 0;
	for (i = 0; dest != '\0'; i++)
	{

	}
}
int main()
{
	char arr1[] = "ni shi shei wo bu yao ni";
	char arr2[] = "123";
	printf("%s\n", str_str(arr1, arr2));
	system("pause\n");
	return 0;
}


//const char *my_strstr(const char *str, const char *sub_str)
//{
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		int tem = i; //tem保留主串中的起始判断下标位置   
//		int j = 0;
//		while (str[i++] == sub_str[j++])
//		{
//			if (sub_str[j] == '\0')
//			{
//				return &str[tem];
//			}
//		}
//		i = tem;
//	}
//
//	return NULL;
//}
//
//int main()
//{
//	char *s = "1233345hello";
//	char *sub = "345";
//	printf("%s\n", my_strstr(s, sub));
//	system("pause\n");
//	return 0;
//}
