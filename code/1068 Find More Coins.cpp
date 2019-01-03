#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int coins[10005];
int dp[10005];
bool choice[10005][110];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, target;
	cin >> n >> target;
	int t;
	for (int i = 1; i <= n; i++)
	{
		cin >> coins[i];
	}
	for (int i = 0; i <= target; i++)
	{
		dp[i] = INT_MIN;
	}
	sort(coins + 1, coins + 1 + n, cmp);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = target; j >= coins[i]; j--)
		{
			//cout << dp[j] << " ";
			dp[j] = max(dp[j], dp[j - coins[i]] + coins[i]);
			if (dp[j] == dp[j - coins[i]] + coins[i])
			{
				choice[i][j] = true;
			}
			//cout << dp[j] << endl;
		}
		//cout << endl;
	}
	if (dp[target] != target)
	{
		cout << "No Solution" << endl;
	}
	else
	{
		vector<int> arr;
		int full = target;
		int total = n;
		while (full > 0)
		{
			if (choice[total][full])
			{
				arr.push_back(coins[total]);
				full -= coins[total];
			}
			total--;
		}
		for (int i = 0; i < arr.size(); i++)
		{
			if (i != 0)
			{
				cout << " ";
			}
			cout << arr[i];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}