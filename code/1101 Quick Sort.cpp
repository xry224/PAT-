#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include<algorithm>
#include <string.h>
using namespace std;
int num[100005];
int ans[100005];
bool valid[100005];
int cnt = 0;
class Node
{
public:
	int min;
	int max;
	int l;
	int r;
}Tree[100005];
int main()
{
	int n;
	scanf("%d", &n);
	memset(valid, true, sizeof(valid));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	int maxbefore = -1;
	int minafter = 1000000005;
	for (int i = 0; i < n; i++)
	{
		if (num[i] >= maxbefore)
		{
			maxbefore = num[i];
		}
		else
		{
			valid[i] = false;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (num[i] <= minafter)
		{
			minafter = num[i];
		}
		else
		{
			valid[i] = false;
		}
		if (valid[i])
		{
			ans[cnt++] = num[i];
		}
	}
	sort(ans, ans + cnt);
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
	{
		cout << ans[i];
		if (i != cnt - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}