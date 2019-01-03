#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	long long n, p;
	ios::sync_with_stdio(false);
	cin >> n >> p;
	vector<long long> seq;
	for (int i = 0; i < n; i++)
	{
		long long t;
		cin >> t;
		seq.push_back(t);
	}
	sort(seq.begin(), seq.end());
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		long long maxp = p * seq[i];
		if (maxp >= seq[n - 1])
		{
			if (ans < n - i)
			{
				ans = n - i;
			}
			break;
		}

		int down = 1, up = n - 1;
		while (down < up)
		{
			int mid = (down + up) / 2;
			if (seq[mid] > maxp)
			{
				up = mid - 1;
			}
			else 
			{
				down = mid + 1;
			}
		}
		if (down - i > ans)
		{
			ans = down - i;
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}