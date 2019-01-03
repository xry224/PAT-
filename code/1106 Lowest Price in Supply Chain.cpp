#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
	int type;
	vector<int> next;
	Node()
	{
		type = 1;
	}
}supply[100005];
int main()
{
	int n;
	double price, rate;
	scanf("%d %lf %lf", &n, &price, &rate);
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == 0)
		{
			supply[i].type = 0;
		}
		else
		{
			for (int j = 0; j < t; j++)
			{
				int mem;
				scanf("%d", &mem);
				supply[i].next.push_back(mem);
			}
		}
	}
	queue<Node> q;
	q.push(supply[0]);
	int level = 0;
	int cnt = 0;
	double ans;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			Node t = q.front();
			q.pop();
			if (t.type == 1)
			{
				for (int i = 0; i < t.next.size(); i++)
				{
					q.push(supply[t.next[i]]);
				}
			}
			else
			{
				cnt++;
			}
		}
		if (cnt != 0)
		{
			ans = pow(1 + rate / 100.0, level) * price;
			break;
		}
		level++;
	}
	printf("%.4lf %d\n", ans, cnt);
	system("pause");
	return 0;
}