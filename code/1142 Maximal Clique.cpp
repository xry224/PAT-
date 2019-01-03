#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> edges[205];
int main()
{
	int n, nv;
	cin >> n >> nv;
	for (int i = 0; i < nv; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	int query;
	cin >> query;
	for (int i = 0; i < query; i++)
	{
		//cout << i << endl;
		int cnt[205] = { 0 };
		int size;
		cin >> size;
		if (size == 1)
		{
			int t;
			cin >> t;
			if (edges[t].size() == 0)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "Not Maximal" << endl;
			}
			continue;
		}
		vector<int> sets;
		for (int j = 0; j < size; j++)
		{
			int t;
			cin >> t;
			sets.push_back(t);
			for (int k = 0; k < edges[t].size(); k++)
			{
				cnt[edges[t][k]]++;
			}
		}
		bool flag = true;;  //yes defalut
		for (int j = 0; j < sets.size(); j++)
		{
			int num = sets[j];
			if (cnt[num] != size - 1)
			{
				flag = false;
				break;
			}
		}
		if (!flag)
		{
			cout << "Not a Clique" << endl;
		}
		else
		{
			bool more = false;
			for (int j = 1; j <= n; j++)
			{
				if (cnt[j] == size)
				{
					more = true;
					break;
				}
			}
			if (more)
			{
				cout << "Not Maximal" << endl;
			}
			else
			{
				cout << "Yes" << endl;
			}
		}
	}
	system("pause");
	return 0;
}