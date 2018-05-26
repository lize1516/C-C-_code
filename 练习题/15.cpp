//15.输出指定整数的二进制中1的个数

int twoNumbers1(int n)          //只能处理正整数，如果输入负数死循环
{
	int count = 0;
	while (n != 0)
	{
		if ((n & 1) == 1)
			count++;

		n = n >> 1;
	}
	return count;
}
int twoNumbers2(int n)     //需要循环32次
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n&flag)
			count++;

		flag=flag << 1;
	}
	return count;
}
int twoNumbers3(int n)      //有多少个1就循环多少次
{
	int count = 0;
	while (n)
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}
void test15()
{
	int n = -1;
	//int count=twoNumbers1(n);
	int count2 = twoNumbers2(n);
	int count3 = twoNumbers3(n);

	//cout << count << endl;
	cout << count2 << endl;
	cout << count3 << endl;
}