#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
using namespace std;
int Bike[501];
bool mark[501];
int dis[501];
int path[501];
int ans[501];
int cap, n, tar, num;
//int send[501], back[501];
vector<int> parent[501];
int send = INT_MAX;
int back = INT_MIN;
int pathlen;
struct Edge
{
	int next;
	int cost;
};
vector<Edge> edges[501];
void Ini()
{
	memset(mark, false, sizeof(mark));
	for (int i = 0; i <= 500; i++)
	{
		path[i] = -1;
		//back[i] = send[i] = 0;
		dis[i] = -1;
	}
}
bool isIn(int newPoint, int next)
{
	for (int i = 0; i < parent[next].size(); i++)
	{
		if (parent[next][i] == newPoint)
		{
			return true;
		}
	}
	return false;
}
void Dij()
{
	mark[0] = true;
	dis[0] = 0;
	int newPoint = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < edges[newPoint].size(); j++)
		{
			int next = edges[newPoint][j].next;
			int cost = edges[newPoint][j].cost;
			if (mark[next])
			{
				continue;
			}
			if (dis[next] == -1 || dis[next] > dis[newPoint] + cost)
			{
				dis[next] = dis[newPoint] + cost;
				parent[next].clear();
				parent[next].push_back(newPoint);
			}
			if (dis[next] == dis[newPoint] + cost && !isIn(newPoint, next))
			{
				parent[next].push_back(newPoint);
			}
		}
		int min = INT_MAX;
		for (int j = 1; j <= n; j++)
		{
			if (mark[j] || dis[j] == -1)
			{
				continue;
			}
			else if (dis[j] < min)
			{
				min = dis[j];
				newPoint = j;
			}
		}
		mark[newPoint] = true;
		//cout << newPoint << endl;
	}

}
void dfs(int cur, int cursend, int curback, int level)
{
	if (cur == 0)
	{
		if (cursend < send)
		{
			send = cursend;
			back = curback;
			path[cur] = -1;
			for (int i = 0; i <= n; i++)
			{
				ans[i] = path[i];
			}
			//cout << ans[0] << endl;
		}
		else if (cursend == send && curback < back)
		{
			back = curback;
			path[cur] = -1;
			for (int i = 0; i <= n; i++)
			{
				ans[i] = path[i];
			}
			//cout << ans[0] << endl;
		}
		return;
	}

	for (int i = 0; i < parent[cur].size(); i++)
	{
		int par = parent[cur][i];
		path[cur] = par;
		int nextsend = cursend, nextback = curback;
		if (Bike[par] > cap / 2)
		{
			nextback = curback + Bike[par] - cap / 2;
			//nextsend = send;
		}
		else if (Bike[par] < cap / 2)
		{
			int t = cap / 2 - Bike[par];
			if (curback < t)
			{
				nextback = 0;
				nextsend = cursend + t - curback;
			}
			else
			{
				nextback = curback - t;
			}
		}
		dfs(par, nextsend, nextback, level + 1);

	}
}
void check()
{
	int t[501];
	int first = tar;
	int cnt = 0;
	while (path[first] != -1)
	{
		t[cnt++] = first;
		first = path[first];
	}
	path[cnt++] = 0;
	int curback = 0;
	int cursend = 0;
	int half = cap / 2;
	for (int i = cnt - 2; i >= 0; i--)
	{
		int station = t[i];
		if (Bike[station] > half)
		{
			curback += Bike[station] - half;
		}
		else if (Bike[station] < half)
		{
			int need = half - Bike[station];
			//需要额外带车
			if (curback < need)
			{
				cursend += need - curback;
				curback = 0;
			}
			//不需要额外带车
			else
			{
				curback -= need;
			}
		}
	}
	if (cursend < send)
	{
		send = cursend;
		back = curback;
		pathlen = cnt - 2;
		for (int i = cnt - 2; i >= 0; i--)
		{
			ans[i] = t[i];
		}
	}
	else if (cursend == send)
	{
		if (curback < back)
		{
			send = cursend;
			back = curback;
			pathlen = cnt - 2;
			for (int i = cnt - 2; i >= 0; i--)
			{
				ans[i] = t[i];
			}
		}
	}
}
void Dfs(int cur)
{
	if (cur == 0)
	{
		check();
		return;
	}

	for (int i = 0; i < parent[cur].size(); i++)
	{
		int par = parent[cur][i];
		path[cur] = par;
		Dfs(par);
	}
}
int main()
{
	Ini();
	cin >> cap >> n >> tar >> num;
	for (int i = 1; i <= n; i++)
	{
		cin >> Bike[i];
	}
	for (int i = 0; i < num; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		Edge t;
		t.next = u;
		t.cost = cost;
		edges[v].push_back(t);

		t.next = v;
		edges[u].push_back(t);
	}
	/*int res[501];
	int cnt = 0;
	int t = tar;*/
	//cout << ans[0] << endl;
	Dij();
	//dfs(tar, 0, 0, 0);
	Dfs(tar);
	/*while (ans[t] != -1)
	{
		res[cnt++] = t;
		t = ans[t];
	}*/
	cout << send << " " << 0;
	for (int i = pathlen; i >= 0; i--)
	{
		cout << "->" << ans[i];
	}
	cout <<" "<<back << endl;
	system("pause");
	return 0;
}