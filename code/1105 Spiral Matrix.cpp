#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n;
	cin >> n;
	vector<int> numbers;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		numbers.push_back(t);
	}
	int upper = sqrt(n) + 1;
	int row, col;
	for (int i = upper; i >= 1; i--)
	{
		if (n % i == 0)
		{
			row = i;
			col= n / i;
			if (row < col)
			{
				int t = row;
				row = col;
				col = t;
			}
			break;
		}
	}
	int matrix[100][100];
	bool visit[100][100];
	memset(visit, false, sizeof(visit));
	sort(numbers.begin(), numbers.end(), cmp);
	int currow = 0;
	int curcol = 0;
	int orientation = 1;
	for (int i = 0; i < n; i++)
	{
		matrix[currow][curcol] = numbers[i];
		//cout << currow << " " << curcol <<" "<<orientation<< endl;
		visit[currow][curcol] = true;
		if (orientation == 1)
		{
			if (curcol + 1 == col || visit[currow][curcol + 1])
			{
				orientation++;
			}
		}
		if (orientation == 2)
		{
			if (currow + 1 == row || visit[currow + 1][curcol])
			{
				orientation++;
			}
		}
		if (orientation == 3)
		{
			if (curcol - 1 < 0 || visit[currow][curcol - 1])
			{
				orientation++;
			}
		}
		if (orientation == 4)
		{
			if (currow - 1 < 0 || visit[currow - 1][curcol])
			{
				orientation = 1;
			}
		}
		switch (orientation)
		{
		case 1:
		{
			curcol++;
			break;
		}
		case 2:
		{
			currow++;
			break;
		}
		case 3:
		{
			curcol--;
			break;
		}
		case 4:
		{
			currow--;
			break;
		}
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col - 1; j++)
		{
			cout << matrix[i][j] <<  " ";

		}
		cout << matrix[i][col - 1] << endl;
	}
	system("pause");
	return 0;
}