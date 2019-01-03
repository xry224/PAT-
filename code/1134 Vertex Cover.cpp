#include <iostream>
#include <vector>
#include <set>
#include <string.h>
using namespace std;
//vector<int> edges[10005];
bool visit[10005];
class edge
{
public:
	int u;
	int v;
	edge(int a, int b)
	{
		u = a;
		v = b;
	}
	edge()
	{
		u = v = -1;
	}
}edges[10005];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[i].u = a;
		edges[i].v = b;
	}
	int query;
	cin >> query;
	for (int i = 0; i < query; i++)
	{
		int num;
		cin >> num;
		set<int> vertex;
		memset(visit, false, sizeof(visit));
		for (int j = 0; j < num; j++)
		{
			int t;
			cin >> t;
			vertex.insert(t);
		}
		bool flag = true;
		for (int j = 0; j < m; j++)
		{
			if (visit[edges[j].u] || visit[edges[j].v])
			{
				continue;
			}
			else
			{
				int a = edges[j].u;
				int b = edges[j].v;
				if (vertex.find(a) != vertex.end())
				{
					visit[a] = true;
				}
				if (vertex.find(b) != vertex.end())
				{
					visit[b] = true;
				}
				if (!visit[a] && !visit[b])
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	system("pause");
	return 0;
}