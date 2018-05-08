#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 10, b = 20;
	int c = a;
	a = b;
	b = c;
	printf("%d  %d\n", a, b);
	system("pause");
	return 0;
}