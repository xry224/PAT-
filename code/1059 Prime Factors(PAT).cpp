#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;
#define SIZE 1000000
int check[SIZE] = { 0 };
int prime[SIZE];
int cnt = 0;
void Prime()
{
	for (int i = 2; i < SIZE; i++)
	{
		if (check[i] == 0)
		{
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * prime[j] < SIZE; j++)
		{
			check[i * prime[j]] = 1;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
struct Node
{
	int coe = 0;
	int exp = 0;
}factor[2000]; 
int main()
{
	Prime();
	long int number;
	cin >> number;
	long int t = number;
	int anscnt = 0;
	int cur = 0;
	for (int i = cur; i < cnt; i++)
	{
		if (t == 1)
		{
			break;
		}
		if (t % prime[i] == 0)
		{
			while (t % prime[i] == 0)
			{
				factor[anscnt].coe = prime[i];
				factor[anscnt].exp++;
				t /= prime[i];
			}
			anscnt++;
		}
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