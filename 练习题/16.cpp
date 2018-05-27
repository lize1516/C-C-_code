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
/////////////////方法2//////////////////////////////////////////////
bool g_flag = false;
double PowerWithUnsignedExponent1(double base, unsigned int exponent);
double PowerWithUnsignedExponent2(double base, unsigned int exponent);
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
	//double result = PowerWithUnsignedExponent1(base, absExponent);
	double result = PowerWithUnsignedExponent2(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;

	return result;
}

double PowerWithUnsignedExponent1(double base, unsigned int exponent)   //先对base数求次方，然后求倒
{
	double result = 1.0;
	while (exponent--)
	{
		result = result*base;
	}
	return result;
}
double PowerWithUnsignedExponent2(double base, unsigned int exponent)  //使用递归，分奇偶次方，效率高
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = PowerWithUnsignedExponent2(base, exponent >> 1);
	result = result*result;
	if ((exponent & 0x1) == 1)
		result *= base;

	return result;
}

void test16()
{
	double num = Power2(5,-2);

	cout <<num<< endl;
}
