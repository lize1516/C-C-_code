//4.二维数组中查找元素
bool findNum(int(* arr)[4],int row,int col,int key)
{
	int i = 0;   //行
	int m = col - 1;   //列
	while ((i>=0&&i<row)&&(m>=0&&m<col))
	{
		if (key == arr[i][m])
			return true;
		if (key > arr[i][m])
		{
			i++;
		}
		if (key < arr[i][m])
		{
			m--;
		}
	}
	return false;
}
void test4()
{
	int arr[4][4] = { { 1, 2, 8,9},\
					{ 2, 4, 9,12},\
					{ 4, 7, 10,13},\
					{ 6, 8, 11,15} };
	int row = sizeof(arr) / sizeof(arr[0]);
	int col = sizeof(arr[0]) / sizeof(arr[0][0]);
	int key = 6;
	bool ret=findNum(arr,row,col,key);
	if (ret)
	{
		cout << "true" << endl;
	}
	else
		cout << "false" << endl;
}
