#define _CRT_SECURE_NO_WARNINGS 1
//#define MAX(x,y) x>y?x:y
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int max;
//	int a = 32, b = 22;
//	max=MAX(a, b);
//	printf("max=%d\n", max);
//	system("pause\n");
//	return 0;
//}
#define MOVE(x)\
(((x&(0xAAAAAAAA)) >> 1) + ((x&(0x55555555)) << 1))  
//0xAAAAAAAAA表示二进制序列：1010 1010 1010 1010 1010 1010 1010 1010  
//0x555555555表示二进制序列：0101 0101 0101 0101 0101 0101 0101 0101
int main()
{
	int x = 0;
	int i = 0;
	int num;
	printf("请输入一个数:\n");
	scanf("%d", &x);
	printf("此数的二进制位：\n");
	for (i = 31; i >=0; i--)
	{
		printf("%d", (x >> i) & 1);
	}
	printf("\n");
	num = MOVE(x);
	printf("奇偶交换后的二进制位：\n");
	for (i = 31; i >=0; i--)
	{
		printf("%d", (num >> i) & 1);
	}
	printf("\n");
	printf("奇偶交换后的值%d\n",num);
	system("pause\n");
	return 0;
}
//#include <stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int n = 1999, m = 2299;
//	int new;
//	int count = 0;
//	new = n^m;
//	while (new != 0)
//	{
//		if (new % 2 != 0)
//			count++;
//		new=new/2;
//	}
//	printf("%d\n", count);
//	system("pause\n");
//	return 0;
//}
