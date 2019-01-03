#include<iostream>
#include<vector>
#include <string.h>
using namespace std;
bool edges[205][205];
int main()
{
	memset(edges, false, sizeof(edges));
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a][b] = edges[b][a] = true;
	}
	int query;
	cin >> query;
	for (int i = 0; i < query; i++)
	{
		bool flag = true;
		int visit[205] = { 0 };
		vector<int> path;
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int t;
			cin >> t;
			if (visit[t] == 0)
			{
				path.push_back(t);
				visit[t] = 1;
			}
			else
			{
				if (j != num - 1)
				{
					flag = false;
				}
				else
				{
					path.push_back(t);
				}
			}
		}
		if (num != n + 1 || path[0] != path[path.size() - 1])
		{
			flag = false;
		}
		if (flag)
		{
			for (int i = 0; i < num - 1; i++)
			{
				int first = path[i];
				int second = path[i + 1];
				if (!edges[first][second])
				{
					flag = false;
					break;
				}
			}
		}


		if (flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	system("pause");
	return 0;
}