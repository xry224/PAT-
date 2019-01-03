#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
int main()
{
	int n1, n2;
	int a;
	double b;
	double num1[1001], num2[1001];
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		cin >> a >> b;
		num1[a] += b;
	}
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		cin >> a >> b;
		num2[a] += b;
	}
	double ans[2005];
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < 1001; j++)
		{
			ans[i + j] += num1[i] * num2[j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < 2005; i++)
	{
		if (ans[i] != 0)
		{
			cnt++;
		}
	}
	cout << cnt;
	for (int i = 2004; i >= 0; i--)
	{
		if (ans[i] != 0)
		{
			cout << fixed << setprecision(1) << " " << i << " " << ans[i];
		}
	}
	cout << endl;
	system("pause");
	return 0;
}