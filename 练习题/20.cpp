//20.表示数值的字符串

bool IsNumber1(char** str)
{
	char* before = *str;
	while (**str != '\0'&&**str >= '0'&&**str <= '9')
		++(*str);

	return *str > before;      //如果出现数字字符返回true，否则返回false
}
bool JudgeSymbol_1(char** str)
{
	if (**str == '-' || **str == '+')   //如果有符号，向后移一位
		++(*str);               
	return IsNumber1(str);    //如果有'+'或'-',符号后一定要为数字;如果无'+'或'-'则判断数字
}
bool JudgeNumberStr1(char* str)
{
	if (str == NULL)
		return false;

	bool number = JudgeSymbol_1(&str);
	if (*str == '.')
	{
		++str;
		number = IsNumber1(&str) || number;      //".222"表示0.222    "222."表示"222.0"
	}
	if (*str == 'e' || *str == 'E')
	{
		++str;
		number = number&&JudgeSymbol_1(&str);
	}

	return number&&*str == '\0';
}
void test20()
{
	char* p1 = "+100";
	char*p2 = "5e2";
	char*p3 = "3.1416";
	char*p4 = "-1E-16";

	char*p5 = "12e";
	char*p6 = "la3.14";
	char*p7 = "1.2.3";
	char*p8 = "12e+5.4";

	if (JudgeNumberStr1(p1))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	if (JudgeNumberStr1(p2))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	if (JudgeNumberStr1(p7))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	if (JudgeNumberStr1(p8))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}
