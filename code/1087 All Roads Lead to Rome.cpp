#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <set>
using namespace std;
#define SIZE 26*26*26+5
int name2id(string str)
{
	int c1 = str[0] - 'A';
	int c2 = str[1] - 'A';
	int c3 = str[2] - 'A';
	return c3 + c2 * 26 + c1 * 26 * 26;
}
string id2name(int id)
{
	char c3 = id % 26 + 'A';
	char c2 = (id / 26) % 26 + 'A';
	char c1 = id / 26 / 26 + 'A';
	string ans = "";
	ans += c1;
	ans += c2;
	ans += c3;
	return ans;
}
class Edge
{
public:
	int next;
	int cost;
	Edge()
	{

	}
};
vector<Edge> edges[SIZE];
int happy[SIZE];
int dis[SIZE];
bool visit[SIZE];
vector<int> parent[SIZE];
int pathcount = 0;
int maxhappy = 0;
double avghappy = 0;
vector<int> curpath;
vector<int> bestpath;
set<int> cities;
void Ini()
{
	for (int i = 0; i < SIZE; i++)
	{
		visit[i] = false;
		dis[i] = -1;
	}
}
void Dij(int start, int n)
{
	//µÏ½ÜË¹ÌØÀ­
	int newPoint = start;
	dis[newPoint] = 0;
	visit[newPoint] = true;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < edges[newPoint].size(); j++)
		{
			int next = edges[newPoint][j].next;
			int cost = edges[newPoint][j].cost;
			if (visit[next])
			{
				continue;
			}
			if (dis[next] == -1 || dis[next] > dis[newPoint] + cost)
			{
				dis[next] = dis[newPoint] + cost;
				parent[next].clear();
				parent[next].push_back(newPoint);
			}
			else if (dis[next] == dis[newPoint] + cost)
			{
				parent[next].push_back(newPoint);
			}
		}

		int min = INT_MAX;
		set<int>::iterator it;
		for (it = cities.begin(); it != cities.end(); it++)
		{
			int j = *it;
			if (dis[j] == -1 || visit[j])
			{
				continue;
			}
			if (dis[j] < min)
			{
				newPoint = j;
				min = dis[j];
			}
		}
		visit[newPoint] = true;
		//cout << newPoint << endl;
	}
}
void UpdateRoad()
{
	bestpath = curpath;
}
void check()
{
	int cnt = 0;
	for (int i = curpath.size() - 1; i >= 0; i--)
	{
		cnt += happy[curpath[i]];
	}
	if (cnt > maxhappy)
	{
		maxhappy = cnt;
		avghappy = (double)cnt / (double)(curpath.size() - 1);
		UpdateRoad();
	}
	else if (cnt == maxhappy)
	{
		double avg = (double)cnt / (double)(curpath.size() - 1);
		if (avghappy < avg)
		{
			avghappy = avg;
			UpdateRoad();
		}
	}
}
void dfs(int cur, int start)
{
	curpath.push_back(cur);
	if (cur == start)
	{
		check();
		pathcount++;
		return;
	}
	for (int i = 0; i < parent[cur].size(); i++)
	{
		dfs(parent[cur][i], start);
		curpath.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	string start;
	string end = "ROM";
	Ini();
	cin >> n >> k >> start;
	for (int i = 0; i < n - 1; i++)
	{	string name;
		int value;
		cin >> name >> value;
		happy[name2id(name)] = value;
	}
	happy[name2id(start)] = 0;
	Edge t;
	for (int i = 0; i < k; i++)
	{
		string n1, n2;
		int cost;
		cin >> n1 >> n2 >> cost;
		int c1 = name2id(n1);
		int c2 = name2id(n2);
		t.next = c2;
		t.cost = cost;
		edges[c1].push_back(t);

		t.next = c1;
		edges[c2].push_back(t);
		cities.insert(c1);
		cities.insert(c2);
	}
	Dij(name2id(start), n);
	int leastcost = dis[name2id(end)];
	//cout << leastcost << endl;
	dfs(name2id(end), name2id(start));
	cout << pathcount << " " << leastcost << " " << maxhappy << " " << (int)avghappy << endl;
	cout << id2name(bestpath[bestpath.size() - 1]);
	for (int i = bestpath.size() - 2; i >= 0; i--)
	{
		cout << "->" << id2name(bestpath[i]);
	}
	cout << endl;
	system("pause");
	return 0;
}