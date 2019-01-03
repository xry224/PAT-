#include <iostream>
#include <string.h>
using namespace std;
int number[10005];
int record[100001];
int main()
{
	int n;
	memset(number, 0, sizeof(number));
	cin >> n;
	int t;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		record[cnt++] = t;
		number[t]++;
	}
	int i;
	int ans = -1;
	for (i = 0; i < cnt; i++)
	{
		if (number[record[i]] == 1)
		{
			ans = record[i];
			break;
		}
	}
	if (ans == -1)
	{
		cout << "None" << endl;
	}
	else
	{
		cout << ans << endl;
	}
	system("pause");
;	return 0;
}