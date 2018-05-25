//将字符串转为整数
////////////////////////1//////////////////////////
int my_atoi_1(string str)
{
	if (str.empty())
		return 0;
	string arr = str;
	int flag = 1;
	long long num = 0;
	int index = 0;
	int len = arr.size();
	while (arr[index]!=0)
	{
		if (((arr[index]) >= '0' && (arr[index]) <= '9'))
			break;
		else if (arr[index] == '-' || arr[index] == '+')
		{
			if (arr[index] == '-')
			{
				flag = -1;
				index++;
				break;
			}
		}
		index++;
	}
	if (arr[index] == 0)
		return 0;
	while (arr[index]!='\0')
	{
		if (((arr[index]) <= '0' || (arr[index]) >= '9'))
		{
			return 0;
		}
			num = num * 10 + (arr[index]) - '0';
			index++;
	}
	num = num*flag;
	if (((flag == 1) && (num > INT_MAX)) || ((flag == -1) && (num <INT_MIN)))
	{
		return 0;
	}

	return (int)num;
}
////////////////////////2//////////////////
int my_atoi_2(string str)     // （方法二）
{
	int len = str.length();
	int index = 0;
	int flag = 1;
	long long num = 0;

	while (str[index]==' ')
	{
		index++;
	}
	if (str[index] == '-')
	{
		flag = -1;
		index++;
	}
	while (str[index] != '\0')
	{
		if (str[index]<'0'||str[index]>'9')
			return 0;

		num = num * 10 + str[index] - '0';
		index++;
	}
	num = num*flag;
	//判断溢出
	if (((flag == 1) && num > INT_MAX) || ((flag == -1) && num < INT_MIN))
		return 0;

	return (int)num;
}
int main()
{
	//char* p = "234hkl";
	//int ret = atoi(p);

	string s("-11gjh ");
	int ret = my_atoi_2(s);
	cout << ret << endl;
	system("pause");
	return 0;
}
#endif

#if 0
//旋转字符串
#include<string>
string rotateString(string A, int n, int p) {
	char ch;
	int len = A.size();
	for (int i = 0; i <= p; i++)
	{
		ch = A[0];
		for (int m = 0; m < len; m++)
		{
			A[m] = A[m + 1];
		}
		A[len - 1] = ch;
	}
	return A;
}
int main()
{
	string arr("ABCDEFGH");
	string A=rotateString(arr, 8, 4);

	cout << A << endl;
	system("pause");
	return 0;
}

#endif
