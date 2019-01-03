#include <iostream>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int stripe[10001];
	int color[201] = { 0 };
	int n, m, len;
	int t;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		color[t] = i + 1;
	}
	cin >> len;
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		cin >> t;
		if (color[t] != 0)
		{
			stripe[cnt++] = color[t];
		}
	}

	int dp[10001] = { 0 };
	for (int i = 0; i < cnt; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (stripe[i] >= stripe[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << dp[cnt - 1] << endl;
	system("pause");
	return 0;
}