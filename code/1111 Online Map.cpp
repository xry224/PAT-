#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <stdio.h>
using namespace std;
class Edge
{
public:
	int next;
	int cost;
	int time;
	Edge()
	{

	}
};
int path1[505];
int path2[505];
int timecon[505];
int length[505];
bool visit[505];
int dis[505];
int start, destination;
vector<Edge> edges[505];
void IniPath(int n)
{
	for (int i = 0; i < n; i++)
	{
		path1[i] = path2[i] = i;
	}
}
void Ini(int n)
{
	memset(visit, false, sizeof(visit));
	for (int i = 0; i <= n; i++)
	{
		length[i] = 1;
		timecon[i] = -1;
		dis[i] = -1;
	}
}
void Dij1(int n)
{
	int newPoint = start;
	dis[newPoint] = 0;
	visit[newPoint] = true;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < edges[newPoint].size(); j++)
		{
			int next = edges[newPoint][j].next;
			int cost = edges[newPoint][j].cost;
			int t = edges[newPoint][j].time;
			if (visit[next])
			{
				continue;
			}
			if (dis[next] == -1 || dis[next] > dis[newPoint] + cost)
			{
				dis[next] = dis[newPoint] + cost;
				timecon[next] = timecon[newPoint] + t;
				path1[next] = newPoint;
			}
			if (dis[next] == dis[newPoint] + cost)
			{
				if (timecon[next] > timecon[newPoint] + t)
				{
					timecon[next] = timecon[newPoint] + t;
					path1[next] = newPoint;
				}
			}
		}

		int min = INT_MAX;
		for (int j = 0; j < n; j++)
		{
			if (visit[j] || dis[j] == -1)
			{
				continue;
			}
			if (dis[j] < min)
			{
				min = dis[j];
				newPoint = j;
			}
		}
		visit[newPoint] = true;
	}
}
void Dij2(int n)
{
	int newPoint = start;
	timecon[newPoint] = 0;
	visit[newPoint] = true;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < edges[newPoint].size(); j++)
		{
			int next = edges[newPoint][j].next;
			int t = edges[newPoint][j].time;
			if (visit[next])
			{
				continue;
			}
			if (timecon[next] == -1 || timecon[next] > timecon[newPoint] + t)
			{
				timecon[next] = timecon[newPoint] + t;
				length[next] = length[newPoint] + 1;
				path2[next] = newPoint;
			}
			if (timecon[next] == timecon[newPoint] + t)
			{
				if (length[next] > length[newPoint] + 1)
				{
					length[next] = length[newPoint] + 1;
					path2[next] = newPoint;
				}
			}
		}

		int min = INT_MAX;
		for (int j = 0; j < n; j++)
		{
			if (visit[j] || timecon[j] == -1)
			{
				continue;
			}
			if (timecon[j] < min)
			{
				min = timecon[j];
				newPoint = j;
			}
		}
		visit[newPoint] = true;
	}
}
bool check(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (path1[i] != path2[i])
		{
			return false;
		}
	}
	return true;
}
void OutPath(int n, int path[], int des, int start)
{
	vector<int> p;
	int t = des;
	while (path[t] != t)
	{
		p.push_back(t);
		t = path[t];
	}
	int size = p.size();
	cout << start;
	for (int i = size - 1; i >= 0; i--)
	{
		cout << " -> " << p[i];
	}
	cout << endl;
}
int main()
{
	int n, k;
	cin >> n >> k;
	Edge t;
	IniPath(n);
	for (int i = 0; i < k; i++)
	{
		int v1, v2, way, length, time;
		cin >> v1 >> v2 >> way >> length >> time;
		t.next = v2;
		t.cost = length;
		t.time = time;
		edges[v1].push_back(t);

		if (way == 0)
		{
			t.next = v1;
			edges[v2].push_back(t);
		}
	}
	cin >> start >> destination;
	Ini(n);
	Dij1(n);
	int distance = dis[destination];
	Ini(n);
	Dij2(n);
	int timeconsume = timecon[destination];
	if (check(n))
	{
		printf("Distance = %d; Time = %d: ", distance, timeconsume);
		OutPath(n, path1, destination, start);
	}
	else
	{
		printf("Distance = %d: ", distance);
		OutPath(n, path1, destination, start);
		printf("Time = %d: ", timeconsume);
		OutPath(n, path2, destination, start);
	}
	system("pause");
	return 0;
}