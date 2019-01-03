#include <iostream>
#include <vector>
#include <set>
#include <string.h>
using namespace std;
#define SIZE 100000
vector<int> incompatible[SIZE];
bool compatible[SIZE];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		incompatible[a].push_back(b);
		incompatible[b].push_back(a);
	}
	for (int i = 0; i < m; i++)
	{
		int cur;
		int num;
		cin >> num;
		bool flag = false;
		memset(compatible, true, sizeof(compatible));
		for (int j = 0; j < num; j++)
		{
			cin >> cur;
			if (!compatible[cur])
			{
				flag = true;
			}
			for (int k = 0; k < incompatible[cur].size(); k++)
			{
				compatible[incompatible[cur][k]] = false;
			}
		}
		if (!flag)
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