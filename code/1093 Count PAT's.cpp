#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;
int main()
{
	string str;
	cin >> str;
	int cnt = 0;
	vector<int> p(str.length());
	vector<int> t(str.length());
	for (int i = 0; i < str.length() - 2; i++)
	{
		if (str[i] == 'P')
		{
			p[i + 1] = p[i] + 1;
		}
		else
		{
			p[i + 1] = p[i];
		}
	}
	for (int i = str.length() - 1; i >= 1; i--)
	{
		if (str[i] == 'T')
		{
			t[i - 1] = t[i] + 1;
		}
		else
		{
			t[i - 1] = t[i];
		}
	}
	long long ans = 0;
	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == 'A')
		{
			ans = (ans + (p[i] * t[i])) % MOD;
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}