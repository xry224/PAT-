#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a%b);
}
void Print(long long numerator, long long denominator)
{
	if (numerator == 0)
	{
		cout << 0;
	}
	else if (abs(numerator) >= abs(denominator))
	{
		long long appn = abs(gcd(numerator, denominator));
		numerator /= appn;
		denominator /= appn;
		bool neg = false;
		if (numerator < 0)
		{
			neg = true;
			numerator = -numerator;
		}
		if (numerator % denominator == 0)
		{
			if (neg)
			{
				printf("(-%lld)", numerator / denominator);
			}
			else
			{
				printf("%lld", numerator / denominator);
			}
			return;
		}
		long long t = numerator / denominator;
		numerator = numerator - t * denominator;
		if (neg)
		{
			printf("(-%lld %lld/%lld)", t, numerator, denominator);
		}
		else
		{
			printf("%lld %lld/%lld", t, numerator, denominator);
		}
	}
	else
	{
		long long appn = abs(gcd(numerator, denominator));
		numerator /= appn;
		denominator /= appn;
		if (numerator < 0)
		{
			printf("(%lld/%lld)", numerator, denominator);
		}
		else
		{
			printf("%lld/%lld", numerator, denominator);
		}
	}
}
int main()
{
	long long n1, d1, n2, d2;
	scanf("%lld/%lld %lld/%lld", &n1, &d1, &n2, &d2);
	
	int t = abs(gcd(d1, d2));
	//通分后两个分数的分子与分母
	long long nd1 = d1 * (d2 / t);
	long long nd2 = d2 * (d1 / t);
	long long num1 = n1 * (nd1 / d1);
	long long num2 = n2 * (nd2 / d2);
	//cout << num1 << " " << nd1 << " " << num2 << " " << nd2 << endl;
	//加法
	long long res = num1 + num2;
	Print(n1, d1);
	cout << " + ";
	Print(n2, d2);
	cout << " = ";
	Print(res, nd1);
	cout << endl;
	//减法
	res = num1 - num2;
	Print(n1, d1);
	cout << " - ";
	Print(n2, d2);
	cout << " = ";
	Print(res, nd1);
	cout << endl;
	//乘法
	Print(n1, d1);
	cout << " * ";
	Print(n2, d2);
	cout << " = ";
	Print(n1 * n2, d1 * d2);
	cout << endl;
	//除法
	if (n2 == 0)
	{
		Print(n1, d1);
		cout << " / ";
		Print(n2, d2);
		cout << " = Inf" << endl;
	}
	else
	{
		Print(n1, d1);
		cout << " / ";
		Print(n2, d2);
		cout << " = ";
		long long quon = n1 * d2;
		long long qund = d1 * n2;
		if(qund < 0)
		{
			qund = -qund;
			quon = -quon;
		}
		Print(quon, qund);
		cout << endl;
	}

	system("pause");
	return 0;
}