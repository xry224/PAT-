#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int map[205][205];
	memset(map, -1, sizeof(map));
	for (int i = 0; i < m; i++)
	{
		int a, b, dis;
		cin >> a >> b >> dis;
		map[a][b] = map[b][a] = dis;
	}
	int num;
	cin >> num;
	int ans = 1;
	int shortest = INT_MAX;
	for (int i = 1; i <= num; i++)
	{
		int totaldis = 0;
		int length;
		cin >> length;
		vector<int> list(length);
		vector<int> appear(n + 1);
		for (int j = 0; j < length; j++)
		{
			cin >> list[j];
			appear[list[j]]++;
		}
		cout << "Path " << i << ": ";
		for (int j = 0; j < length - 1; j++)
		{
			int u = list[j], v = list[j + 1];
			if (map[u][v] == -1)
			{
				totaldis = -1;
				break;
			}
			totaldis += map[u][v];
		}
		if (totaldis == -1)
		{
			cout << "NA (Not a TS cycle)" << endl;
			continue;
		}
		cout << totaldis;
		if (list[0] != list[length - 1])
		{
			cout << " (Not a TS cycle)" << endl;
			continue;
		}
		int flag = 2;
		for (int j = 1; j <= n; j++)
		{
			if (appear[j] == 0)
			{
				flag = 0;
				break;
			}
			if (appear[j] > 2 || appear[j] == 2 && j != list[0])
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << " (Not a TS cycle)" << endl;
		}
		else
		{
			if (totaldis < shortest)
			{
				shortest = totaldis;
				ans = i;
			}
			if (flag == 2)
			{
				cout << " (TS simple cycle)" << endl;
			}
			else if (flag == 1)
			{
				cout << " (TS cycle)" << endl;
			}
		}
	}
	cout << "Shortest Dist(" << ans << ") = " << shortest << endl;
	system("pause");
	return 0;
}