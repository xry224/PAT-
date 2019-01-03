#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int num[100005];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n, greater<int>());
	int ans = 0;
	while (ans < n && num[ans] > ans + 1)
	{
		ans++;
	}
	cout << ans << endl;
	system("pause");
	return 0;
}