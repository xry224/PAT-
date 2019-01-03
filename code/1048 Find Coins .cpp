#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int index[100005];
	int coins[1005] = { 0 };
	int n, target;
	int cnt = 0;
	int t;
	scanf("%d %d", &n, &target);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);		
		if (coins[t] == 0)
		{
			index[cnt++] = t;
		}
		coins[t]++;

		
	}
	int a = -1, b = -1;
	sort(index, index + cnt);
	for (int i = 0; i < cnt; i++)
	{
		int need = target - index[i];
		if (need < index[i])
		{
			break;
		}
		if (index[i] == need && coins[need] > 1)
		{
			a = index[i];
			b = need;
			break;
		}
		else if (index[i] != need && coins[need] != 0)
		{
			a = index[i];
			b = need;
			break;
		}
	}
	if (a == b && a == -1)
	{
		printf("No Solution\n");
	}
	else
	{
		printf("%d %d\n", a, b);
	}

	system("pause");
	return 0;
}