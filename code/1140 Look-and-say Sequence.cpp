#include <iostream>
#include <string>
using namespace std;
int main()
{
	int d, n;
	cin >> d >> n;
	string ans = to_string(d);
	for (int i = 1; i < n; i++)
	{
		string t = "";
		for (int j = 0; j < ans.length(); j++)
		{
			char now = ans[j];
			int k;
			for (k = j; k < ans.length(); k++)
			{
				if (ans[k] != now)
				{
					break;
				}
			}
			int length = k - j;
			t += now;
			t += to_string(length);
			j = k - 1;
		}
		ans = t;
		//cout << ans << endl;
	}
	//ans = ans.substr(1);
	cout << ans << endl;
	system("pause");
	return 0;
}