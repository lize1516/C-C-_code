//11.旋转数组的最小数字

int Min(int arr[], int len)
{
	if (arr == NULL || len <= 0)
		return NULL;
	int index1 = 0;
	int index2 = len - 1;
	int Mid = index1;
	while (arr[index1] > arr[index2])
	{
		if (index2 - index1 == 1)
		{
			Mid = index2;
			break;
		}

		Mid = (index1 + index2) / 2;
		if (arr[Mid] >= arr[index1])
			index1 = Mid;
		else if (arr[Mid] <= arr[index2])
			index2 = Mid;
	}
	return arr[Mid];
}

void test11()
{
	int arr[] = { 3, 4, 5, 1, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret=Min(arr, size);
	cout << ret << endl;

}
