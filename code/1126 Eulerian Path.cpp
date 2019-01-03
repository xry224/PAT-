#include <iostream>
#include<vector>
#include <string.h>
using namespace std;
class Node
{
public:
	vector<int> next;
}edges[505];
int cnt = 0;
bool visit[505];
void dfs(int cur)
{
	if (visit[cur])
	{
		return;
	}
	cnt++;
	visit[cur] = true;
	for (int i = 0; i < edges[cur].next.size(); i++)
	{
		int npoint = edges[cur].next[i];
		dfs(npoint);
	}
}
int main()
{
	int n, edge;
	int oddcnt = 0;
	memset(visit, false, sizeof(visit));
	int Degree[505] = { 0 };
	cin >> n >> edge;
	for (int i = 1; i <= edge; i++)
	{
		int a, b;
		cin >> a >> b;
		Degree[a]++;
		Degree[b]++;
		edges[a].next.push_back(b);
		edges[b].next.push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << Degree[i];
		if (Degree[i] % 2 != 0)
		{
			oddcnt++;
		}
		if (i != n)
		{
			cout << " ";
		}
	}
	cout << endl;
	dfs(1);
	if (cnt != n || oddcnt > 2)
	{
		cout << "Non-Eulerian" << endl;
	}
	else if (oddcnt == 0)
	{
		cout << "Eulerian" << endl;
	}
	else if (oddcnt == 2)
	{
		cout << "Semi-Eulerian" << endl;
	}
	system("pause");
	return 0;
}