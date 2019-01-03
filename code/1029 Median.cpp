#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
int main()
{
	queue<int> arr1, arr2;
	int len1, len2;
	scanf("%d", &len1);
	long long t;
	for (int i = 0; i < len1; i++)
	{
		scanf("%lld", &t);
		int num = min(t, (long long)INT_MAX);
		arr1.push(num);
	}
	arr1.push(INT_MAX);
	scanf("%d", &len2);
	int index = (len1 + len2 - 1) / 2;
	int cnt = 0;
	for (int i = 0; i < len2; i++)
	{
		scanf("%lld", &t);
		int num = min(t, (long long)INT_MAX);
		arr2.push(num);		
		if (cnt == index)
		{
			printf("%d\n", min(arr1.front(), arr2.front()));
			return 0;
		}
		if (arr1.front() < arr2.front())
		{
			arr1.pop();
		}
		else
		{
			arr2.pop();
		}
		cnt++;
	}
	arr2.push(INT_MAX);
	for (; cnt < index; cnt++)
	{
		if (arr1.front() < arr2.front())
		{
			arr1.pop();
		}
		else
		{
			arr2.pop();
		}
	}
	printf("%d\n", min(arr1.front(), arr2.front()));
	system("pause");
	return 0;
}