#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		double t;
		scanf("%lf", &t);
		sum += (t * (n - i) * (i + 1));
	}
	printf("%.2lf\n", sum);
	system("pause");
	return 0;
}