#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
long int gcd(long int a, long int b)
{
	return b == 0 ? a : gcd(b, a%b);
}
int main()
{
	long int deno = 1;
	long int nume = 0;
	int n;
	scanf("%d", &n);
	long int n1, n2;
	for (int i = 0; i < n; i++)
	{
		scanf("%ld/%ld", &n1, &n2);
		long int t = gcd(n2, deno);
		long int ndeno = deno / t * n2;
		nume = nume * (ndeno / deno) + n1 * (ndeno / n2);
		deno = ndeno;
		//
	}
	long int t = gcd(nume, deno);
	t = t < 0 ? -t : t;
	nume = nume / t;
	deno = deno / t;
	if (nume == 0)
	{
		printf("0\n");
	}
	
	else if (abs(deno) < abs(nume))
	{
		if (nume % deno == 0)
		{
			printf("%ld\n", nume / deno);
		}
		else
		{
			long int t = nume / deno;
			nume = nume - t * deno;
			printf("%ld %ld/%ld\n", t, nume, deno);
		}
	}
	else
	{
		printf("%ld/%ld\n", nume, deno);
	}
	system("pause");
	return 0;
}