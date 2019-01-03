#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		long double a, b, c;
		cin >> a >> b >> c;
		if (a + b > c)
		{
			printf("true\n");
		}
		else
		{
			printf("false\n");
		}
	}

}