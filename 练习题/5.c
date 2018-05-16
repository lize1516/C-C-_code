//5.替换空格,将空格替换成%20
void replace(char* arr,int length)
{
	if (arr == NULL)
		return;
	int count = 0;
	int p = length;
	char* ret = arr;

	while (*ret!='\0')
	{
		if (*ret==' ')
		count++;

		ret++;
	}
	int newsize = count * 3 + length-count;
	while (newsize>=0)
	{
		char * temp = "%20";
		if (arr[p] == ' ')
		{
			for (int i = 2; i >= 0; i--)
			{
				arr[newsize] = temp[i];
				newsize--;
			}
			p--;
		}
		arr[newsize] = arr[p];
		newsize--;
		p--;
	}
}
void test5()
{
	char str[30] = "We are happy.";
	int len = strlen(str);
	replace(str,len);
	cout << str << endl;
}

