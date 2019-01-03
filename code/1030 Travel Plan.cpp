#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
using namespace std;
class Edge
{
public:
	int cost;
	int next;
	int length;
	Edge()
	{

	}
};
vector<Edge> edges[501];
//vector<int> parent[501];
bool visit[501];
int dis[501];
//int ans = INT_MAX;
int path[501];
int cost[501];
int n, roads, start, target;
void Ini()
{
	memset(visit, false, sizeof(visit));
	for (int i = 0; i <= 500; i++)
	{
		path[i] = -1;
		dis[i] = -1;
	}
}
void Dij()
{
	dis[start] = 0;
	visit[start] = true;
	int newPoint = start;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < edges[newPoint].size(); j++)
		{
			int next = edges[newPoint][j].next;
			int distance = edges[newPoint][j].length;
			if (dis[next] == -1 || dis[next] > dis[newPoint] + distance)
			{
				/*parent[next].clear();
				parent[next].push_back(newPoint);*/
				dis[next] = dis[newPoint] + distance;
				cost[next] = cost[newPoint] + edges[newPoint][j].cost;
				path[next] = newPoint;
			}
			else if (dis[next] == dis[newPoint] + distance)
			{
				//parent[next].push_back(newPoint);
				if (cost[next] > cost[newPoint] + edges[newPoint][j].cost)
				{
					cost[next] = cost[newPoint] + edges[newPoint][j].cost;
					path[next] = newPoint;
				}

			}
		}

		int min = INT_MAX;
		for (int j = 0; j < n; j++)
		{
			if (visit[j] || dis[j] == -1)
			{
				continue;
			}
			if (dis[j] < min)
			{
				newPoint = j;
				min = dis[j];
			}
		}
		visit[newPoint] = true;
	}
}
int main()
{
	Ini();
	cin >> n >> roads >> start >> target;	
	Edge t;
	int c1, c2, len, c;
	for (int i = 0; i < roads; i++)
	{
		cin >> c1 >> c2 >> len >> c;
		t.next = c2;
		t.length = len;
		t.cost = c;
		edges[c1].push_back(t);

		t.next = c1;
		edges[c2].push_back(t);
	}
	Dij();
	int ans[501];
	int cnt = 0;
	int first = target;
	while (path[first] != -1)
	{
		ans[cnt++] = first;
		first = path[first];
	}
	ans[cnt++] = start;
	for (int i = cnt - 1; i >= 0; i--)
	{
		cout << ans[i] << " ";
	}
	cout << dis[target] << " " << cost[target] << endl;
	system("pause");
	return 0;
}
/*void check()
{
	int t[501];
	int cnt = 0;
	int first = target;
	while (path[first] != -1)
	{
		t[cnt++] = first;
		first = path[first];
	}
	t[cnt++] = start;
	for (int i = cnt - 1; i >= 0; i--)
	{

	}
}
void Dfs(int cur)
{
	if (cur == start)
	{
		check();
		return;
	}

	for (int i = 0; i < parent[cur].size(); i++)
	{
		path[cur] = parent[cur][i];
		Dfs(path[cur]);
	}
}*/