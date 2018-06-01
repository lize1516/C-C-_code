//最大连续子数组之和
void FindConnectMaxSum(vector<int> arr)
{
	int size = arr.size();
	vector<int> str;
	int sum=0;
	str.resize(size);

	for (int i = 0; i < size; i++)
	{
		sum = sum + arr[i];
		str[i] = sum;
		if (sum <= 0)
			sum = 0;
	}
	int max = str[0];
	for (int m = 0; m < size; m++)
	{
		if (max < str[m])
			max = str[m];
	}
	cout << max << endl;
}
int main()
{
	int n = 0;
	cin >> n;
	vector<int> arr;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	FindConnectMaxSum(arr);

	system("pause");
	return 0;
}
