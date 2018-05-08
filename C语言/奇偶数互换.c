#define _CRT_SECURE_NO_WARNINGS 1
//调整数组使奇数全部都位于偶数前面。
#include<stdio.h>
#include<stdlib.h>
void exchange(int *arr, int sz)
{
	int *left =arr;
	int *right = arr + sz - 1;
	while (left < right)
	{
		while ((*left) % 2 == 1)
		{
				left++;
		}
		while ((*right) % 2 == 0)
		{
				right--;
		}
		if (left < right)
		{
			int ret = *left;
			*left = *right;
			*right = ret;
		}
		left++;
		right--;
	}
}
int main()
{
	int i = 0;
	int arr[] = { 1,22,12,4,5,6,7,8,9};
	int sz = sizeof(arr) / sizeof(arr[0]);
	exchange(arr,sz);////完成要求的函数，功能“将奇数转换到前面偶数放到后面”
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
#include<stdio.h>
#include<stdlib.h>
void find(int arr[3][3], int *px, int *py, int key)
{
	int row = 0;
	int col = *py - 1;
	while ((row<=*px-1)&&(col>=0))
	{
	   if (arr[row][col]>key)
		{
			col--;
		}
	   else if (arr[row][col] < key)
	   {
		   row++;
	   }
		else if (arr[row][col] == key)
		{
			*px = row+1;
			*py = col+1;
			return;
		}
	}
	if ((col<0) || (row>*py-1))
	{
		*px = -1;
		*py = -1;
	}
}
int main()
{
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int x = 3;
	int y = 3;
	int key = 8;
	find(arr, &x, &y, key);
	printf("%d  %d \n", x, y);
	system("pause");
	return 0;
}