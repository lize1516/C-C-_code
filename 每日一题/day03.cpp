//一组数，如果某个数出现的次数大于数字个数的一半，输出这个数，{1,2,3,2,2,2,5,4,2}; 输出2；否则输出0
int MoreThanHalfNum_Solution(vector<int> numbers) {
	int size = numbers.size();
	int i = 0;
	int _max = numbers[0];
	int _min = numbers[0];
	for (i = 0; i < size; i++)
	{
		if (_max < numbers[i])
			_max = numbers[i];
		if (_min>numbers[i])
			_min = numbers[i];
	}

	int num_size = _max - _min+1;
	vector<int> v2;
	v2.resize(num_size, 0);
	for (i = 0; i < size; i++)
	{
		v2[numbers[i]-_min]++;
	}
	int ret = 0;
	int max = v2[ret];
	for (i = 0; i <num_size; i++)
	{
		if (v2[i]>max)
		{
			max = v2[i];
			ret = i + _min;
		}
	}
	if (max > (size / 2))
		return ret;
	else
	return 0;
}

int main()
{
	int arr[] = {1,2,3,2,2,2,5,4,2};
	//int arr[] = {1,2,2,3,4,5,4,2};
	int size = sizeof(arr) / sizeof(arr[0]);
	vector<int> v1;
	for (int i = 0; i < size; i++)
	{
		v1.push_back(arr[i]);
	}
	int ret=MoreThanHalfNum_Solution(v1);

	cout << ret << endl;
	system("pause");
	return 0;
}


//查找一个字符串中第一个出现一次的字符，未找到输出-1
#include<assert.h>
#include<string>
void find_first(const char* str)
{
	assert(str);
	const char* ret = str;
	int arr[255] = {0};
	while (*str != '\0')
	{
		arr[*str]++;
		str++;
	}
	while (*ret != '\0')
	{
		if (arr[*ret] == 1)
		{
			cout << *ret << endl;
			return;
		}
		ret++;
	}
	cout << -1 << endl;
}
int main()
{
	string s;
	while (1)
	{
		s.clear();
		getline(cin, s);
		find_first(s.c_str());
	}

	system("pause");
	return 0;
}
