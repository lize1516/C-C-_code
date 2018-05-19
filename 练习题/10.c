//10.斐波那契数列
int Fib(int n)          //递归形式
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;

	return Fib(n - 1) + Fib(n-2);
}
int _Fib(int n)   //非递归形式
{
	int a = 1;
	int b = 1;
	int c = 1;
	if (n <= 0)
		return 0;
	if (n>2)
	{
		for (int i = 2; i <n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
	}
	return c;
}

void test10()
{
	int n = 5;
	//int ret=Fib(40);    //递归（效率低，费时）
	int ret = _Fib(40);   //非递归（效率高）
	cout << ret << endl;
}

//.青蛙跳台阶问题
//一次可以跳一个台阶，一次也可以跳两个台阶，n级台阶一共有多少种跳法
//一、第一次跳一个台阶，此时跳法数目等于后面剩下的n-1级台阶的跳法数 f(n-1)
//二、第一次跳2个台阶，此时跳法数目等于后面剩下的n-2级台阶的跳法数 f(n-2)
//因此总的跳法数 f(n)=f(n-1)+f(n-2);  (实际上就是斐波那契数列)
