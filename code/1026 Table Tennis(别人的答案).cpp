#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdio.h>

using namespace std;

typedef struct Node
{
	int arrive, process, tag;
	int serve, wait; // serve和wait分别代表服务开始时间和等待时间，将serve初始化为INF，从而区分有没有被服务
}Node;
typedef struct Table
{
	int tag;
	int freeTime, num; // 每个桌子记录自己的空闲时间和服务数，全部初始化为上午8:00，这样可以迭代着处理
}Table;
bool CmpArrive(Node a, Node b) // 用于对用户的到达时间升序排序
{
	return a.arrive < b.arrive;
}
bool CmpServe(Node a, Node b) // 对用户按照时间顺序排列，优先按照服务时间排序，如果服务同时开始（多个空桌），按照到达时间升序
{
	if(a.serve == b.serve)
		return a.arrive < b.arrive;
	else return a.serve < b.serve;
}
#define INF 0x6FFFFFFF

vector<Node> user;
vector<Table> table;
void UpdateInfo(int userID, int tableID)
{
	user[userID].serve = max(user[userID].arrive, table[tableID].freeTime);
	user[userID].wait = user[userID].serve-user[userID].arrive;
	table[tableID].num++;
	table[tableID].freeTime = user[userID].serve+min(user[userID].process, 7200); // 最长服务时间为2小时
}
int main()
{
	//input
	int n;
	scanf("%d",&n);

	user.resize(n);
	for(int i = 0; i < n; ++i)
	{
		int h, m, s;
		scanf("%d:%d:%d %d%d",&h,&m,&s,&user[i].process,&user[i].tag);
		user[i].arrive = h*3600+m*60+s;
		user[i].process *= 60;
		user[i].serve = INF; user[i].wait = INF; // 初始化为INF，INF就代表未被处理
	}
	int k, m;
	scanf("%d%d",&k,&m);

	table.resize(k);
	for(int i = 0; i < k; ++i)
		table[i].freeTime = 8*3600, table[i].tag = 0, table[i].num = 0; // 所有桌子从上午8:00开始可用
	for(int i = 0; i < m; ++i)
	{
		int c;
		scanf("%d",&c); c--;
		table[c].tag = 1;
	}
	//process
	sort(user.begin(), user.end(), CmpArrive); // 按照到达时间升序排列，符合排队规则
	//visited.assign(n, false);
	for(int i = 0; i < n; ++i)
	{
		if(user[i].serve != INF) continue; // server时间初始化为INF，不为INF的已经服务完毕。
		int minFreeTime = INF;
		for(int j = 0; j < k; ++j)
			minFreeTime = min(minFreeTime, table[j].freeTime); // 找出最早空闲的桌子
		int timePoint = max(user[i].arrive, minFreeTime); // 根据队头用户确定当前最早服务时间点
		if(timePoint >= 21*3600) break; // 判断是否超过营业时间
		vector<int> userList;
		vector<int> tableList;
		for(int j = i; j < n; ++j) // 根据最早服务时间点找到所有可能被服务的人，是为了处理有VIP优先去VIP桌的情况。
			if(user[j].serve == INF && user[j].arrive <= timePoint) userList.push_back(j);
		for(int j = 0; j < k; ++j) // 找出所有在时间点之前空闲的桌子，因为可能用户到达晚，因此会有多个桌子空闲
			if(table[j].freeTime <= timePoint) tableList.push_back(j);

		bool flag = false; // 判断是否处理了一个服务
		// 首先特殊处理VIP，如果没有VIP被处理则处理一个普通用户，每次只处理一个
		if(userList.size() == 1 && tableList.size() > 1) // 单个用户多个桌子，用户为VIP则去找编号最小的VIP桌
		{
			if(user[userList[0]].tag == 1)
			{
				for(int j = 0; j < tableList.size(); ++j)
				{
					if(table[tableList[j]].tag == 1)
					{
						flag = true;
						UpdateInfo(userList[0], tableList[j]);
						break;
					}
				}
			}
		}
		else if(tableList.size() == 1 && userList.size() > 1) // 多人单桌情况，如果为VIP桌找多人中最先到达的VIP为其服务
		{
			if(table[tableList[0]].tag == 1)
			{
				for(int j = 0; j < userList.size(); ++j)
				{
					if(user[userList[j]].tag == 1)
					{
						flag = true;
						UpdateInfo(userList[j], tableList[0]);
						break;
					}
				}
			}
		}
		else if(tableList.size() > 1 && userList.size() > 1) // 多人多桌情况，先找桌子中的VIP桌，有则找用户中最先到达的VIP
		{
			for(int t = 0; t < tableList.size(); ++t)
			{
				if(table[tableList[t]].tag == 1)
				{
					for(int u = 0; u < userList.size(); ++u)
					{
						if(user[userList[u]].tag == 1)
						{
							flag = true;
							UpdateInfo(userList[u], tableList[t]);
							break;
						}
					}
				}
			}
		}
		if(!flag) UpdateInfo(userList[0], tableList[0]); // 如果没有VIP被处理，则按照正常情况处理。
		--i;
	}
	//output
	sort(user.begin(), user.end(), CmpServe);
	for(int i = 0; i < n; ++i)
	{
		if(user[i].serve >= 21*3600) break;
		int h1, m1, s1, h2, m2, s2;
		int t = user[i].arrive;
		h1 = t/3600; t %= 3600;
		m1 = t/60; t %= 60;
		s1 = t;
		t = user[i].serve;
		h2 = t/3600; t %= 3600;
		m2 = t/60; t %= 60;
		s2 = t;
		// 注意对等待时间的四舍五入为超过30秒算作一分钟
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", h1, m1, s1, h2, m2, s2, (user[i].wait+30)/60);
	}
	for(int i = 0; i < k; ++i)
	{
		if(i != k-1)
			printf("%d ",table[i].num);
		else printf("%d\n",table[i].num);
	}
	return 0;
}
