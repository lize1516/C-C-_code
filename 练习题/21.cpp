//21.调整数组顺序使使奇数位于偶数前面
void ChangeOrder(int * arr,int size)
{
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		while (left < right)
		{
			if (arr[left] % 2 == 0)
				break;
			left++;
		}
		while (left < right)
		{
			if (arr[right] % 2 == 1)
				break;
			right--;
		}
		if (left == right)
			return;
		else
		{
			int ret = arr[left];
			arr[left] = arr[right];
			arr[right] = ret;
		}
	}

}
void test21()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	ChangeOrder(arr,size);

}
