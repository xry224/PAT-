#include <iostream>
#include <string>
using namespace std;
string inverse(string ori)
{
	string ans = "";
	for (int i = ori.length() - 1; i >= 0; i--)
	{
		ans += ori[i];
	}
	return ans;
}
string solve(int num)
{
	string res = to_string(num);
	int cnt = res.length();
	if (res[0] == '-')
	{
		cnt--;
	}
	if (cnt < 4)
	{
		return res;
	}
	else
	{
		string ans = "";
		int cur = 0;
		for (int i = res.length() - 1; i >= 0; i--)
		{
			ans += res[i];
			cur++;
			if (cur == 3)
			{
				if (i != 0 && res[i - 1] != '-')
				{
					ans += ',';
					cur -= 3;
				}
			}

		}
		return inverse(ans);
	}
}
int main()
{
	int a, b;
	string ans;
	while (cin >> a >> b)
	{
		ans = solve(a + b);
		cout << ans << endl;
	}

}