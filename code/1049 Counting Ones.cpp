#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int factor = 1;
	int low;
	int high;
	int ans = 0;
	int cur;
	while (n / factor > 0)
	{
		cur = (n/factor) % 10;
		high = n / (factor * 10);
		low = n - (n / factor)*factor;
		if (cur == 0)
		{
			ans += high * factor;
		}
		else if (cur == 1)
		{
			ans += low + 1 + high * factor;
		}
		else
		{
			ans += (high + 1)*factor;
		}
		factor *= 10;
	}
	cout << ans << endl;
	system("pause");
	return 0;
}