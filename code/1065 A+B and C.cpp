#pragma warning(disable:4996)
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		bool flag;
		long long a, b, c;
		cin >> a >> b >> c;
		printf("Case #%d: ", i);
		long long d = a + b;
		if (a < 0 && b < 0 && d >= 0)
		{
			flag = false;
		}
		else if (a > 0 && b > 0 && d <= 0)
		{
			flag = true;
		}
		else
		{
			flag = d > c;
		}

		if (flag)
		{
			printf("true\n");
		}
		else
		{
			printf("false\n");
		}
	}
	system("pause");
	return 0;
}

