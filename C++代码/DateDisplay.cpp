#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<iomanip>
using namespace std;

//1990��1��1��������һ
int nyear(int year)   //�ж������껹��ƽ��
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 366;
	else
		return 365;
}

int nmonth(int y, int m)        //������ݺ��·��ж�����һ���µ�����
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return 31;
	else if (nyear(y) == 366 && m == 2)
		return 29;
	else if (nyear(y) == 365 && m == 2)
		return 28;
	else
		return 30;
}

int GetDays(int year, int month)  //������ݺ��·�ȷ����1990.1.1�ܹ�������
{
	int i = 0;
	int sum = 0;
	if (year>1990)
	for (i = 1990; i < year; i++)
		sum += nyear(i);
	if (month>1)
	for (i = 1; i < month; i++)
	{
		sum += nmonth(year, i);
	}

	return sum;
}
void DisplayOnemonth()
{
	int i, j, year, month, day, sum, daycount, cases = 1;
	cout << "������-��-�£�";
	while (cin >> year >> month)
	{
		sum = GetDays(year, month);
		day = (sum + 1) % 7;  //�ó�һ���µ�һ��ǰҪ�ռ���
		daycount = nmonth(year, month);   //�����һ���µ�����
		cout << "  " << year << "��" << month << "��" << endl;
		cout << "  ��  һ  ��  ��  ��  ��  �� " << endl;
		for (i = 0; i < day; i++)
			cout << setw(4) << " ";
		for (i = 1, j = day + i; i <= daycount; i++, j++)
		{
			cout << setw(4) << i;
			if (j % 7 == 0)
				cout << endl;
		}
		cout << endl;
	}
}
void DisplayOneyear()
{
	int i = 0, year;
	int sum1, sum2, sum3;
	int day1, day2, day3;
	int daycount1, daycount2, daycount3;

	cout << "�������꣺";
	while (cin >> year)
	{
		for (i = 1; i < 12; i += 3)
		{
			int j = 0, m = 1;   //���ƴ�ӡ���ڵĵ�һ��
			int n = 0, q = 1;   //���ƴ�ӡ���ڵĵڶ���
			int k = 0, d = 1;   //���ƴ�ӡ���ڵĵ�����
			sum1 = GetDays(year, i);          //��1990.1.1��������
			sum2 = GetDays(year, i + 1);
			sum3 = GetDays(year, i + 2);
			day1 = (sum1 + 1) % 7;            //�ó�һ���µ�һ��ǰҪ�ռ���
			day2 = (sum2 + 1) % 7;
			day3 = (sum3 + 1) % 7;
			daycount1 = nmonth(year, i);       //һ���µ�������
			daycount2 = nmonth(year, i + 1);
			daycount3 = nmonth(year, i + 2);
			cout << setw(10) << " " << year << "��" << setw(2) << i << "��" << setw(21) << " " << "  " << year << "��" << setw(2) << i + 1 << "��" << setw(21) << " " << "  " << year << "��" << setw(2) << i + 2 << "��" << endl;
			cout << "  ��  һ  ��  ��  ��  ��  �� " << setw(4) << " " << "  ��  һ  ��  ��  ��  ��  �� " << setw(4) << " " << "  ��  һ  ��  ��  ��  ��  �� " << endl;
			for (j = 0; j < day1; j++)    //1.��һ��ѭ�����·����һ�еĿո���
				cout << setw(4) << " ";
			for (j = day1 + m; m <= daycount1+1; m++, j++)      //1.����ѭ����һ��
			{//1
				if (m>daycount1)       //���ӡһ�пո�
				{
					for (int a = 0; a < 7; a++)
						cout << setw(4) << " ";
					j = 7;
				}
				else
				    cout << setw(4) << m;

				if (m == daycount1)        //1.���һ��Ҫ�Ŀո���
				{
					for (int a = 0; a <((7 - (m + day1) % 7)%7); a++)
						cout << setw(4) << " ";
					j = 7;
				}
				if (j % 7 == 0)
				{
					cout << setw(5) << " ";      //1.����һ��������ľ���
					//#//////////////////////////////////////////--2
					if (n == 0)     //2.��Ϊ�µĵ�һ��ʱ
					{
						for (n = 0; n < day2; n++)       //2.�ڶ���ѭ�����·����һ�еĿո���     
							cout << setw(4) << " ";
					}
					for (n = day2 + q; q <= daycount2+2; q++, n++)       //2.�ڶ���ѭ��
					{//2
						if (q>daycount2)      //���ӡһ�пո�
						{
							for (int a = 0; a < 7;a++)
								cout << setw(4) << " ";
							n = 7;
						}
						else
						    cout << setw(4) << q;
						if (q == daycount2)         //2.���һ��Ҫ�Ŀո���
						{
							for (int a = 0; a <((7 - (q + day2) % 7)%7); a++)
								cout << setw(4) << " ";
							n = 7;               //2.ʹ����Խ�����һ��ѭ��
						}
	
						if (n % 7 == 0)
						{
							q++;
							n++;
							cout << setw(4) << " "; //2.����һ��������ľ���
							//#//////////////////////////////////////--3
							if (k == 0)           //3.�·ݵĵ�һ��
							{
								for (k = 0; k< day3; k++)      //3.�·ݵĵ�һ��Ҫ��ӡ�Ŀո���
									cout << setw(4) << " ";
							}
							for (k = day3 + d; d <= daycount3+1; d++, k++)   //3.��ӡ�·ݵ�����
							{//3
								if (d>daycount3)
								{
									for (int a = 0; a < 7;a++)
										cout << setw(4) << " "; //���ӡһ�пո�
									k = 7;
									m++;
									j++;
								}
								else
								    cout << setw(4) << d;
								if (d == daycount3)
								{
									k++;
									d++;
									cout << endl;
									break;
								}
								if (k % 7 == 0)
								{
									k++;
									d++;

									cout << endl;
									break;
								}
							}//3
							break;
						}
					}//2
				}
			}//1
          /////////////////////
		}
	}
}
int main()
{
	//DisplayOnemonth();
	DisplayOneyear();

	system("pause");
	return 0;
}
