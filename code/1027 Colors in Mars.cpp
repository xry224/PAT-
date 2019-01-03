#include <iostream>
#include <string>
using namespace std;
string toThirteen(int x)
{
	if (x == 0)
	{
		return "00";
	}
	int t = x;
	string ans = "";
	while (t > 0)
	{
		int temp = t % 13;
		if (temp <= 9)
		{
			ans += (temp + '0');
		}
		else
		{
			ans += ('A' + temp - 10);
		}
		t /= 13;
	}
	string res = "";
	for (int i = ans.length() - 1; i >= 0; i--)
	{
		res += ans[i];
	}
	if (res.length() == 1)
	{
	    res.insert(0, "0");
	}
	return res;

}
string Convert(int r, int g, int b)
{
	string ans = "#";
	ans += toThirteen(r);
	ans += toThirteen(g);
	ans += toThirteen(b);
	return ans;
}
int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	string ans = Convert(r, g, b);
	cout << ans << endl;
	system("pause");
	return 0;
}