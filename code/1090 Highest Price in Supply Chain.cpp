#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <math.h>
using namespace std;
vector<int> supply[100005];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	double price;
	double percent;
	int t;
	cin >> n >> price >> percent;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		if (t == -1)
		{
			t = n + 1;
		}
		supply[t].push_back(i);
	}
	queue<int> q;
	for (int i = 0; i < supply[n + 1].size(); i++)
	{
		q.push(supply[n + 1][i]);
	}
	int level = 0;
	int count;
	while (!q.empty())
	{
		int size = q.size();
		count = size;
		for (int i = 0; i < size; i++)
		{
			t = q.front();
			q.pop();
			for (int j = 0; j < supply[t].size(); j++)
			{
				q.push(supply[t][j]);
			}
		}
		level++;
	}
	level--;
	cout << fixed << setprecision(2) << price * pow(1 + (double)percent / 100, level) << " ";
	cout << count << endl;
	system("pause");
	return 0;
}