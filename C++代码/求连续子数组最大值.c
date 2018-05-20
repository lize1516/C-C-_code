#include<iostream>
#include<vector>
using namespace std;


int GetMaxSumLength1(vector<int> arr)                   //方法一
{
	if (arr.size() == 0)
		return 0;
	vector<int> index(arr.size(),0);
	for (size_t i = 0; i < arr.size(); i++)
	{
		index[i] = arr[i];
		int temp = index[i];
		for (int j = i - 1; j >= 0; j--)
		{
			temp += arr[j];
			if (temp>index[i])
				index[i] = temp;
		}
	}
	int result = arr[0];
	for (auto & v : index)
	{
		cout << v << " ";
		if (v > result)
			result = v;
	}
	return result;
}
int GetMaxSumLength2(vector<int> arr)              //方法二
{
	if (arr.size() == 0)
		return 0;
	vector<int> index(arr.size(), 0);
	int sum = 0;
	for (size_t i = 0; i < arr.size(); i++)
	{
		sum+= arr[i];
		index[i] = sum;

		if (sum < 0)
			sum = 0;
	}
	int result = index[0];
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << index[i] << " ";
		if (result < index[i])
			result = index[i];
	}
	return result;
}
int main()
{
	int n = 0;
	int array[] = {2, -8, -1,4, -2, 4, 6 };
	vector<int> arr;
	//cin >> n;
	n = sizeof(array)/sizeof(array[0]);
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = array[i];
	}
	int ret1 = GetMaxSumLength1(arr);
	cout << endl;
	cout << ret1 << endl;

	int ret = GetMaxSumLength2(arr);
	cout << endl;
	cout << ret << endl;
	system("pause");
	return 0;
}