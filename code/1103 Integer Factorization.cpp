#include <iostream>
#include <math.h>
using namespace std;
int ans[400] = { 0 };
int temp[400];
long long cursum = 0;
bool hasfind = false;	
long long n, k;
int p;
void dfs(long long left, int cur)
{
	if (left == 0 && cur == k)
	{
		hasfind = true;
		long long sum1 = 0;
		for (int i = 0; i < k; i++)
		{
			sum1 += temp[i];
		}
		if (cursum <= sum1)
		{
			for (int i = 0; i < k; i++)
			{
				ans[i] = temp[i];
			}
			cursum = sum1;
		}
	}
	if (left == 0 && cur != k || cur == k && left != 0)
	{
		return;
	}
	int upp = sqrt(left);
	int low = cur == 0 ? 1 : temp[cur - 1];
	for (int i = low; i <= upp; i++)
	{
		long long t = pow(i, p);
		if (left - t >= 0)
		{
			temp[cur] = i;
			dfs(left - t, cur + 1);
		}
		else
		{
			break;
		}
	}
}
int main()
{
	cin >> n >> k >> p;
	dfs(n, 0);
	if (!hasfind)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << n << " = " << ans[k - 1] << "^" << p;
		for (int i = k - 2; i >= 0; i--)
		{
			cout << " + " << ans[i] << "^" << p;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}