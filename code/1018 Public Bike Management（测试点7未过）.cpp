#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
using namespace std;
int Bike[501];
bool mark[501];
int dis[501];
int path[501];
int cap, n, tar, num;
int send[501], back[501];
struct Edge
{
	int next;
	int cost;
};
vector<Edge> edges[501];
void Ini()
{
	memset(mark, false, sizeof(mark));
	for (int i = 0; i <= 500; i++)
	{
		back[i] = send[i] = 0;
		dis[i] = -1;
	}
}
void Dij()
{
	mark[0] = true;
	dis[0] = 0;
	int newPoint = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < edges[newPoint].size(); j++)
		{
			int next = edges[newPoint][j].next;
			int cost = edges[newPoint][j].cost;
			if (mark[next])
			{
				continue;
			}
			if (dis[next] == -1 || dis[next] > dis[newPoint] + cost)
			{
				path[next] = newPoint;
				dis[next] = dis[newPoint] + cost;
				//��һվ���������࣬����back����
				if (Bike[next] > cap / 2)
				{
					//��Ҫ���س�
					back[next] = back[newPoint] + Bike[next] - cap / 2;
					send[next] = send[newPoint];
				}
				//��һվ����������
				else if (Bike[next] < cap / 2)
				{
					//��������
					int t = cap / 2 - Bike[next];
					//׼�����صĳ�������Ҫ���ĳ�
					if (back[newPoint] > t)
					{
						back[next] = back[newPoint] - t;
						send[next] = send[newPoint];
					}
					//��Ҫ�������
					else
					{
						back[next] = 0;
						send[next] = send[newPoint] + t - back[newPoint];
					}
				}
			}
			if (dis[next] == dis[newPoint] + cost)
			{
				//��һվ���������࣬����back����
				if (Bike[next] > cap / 2)
				{
					//��Ҫ������صĳ�
					int tb = Bike[next] - cap / 2;
					if (send[next] > send[newPoint])
					{
						send[next] = send[newPoint];
						path[next] = newPoint;
						back[next] = back[newPoint] + tb;
					}
					else if (send[next] == send[newPoint])
					{
						if (back[next] > back[newPoint] + tb)
						{
							back[next] = back[newPoint] + tb;
							path[next] = newPoint;
						}
					}
				}
				//��һվ����������
				else if (Bike[next] < cap / 2)
				{
					//��Ҫ����ĳ�
					int tb = cap / 2 - Bike[next];
					//���г��㹻
					if (back[newPoint] > tb)
					{
						if (send[next] > send[newPoint])
						{
							send[next] = send[newPoint];
							path[next] = newPoint;
							back[next] = back[newPoint] - tb;
						}
						else if (send[next] == send[newPoint])
						{
							if (back[next] > back[newPoint] - tb)
							{
								back[next] = back[newPoint] - tb;
								path[next] = newPoint;
							}
						}
					}
					//��Ҫ�������
					else
					{
						//��Ҫ�����ĳ�������
						int ts = send[newPoint] + tb - back[newPoint];
						if (send[next] > ts)
						{
							send[next] = ts;
							path[next] = newPoint;
							back[next] = 0;
						}
						else if (send[next] == ts)
						{
							if (back[next] > 0)
							{
								back[next] = 0;
								path[next] = newPoint;
							}

						}
					}

				}
			}
		}
		int min = INT_MAX;
		for (int j = 1; j <= n; j++)
		{
			if (mark[j] || dis[j] == -1)
			{
				continue;
			}
			else if (dis[j] < min)
			{
				min = dis[j];
				newPoint = j;
			}
		}
		mark[newPoint] = true;
		//cout << newPoint << endl;
	}

}
int main()
{
	Ini();
	cin >> cap >> n >> tar >> num;
	for (int i = 1; i <= n; i++)
	{
		cin >> Bike[i];
	}
	for (int i = 0; i < num; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		Edge t;
		t.next = u;
		t.cost = cost;
		edges[v].push_back(t);

		t.next = v;
		edges[u].push_back(t);
	}
	path[0] = -1;
	int ans[501];
	Dij();
	int cnt = 0;
	int t = tar;
	while (path[t] != -1)
	{
		ans[cnt++] = t;
		t = path[t];
	}
	//cout << dis[tar] << endl;
	cout << send[tar] << " " << 0;
	for (int i = cnt - 1; i >= 0; i--)
	{
		cout << "->" << ans[i];
	}
	cout << " " << back[tar] << endl;
	system("pause");
	return 0;
}