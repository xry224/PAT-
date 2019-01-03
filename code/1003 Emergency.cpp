#include <iostream>
#include <vector>
#include <string.h>
#define SIZE 500*500
using namespace std;
#define INF 1000000000
int team[501];
bool mark[501];
int dis[501];
int path[501];
int amount[501];
class Edge
{
public:
	int next;
	int cost;
	Edge()
	{

	}
};
vector<Edge> edges[501];
void Initialize()
{
	for (int i = 0; i < 500; i++)
	{
		edges[i].clear();
	}
	memset(mark, false, sizeof(mark));
	for (int i = 0; i < 500; i++)
	{
		path[i] = 0;
		amount[i] = 0;
		dis[i] = -1;
	}
}
int main()
{
	int n, m, start, target;
	cin >> n >> m >> start >> target;
	Initialize();
	for (int i = 0; i < n; i++)
	{
		cin >> team[i];
		amount[i] = team[i];
	}
	Edge t;
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		t.next = v;
		t.cost = c;
		edges[u].push_back(t);

		t.next = u;
		edges[v].push_back(t);
	}
	dis[start] = 0;
	mark[start] = true;
	path[start] = 1;
	int newPoint = start;
	for (int i = 0; i < n - 1; i++)
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
				amount[next] = amount[newPoint] + team[next];
				path[next] = path[newPoint];
;			}
			else if (dis[next] == dis[newPoint] + cost)
			{
				path[next] += path[newPoint];
				if (amount[next] < amount[newPoint] + team[next])
				{
					amount[next] = amount[newPoint] + team[next];
				}
			}
		}
		int min = INF;
		for (int j = 0; j < n; j++)
		{
			if (dis[j] == -1 || mark[j])
			{
				continue;
			}
			if (dis[j] < min)
			{
				min = dis[j];
				newPoint = j;
			}
		}
		mark[newPoint] = true;
	}

	cout << path[target] << " " << amount[target] << endl;
	system("pause");
	return 0;
}