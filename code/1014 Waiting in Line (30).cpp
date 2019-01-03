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
		//�ж��Ƿ�ĳ�����еĵ�һ���˵ı�����ʱ��Ϊ��ǰʱ��
		for (int i = 0; i < n; i++)
		{
			if (que[i].empty())
			{
				continue;
			}
			//��ǰ���ж��׿ͻ���ɷ����ʱ����ڵ�ǰʱ��
			if (cost[que[i].front()] == now)
			{
				que[i].pop();
				if (!que[i].empty())
				{
					//���㵱ǰ������һ���ͻ���ɷ����ʱ��
					cost[que[i].front()] = now + time[que[i].front()];
				}
			}
		}

		//��δ�ڶ����еĿͻ�����δ������
		for (int i = 1; i <= k; i++)
		{
			//�Ѿ��ڶ�����
			if (inQue[i])
			{
				continue;
			}
			int cur = 20;
			int choose = -1;
			//Ѱ��δ�����������ٵĶ���
			for (int j = 0; j < n; j++)
			{
				if (que[j].size() < m && cur > que[j].size())
				{
					cur = que[j].size();
					choose = j;
				}
			}
			//ȫ��������
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