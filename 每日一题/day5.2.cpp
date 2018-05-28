//正则表达式匹配 
bool _match(char* str, char* pattern);
bool match(char* str, char* pattern)     //递归法
{
	if (str == NULL || pattern == NULL)
		return false;

	return _match(str, pattern);
}
bool _match(char* str, char* pattern)
{
	if (*str == '\0'&&*pattern == '\0')
		return true;
	if (*str != '\0'&&*pattern == '\0')
		return false;

	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern == '.'&&*str != '\0'))
			return _match(str + 1, pattern + 2) || \
			_match(str + 1, pattern) || _match(str, pattern + 2);
		else
			return _match(str, pattern + 2);
	}
	if (*str == *pattern || (*pattern == '.'&&*str != '\0'))
		return _match(str + 1, pattern + 1);
	return false;
}
int main()
{
	char* p = "a.a";
	char*p2 = "aaa";
	char*p3 = "ab*ac*a";
	char*p4 = "aa.a";
	char*p5 = "ab*a";
	char*p6 = "";
	char*p7 = ".";
	if (match2(p2, p3))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}
