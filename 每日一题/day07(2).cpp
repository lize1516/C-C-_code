//小明喜欢数字，找出和为sum的一组连续的数
vector<vector<int> > FindContinuousSequence(int sum) {

	int start = 1;
	vector<int> arr;
	vector<vector<int>> ret;

	while (start<(sum/2+1))
	{
		int end = start;
		int temp = 0;

		while (end<sum)
		{
			temp = temp + end;
			if (temp == sum)
			{
				break;
			}
			else if (temp>sum)
				break;

			end += 1;
		}
		if (temp == sum)
		{
			ret.push_back(arr);
			int m = start;

			for (; m <= end;m++)
			{
				ret.back().push_back(m);
			}
		}

		start += 1;
	}
	return ret;
}
int main()
{
	int sum =3;
	FindContinuousSequence(sum);

	system("pause");
	return 0;
}
