#include <iostream>
using namespace std;
int color[205];
int stripe[10005];
int dp[201][10001] = { 0 };
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int n;
	int m;
	int len;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> color[i];
	}
	cin >> len;
	for (int i = 1; i <= len; i++)
	{
		cin >> stripe[i];
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			int t = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));
			if (color[i] == stripe[j])
			{
				dp[i][j] = t + 1;
			}
			else
			{
				dp[i][j] = t;
			}
		}
	}
	cout << dp[m][len] << endl;
	system("pause");
	return 0;
}