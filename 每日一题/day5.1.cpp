//day05.1

bool Find(int target, vector<vector<int> > array) {
	int rows = array.size();
	int cols = array[0].size();
	int row = 0;
	int col = cols-1;
	while ((row >= 0 && row < rows) && (col >= 0 && col < cols))
	{
		if (array[row][col] == target)
			return true;
		if (target>array[row][col])
			row++;

		else if (target < array[row][col])
			col--;
	}
	return false;
}
int main()
{
	int n = 5;
	int str[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	vector<int> arr1;
	vector<vector<int>> arr;
	for (int i = 0; i < 3; i++)
	{
		arr.push_back(arr1);
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i].push_back(str[i][j]);
		}
	}
	

	if (Find(n, arr))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}
