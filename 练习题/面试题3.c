//3.
//(1)找出数组中的重复数字
int find_num(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int ret = arr[i];
		int count = 0;
		for (int m = 0; m < size; m++)
		{
			if (arr[m] == ret)
				count++;
			if (count == 2)
				return arr[m];
		}
	}
	return NULL;
}
bool Find_num(int arr[],int length,int *duplication)
{
	if (arr == NULL || length <= 0)
	{
		return false;
	}
	for (int i = 0; i < length; i++)
	{
		if (arr[i]<0 || arr[i]>length - 1)
			return false;
	}
	for (int i = 0; i < length; i++)
	{
		while (arr[i] != i)
		{
			if (arr[i] == arr[arr[i]])
			{
				*duplication = arr[i];
				return true;
			}
			int temp = arr[i];
			arr[i] = arr[temp];
			arr[temp] = temp;
		}
	}

	return false;
}
void test3()
{
	int arr[] = { 2, 3, 1, 0, 2, 5, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//cout << find_num(arr, size) << endl;;
	int ret = 0;
	Find_num(arr, size, &ret);
	cout << ret << endl;
}
