//19.正则表达式匹配
bool _match(char* str, char* pattern)
{
	if (*str =='\0'&&*pattern == '\0')
		return true;
	if (*str != '\0'&&*pattern == '\0')
		return false;

	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern == '.'&&*str != '\0'))
			return _match(str + 1, pattern + 2) || _match(str + 1, pattern) || _match(str, pattern + 2);
		//   str当前字符与 'pattern*'抵消       pattern符合多次str的字符     当'pattern*’表示为0满足条件 
		else
			return _match(str, pattern + 2);     //忽略 字符'pattern*'；
	}
	if (*str == *pattern || (*pattern == '.'&&*str != '\0'))
		return _match(str + 1, pattern + 1);

	return false;
}
bool match(char* str, char* pattern)
{
	if (str == NULL||pattern == NULL)
		return false;

	return _match(str, pattern);
}
void test19()
{
	char*str = "aaa";
	char*p1 = "a.a";
	char*p2 = "ab*ac*a";
	char*p3 = "aa.a";
	char*p4 = "ab*a";
	if (match(str, p4))
		cout << "true" << endl;
	else
		cout << "false"<<endl;
}
