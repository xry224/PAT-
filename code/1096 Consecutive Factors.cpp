#include <iostream>
#include <math.h>
using namespace std;
int factor[100000];
int main()
{
	int n;
	cin >> n;
	int maxcnt = 0;
	int first = 0;
	for (int i = 2; i <= (int)sqrt(n); i++)
	{
		if (n % i == 0)
		{
			int t = n;
			int fac = i;
			int cnt = 0;
			while (t%fac == 0)
			{
				cnt++;
				t /= fac;
				fac++;
			}
			if (cnt > maxcnt)
			{
				maxcnt = cnt;
				first = i;
			}
		}
	}
	if (maxcnt == 0)
	{
		cout << 1 << endl;
		cout << n << endl;
	}
	else
	{
		cout << maxcnt << endl;
		cout << first;
		for (int i = 1; i < maxcnt; i++)
		{
			cout << "*" << first + i;
		}
		cout << endl;	
	}

	system("pause");
	return 0;
}