//15.���ָ�������Ķ�������1�ĸ���

int twoNumbers1(int n)          //ֻ�ܴ�����������������븺����ѭ��
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
int twoNumbers2(int n)     //��Ҫѭ��32��
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
int twoNumbers3(int n)      //�ж��ٸ�1��ѭ�����ٴ�
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