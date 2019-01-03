#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int Tree[1001];
struct Edge
{
	int u;
	int v;
}Edges[500001];
void Init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		Tree[i] = i;
	}
}
int findRoot(int x)
{
	if (Tree[x] == x)
	{
		return x;
	}
	int t = findRoot(Tree[x]);
	Tree[x] = t;
	return t;
}
void Join(int x, int y)
{
	x = findRoot(x);
	y = findRoot(y);
	if (x != y)
	{
		Tree[x] = y;
	}
}
int main()
{
	//memset(map, 0, sizeof(map));
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &Edges[i].u, &Edges[i].v);
		//cin >> Edges[i].u >> Edges[i].v;
	}
	for (int i = 0; i < k; i++)
	{
		Init(n);
		int occ;
		cin >> occ;
		int ans = 0;
		for (int j = 0; j < m; j++)
		{
			int a = Edges[j].u;
			int b = Edges[j].v;
			if (a == occ || b == occ)
			{
				continue;
			}
			Join(a, b);
		}
		//计算联通分量数量
		for (int j = 1; j <= n; j++)
		{
			if (j == occ)
			{
				continue;
			}
			else
			{
				if (Tree[j] == j)
				{
					ans++;
				}
			}
		}
		cout << ans-1 << endl;
	}
	system("pause");
	return 0;
}