#include <iostream>
#include <vector>
using namespace std;
vector<int> edges[1005];
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> Degree(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		Degree[b]++;
	}
	int query;
	cin >> query;
	vector<int> ans;
	for (int i = 0; i < query; i++)
	{
		vector<int> tempDegree = Degree;
		bool flag = true;
		for (int j = 0; j < n; j++)
		{
			int number;
			cin >> number;
			if (tempDegree[number] != 0 || !flag)
			{
				flag = false;
				continue;
			}
			for (int k = 0; k < edges[number].size(); k++)
			{
				tempDegree[edges[number][k]]--;
			}
		}
		if (!flag)
		{
			ans.push_back(i);
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i != ans.size() - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}