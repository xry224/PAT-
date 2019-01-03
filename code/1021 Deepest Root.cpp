#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int Tree[10001];
int ans = 0;
vector<int> child[10001];
bool visit[10001];
int anslen = 0;
set<int> res;
void Ini()
{
	for (int i = 0; i <= 10000; i++)
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
void dfs(int cur, int level, int start)
{
	bool flag = false;
	for (int i = 0; i < child[cur].size(); i++)
	{
		int son = child[cur][i];
		
		if (!visit[son])
		{
			//cout << cur << " " << son << endl;
			flag = true;
			visit[son] = true;
			dfs(son, level + 1, start);
		}
	}
	if (!flag)
	{
		if (level > ans)
		{
			res.clear();
			res.insert(cur);
			ans = level;
		}
		else if (level == ans)
		{
			res.insert(cur);
		}
	}
}
int main()
{
	Ini();
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		child[a].push_back(b);
		child[b].push_back(a);
		int ra = findRoot(a);
		int rb = findRoot(b);
		if (ra != rb)
		{
			Tree[ra] = rb;
		}
	}
	int cnt = 0;
	//计算联通分量数量
	for (int i = 1; i <= n; i++)
	{
		if (Tree[i] == i)
		{
			cnt++;
		}
	}
	//联通分量不止一个，图无法构成树
	if (cnt > 1)
	{
		cout << "Error: " << cnt << " components" << endl;
		system("pause");
		return 0;
	}
	set<int>::iterator it;
	set<int> finalans;
	memset(visit, false, sizeof(visit));
	visit[1] = true;
	dfs(1, 0, 1);

	for (it = res.begin(); it != res.end(); it++)
	{
		finalans.insert(*it);
	}
	memset(visit, false, sizeof(visit));
	it = res.begin();
	int start = *it;
	visit[start] = true;
	dfs(start, 0, start);
	for (it = res.begin(); it != res.end(); it++)
	{
		finalans.insert(*it);
	}
	for (it = finalans.begin(); it != finalans.end(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;
}