#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <limits.h>
#include <iomanip>
#include <algorithm>
using namespace std;
int dis[1200];
bool visit[1200];
class Edge
{
public:
	int next;
	int cost;
	Edge()
	{

	}
};
class Gas
{
public:
	int id;
	int mindis;
	double avg;
	bool operator < (const Gas &A)const
	{
		if (mindis == A.mindis)
		{
			if (avg == A.avg)
			{
				return id < A.id;
			}
			return avg < A.avg;
		}
		return mindis > A.mindis;
	}
};
void Ini()
{
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < 1200; i++)
	{
		dis[i] = -1;
	}
}
vector<Edge> edges[1200];
int getID(int n, string station)
{
	if (station[0] == 'G')
	{
		if (station.length() == 2)
		{
			return n + (station[1] - '0');
		}
		else
		{
			return n + 10;
		}
	}
	int id = 0;
	for (int i = 0; i < station.length(); i++)
	{
		id *= 10;
		id += station[i] - '0';
	}
	return id;
}
string getName(int n, int index)
{
	int off = index - n;
	string ans = "G";
	if (off < 10)
	{
		ans = ans + char(off + '0');
	}
	else
	{
		ans += "10";
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, station, roadnumber, range;
	cin >> n >> station >> roadnumber >> range;
	Edge t;
	vector<Gas> ans;
	for (int i = 0; i < roadnumber; i++)
	{
		string a, b;
		int cost;
		cin >> a >> b >> cost;
		int id1 = getID(n, a);
		int id2 = getID(n ,b);
		t.next = id2;
		t.cost = cost;
		edges[id1].push_back(t);

		t.next = id1;
		edges[id2].push_back(t);
	}
	//对所有加油站求最短路
	for (int i = 1; i <= station; i++)
	{
		int id = n + i;
		//求最短路
		Ini();
		dis[id] = 0;
		visit[id] = true;
		int newPoint = id;
		for (int j = 0; j < n + station - 1; j++)
		{
			for (int k = 0; k < edges[newPoint].size(); k++)
			{
				int next = edges[newPoint][k].next;
				int cost = edges[newPoint][k].cost;
				if (visit[next])
				{
					continue;	
				}
				if (dis[next] == -1 || dis[next] > dis[newPoint] + cost)
				{
					dis[next] = dis[newPoint] + cost;
				}
			}

			int min = INT_MAX;
			for (int k = 1; k <= n + station; k++)
			{
				if (dis[k] == -1 || visit[k])
				{
					continue;
				}
				if (dis[k] < min)
				{
					min = dis[k];
					newPoint = k;
				}
			}
			visit[newPoint] = true;
		}
		bool flag = true;
		int total = 0;
		int min = INT_MAX;
		//遍历最短路，判断是否符合条件
		for (int j = 1; j <= n; j++)
		{
			total += dis[j];
			if (dis[j] > range || dis[j] == -1)
			{
				flag = false;
				break;
			}
			if (dis[j] < min)
			{
				min = dis[j];
			}
		}
		if (flag)
		{
			Gas t;
			t.id = id;
			t.mindis = min;
			t.avg = (double)total / (double)n;
			ans.push_back(t);
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.empty())
	{
		cout << "No Solution" << endl;
	}
	else
	{
		Gas t = ans.front();
		string name = getName(n, t.id);
		cout << name << endl;
		cout << fixed << setprecision(1) << (double)t.mindis << " " << t.avg << endl;
	}
	system("pause");
	return 0;
}