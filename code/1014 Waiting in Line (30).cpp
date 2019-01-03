#pragma disable(warning:4996)
#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	int time[1001];
	int cost[1001] = { -1 };
	bool inQue[1001];
	int n, m, k, q;
	int query;
	memset(inQue, false, sizeof(inQue));
	queue<int> que[20];
	cin >> n >> m >> k >> q;
	for (int i = 1; i <= k; i++)
	{
		cin >> time[i];
		cost[i] = -1;
	}

	for (int now = 0; now < 540; now++)
	{
		//判断是否某个队列的第一个人的被服务时间为当前时间
		for (int i = 0; i < n; i++)
		{
			if (que[i].empty())
			{
				continue;
			}
			//当前队列队首客户完成服务的时间等于当前时间
			if (cost[que[i].front()] == now)
			{
				que[i].pop();
				if (!que[i].empty())
				{
					//计算当前队列下一个客户完成服务的时间
					cost[que[i].front()] = now + time[que[i].front()];
				}
			}
		}

		//将未在队列中的客户加入未满队列
		for (int i = 1; i <= k; i++)
		{
			//已经在队列中
			if (inQue[i])
			{
				continue;
			}
			int cur = 20;
			int choose = -1;
			//寻找未满且人数最少的队列
			for (int j = 0; j < n; j++)
			{
				if (que[j].size() < m && cur > que[j].size())
				{
					cur = que[j].size();
					choose = j;
				}
			}
			//全部队列满
			if (choose == -1)
			{
				break;
			}
			que[choose].push(i);
			if (que[choose].size() == 1)
			{
				cost[i] = now + time[i];
			}
			inQue[i] = true;
		}
	
	}
	for (int i = 0; i < q; i++)
	{
		cin >> query;
		if (cost[query] == -1)
		{
			cout << "Sorry" << endl;
		}
		else
		{
			int time = cost[query];
			int hour = time / 60 + 8;
			int minute = time % 60;
			printf("%02d:%02d\n", hour, minute);
		}
		
	}
	system("pause");
	return 0;
}