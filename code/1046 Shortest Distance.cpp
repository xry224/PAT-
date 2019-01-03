#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;
int cycle[100005];
int sum[100005];
int n;
int calDis(int start, int end)
{
	int ans = 0;
	if (start < end)
	{
		for (int i = start; i < end; i++)
		{
			ans += cycle[i];
		}
	}
	else if (start > end)
	{
		for (int i = 1; i < end; i++)
		{
			ans += cycle[i];
		}
		for (int i = start; i <= n; i++)
		{
			ans += cycle[i];
		}
	}
	return ans;
}
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
int main()
{
	int query;
	sum[0] = 0;
	int total = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &cycle[i]);
		total += cycle[i];
		sum[i] = sum[i - 1] + cycle[i];
	}
	scanf("%d", &query);
	int a, b;
	for (int i = 0; i < query; i++)
	{
		scanf("%d %d", &a, &b);
		//int res1 = calDis(a, b);
		if (a < b)
		{
			swap(a, b);
		}
		int res1 = sum[a - 1] - sum[b - 1];
		int res2 = total - res1;
		int res = res1 < res2 ? res1 : res2;
		printf("%d\n", res);
	}
	system("pause");
	return 0;
}