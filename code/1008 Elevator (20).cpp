#include <iostream>
using namespace std;
int main()
{
	int ans = 0;
	int n;
	cin >> n;
	int now;
	int last;
	cin >> now;
	last = now;
	ans += 5;
	ans += (now * 6);
	for (int i = 1; i < n; i++)
	{
		cin >> now;
		if (now >= last)
		{
			ans += (now - last) * 6 + 5;
		}
		else 
		{
			ans += (last - now) * 4 + 5;
		}
		last = now;
	}
	cout << ans << endl;
	system("pause");
	return 0;
}