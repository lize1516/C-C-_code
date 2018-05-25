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