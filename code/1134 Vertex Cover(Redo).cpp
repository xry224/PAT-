#include <iostream>
#include <vector>
#include<string.h>
using namespace std;
vector<int> edges[10005];
bool visit[10005];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(i);
		edges[b].push_back(i);
	}
	int query;
	cin >> query;
	for (int i = 0; i < query; i++)
	{
		int num;
		cin >> num;
		memset(visit, false, sizeof(visit));
		for (int j = 0; j < num; j++)
		{
			int t;
			cin >> t;
			for (int k = 0; k < edges[t].size(); k++)
			{
				visit[edges[t][k]] = true;
			}
		}
		bool flag = true;
		for (int j = 0; j < m; j++)
		{
			if (!visit[j])
			{
				flag = false;
				break;
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