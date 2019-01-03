#include <iostream>
#include <set>
using namespace std;
int main()
{
	int n;
	cin >> n;
	set<int> number;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		number.insert(t);
	}
	set<int>::iterator it;
	it = number.find(1);
	if (it == number.end())
	{
		cout << 1 << endl;
		return 0;
	}
	int ans = 1;
	for (++it; it != number.end(); it++)
	{
		int t = *it;
		if (t - ans == 1)
		{
			ans = t;
		}
		else
		{
			break;
		}
	}
	cout << ++ans << endl;
	system("pause");
	return 0;
}