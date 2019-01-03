#pragma warning(disable:4996)
#include <stdio.h>
#include <set>
using namespace std;
set<int> sets[60];
int main()
{
	int n;
	scanf("%d", &n);
	int m;
	int t;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &t);
			sets[i].insert(t);
		}
	}
	set<int>::iterator it;
	set<int>::iterator temp;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int nc = 0;
		int nt = sets[a].size() + sets[b].size();
		for (it = sets[a].begin(); it != sets[a].end(); it++)
		{
			int num = *it;
			temp = sets[b].find(num);
			if (temp != sets[b].end())
			{
				nc++;
				nt--;
			}
		}
		printf("%.1f%%\n", ((double)nc / (double)nt) * 100);
	}
	system("pause");
	return 0;
}