#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <set>
using namespace std;	
vector<int> followers[1005];
int n, l;
int Bfs(int source)
{
	bool visit[1005];
	memset(visit, false, sizeof(visit));
	queue<int> q;
	q.push(source);
	visit[source] = true;
	int level = 0;
	int ans = 0;
	while (!q.empty() && level < l)
	{
		int size = q.size();
		for (int j = 0; j < size; j++)
		{
			int t = q.front();
			q.pop();
			for (int i = 0; i < followers[t].size(); i++)
			{
				if (visit[followers[t][i]])
				{
					continue;
				}
				else
				{
					q.push(followers[t][i]);
					ans++;
					visit[followers[t][i]] = true;
				}
			}
		}
		level++;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int t;
			cin >> t;
			followers[t].push_back(i);
		}
	}

	int k;
	cin >> k;
	int query;
	for (int i = 0; i < k; i++)
	{
		cin >> query;
		cout << Bfs(query) << endl;
	}
	system("pause");
	return 0;
}