//16.数值的整数次方
double Power(double base, int exponent)    //当exponent输入负数会出错
{
	double num = 1;
	while (exponent--)
	{
		num = num*base;
	}
	return num;
}
///////////////////////////////////////////////////////////////
bool g_flag = false;
double PowerWithUnsignedExponent(double base, unsigned int exponent);
double Power2(double base, int exponent)
{
	g_flag = false;

	if (base == 0.0 && exponent < 0)
	{
		g_flag = true;
		return 0;
	}

	unsigned int absExponent=(unsigned int)(exponent);
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);
	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;

	return result;
}
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	double result = 1.0;
	while (exponent--)
	{
		result = result*base;
	}
	return result;
}
//////////////////////////////////////////////////////////////
void test16()
{
	double num = Power2(5,-2);

	cout <<num<< endl;
}