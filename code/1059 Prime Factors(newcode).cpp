#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
struct Node
{
	int coe = 0;
	int exp = 0;
}factor[2000];
bool isprime(long int t)
{
	if (t == 1)
	{
		return false;
	}
	if (t == 2)
	{
		return true;
	}
	for (int i = 2; i * i < t; i++)
	{
		if (t % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	long int number;
	cin >> number;
	long int t = number;
	int anscnt = 0;
	int cur = 0;
	for (int i = 2; i < (int)sqrt(number); i++)
	{
		if (isprime(i))
		{
			if (t % i == 0)
			{
				factor[anscnt].coe = i;
				while (t % i == 0)
				{
					factor[anscnt].exp++;
					t /= i;
				}
				anscnt++;
			}
		}
	}
	if (t != 1)
	{
		factor[anscnt].coe = t;
		factor[anscnt].exp = 1;
		anscnt++;
	}
	printf("%ld=", number);
	if (anscnt == 0)
	{
		printf("%ld", number);
	}
	else
	{
		if (factor[0].exp == 1)
		{
			printf("%d", factor[0].coe);
		}
		else
		{
			printf("%d^%d", factor[0].coe, factor[0].exp);
		}
		for (int i = 1; i < anscnt; i++)
		{
			if (factor[i].exp == 1)
			{
				printf("*%d", factor[i].coe);
			}
			else
			{
				printf("*%d^%d", factor[i].coe, factor[i].exp);
			}
		}
	}
	printf("\n");
	system("pause");
	return 0;
}