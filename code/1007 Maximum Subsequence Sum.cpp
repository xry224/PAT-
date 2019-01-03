#include <iostream>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int n;
	int num[10001];
	cin >> n;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		if (num[i] >= 0)
		{
			flag = true;
		}
	}
	int first, last;
	int dp[10001];
	dp[0] = num[0];
	int ans = dp[0];
	first = last = 0;
	int cur1, cur2;
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + num[i], num[i]);
		if (dp[i] == num[i])
		{
			cur1 = cur2 = i;
		}
		else
		{
			cur2 = i;
		}
		if (dp[i] > ans)
		{
			ans = dp[i];
			first = cur1;
			last = cur2;
		}
	}
	if (!flag)
	{
		cout << 0 << " " << num[0] << " " << num[n - 1] << endl;
	}
	else
	{
		cout << ans << " " << num[first] << " " << num[last] << endl;
	}

	system("pause");
	return 0;
}