#include <iostream>
#include <string.h>
using namespace std;
bool map[1005][1005];
int mover[] = { -1,1 };
int movec[] = { -1,1 };
void fill(int k, int row, int col)
{
	for (int i = 1; i <= k; i++)
	{
		map[row][i] = true;
		map[i][col] = true;
	}
	for (int i = row, j = col; i >= 1 && j >= 1; i--, j--)
	{
		map[i][j] = true;
	}
	for (int i = row, j = col; i <= k && j <= k; i++, j++)
	{
		map[i][j] = true;
	}
	for (int i = row, j = col; i <= k && j >= 1; i++, j--)
	{
		map[i][j] = true;
	}
	for (int i = row, j = col; i >= 1 && j <= k; i--, j++)
	{
		map[i][j] = true;
	}
}
int main()
{
	int n;
	int k;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		bool flag = true;
		memset(map, false, sizeof(map));
		for (int j = 1; j <= k; j++)
		{
			int t;
			cin >> t;
			if (map[t][j])
			{
				flag = false;
			}
			if (flag)
			{
				fill(k, t, j);
			}

		}
		if (flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

	}
	system("pause");
	return 0;
}