��һԪ���η���
#include <stdio.h>
#include <math.h>
void main()
{
	double a, b, c, x1, x2, x, d;
	printf("������a,b,c:");
	scanf("%lf %lf %lf", &a, &b, &c);
	if (a == 0)
	{
		x = (-c) / b;
		printf("%", x);
	}
	else
	{
		d = b*b - 4 * a*c;
		if (d < 0)
		{
			printf("�޽�\n");

		}

		else
		{
			x1 = ((-b) + sqrt(d)) / (2 * a);
			x2 = ((-b) - sqrt(d)) / (2 * a);
			printf("x1=%lf, x2= %lf ", x1, x2);
		}
	}
	return 0;
}
//�����������Լ��
//#include <stdio.h>
//void main()
//{
//	int a, b, i;
//	printf("��������������");
//	scanf("%d%d", &a, &b);
//	if (a<b);
//	{
//		i = a; a = b; b = i;
//	}
//	for (i = b; i>1; i--)
//	if (a%i == 0 && b%i == 0)
//		break;
//
//	printf("\n���Լ����:%d", i);
//
//}
//���������Ӵ�С���
//#include <stdio.h>
//int main()
//{
//	int a, X, Y, Z;
//	printf("����������������\n");
//	scanf("%d%d%d", &X, &Y, &Z);
//	if (X<Y)
//	{
//		a = X; X = Y; Y = a;
//	}
//	if (Y<Z)
//	{
//		a = Z; Z = Y;
//		if (X >= a)Y = a;
//		else
//		{
//			Y = X; X = a;
//		}
//	}
//	printf("%d,%d,%d", X, Y, Z);
//	return 0;
//}
//�������ݽ���
//#include<stdio.h>
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, arr2[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }, arr3[10];
//	int i;
//	for (i = 0; i<sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		arr3[i] = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = arr3[i];
//	}
//	for (i = 0; i<sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i<sizeof(arr2) / sizeof(arr2[0]); i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}
//
//��ȡһ�������������������еļ���λ��ż��λ���ֱ��������������
//#include <stdio.h>
//int main()
//{
//	int a, i = 0;
//	int arr1[16], arr2[16];
//	scanf("%d", &a);
//	while (i<32)
//	{
//		arr1[i / 2] = a % 2;
//		a = a >> 1;
//		i++;
//		arr2[(i - 1) / 2] = a % 2;
//		a = a >> 1;
//		i++;
//	}
//	printf("�����ж���������:");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d", arr1[i]);
//	}
//	printf("\nż���ж�����������:");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d", arr2[i]);
//	}
//	return 0;
//}