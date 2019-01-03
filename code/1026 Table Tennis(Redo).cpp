#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <stdio.h>
using namespace std;
#define TotalTime 13*60*60
class Table
{
public:
	int ID;
	int avaliable;
	int cnt;
	bool vip;
	Table()
	{
		avaliable = 8 * 3600;
		cnt = 0;
	}
};
class Pair
{
public:
	int isVIP;
	int arrive;
	int serve;
	int playInsec;
	Pair()
	{
		serve = 0;
	}
};
Table tables[101];
bool cmp1(Pair A, Pair B)
{
	return A.arrive < B.arrive;
}
bool cmp2(Pair A, Pair B)
{
	return A.serve < B.serve;
}
void printTime(int sec)
{
	int hour = sec / 3600;
	int minute = sec % 3600 / 60;
	int second = sec % 60;
	printf("%02d:%02d:%02d", hour, minute, second);
}
vector<Pair> ori;
vector<Pair> Vip;
vector<Pair> ans;
vector<Pair> user;
int main()
{
	int n;
	cin >> n;
	Pair players;
	for (int i = 0; i < n; i++)
	{
		int h, m, s, ser, vip;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &ser, &vip);
		if (ser > 120)
		{
			ser = 120;
		}
		players.arrive = h * 3600 + m * 60 + s;
		players.isVIP = vip;
		players.playInsec = ser * 60;
		players.serve = 24 * 3600 * 60;
		if (players.arrive >= 21 * 3600)
		{
			continue;
		}
		user.push_back(players);
		/*
		if (vip == 1)
		{
			Vip.push_back(players);
		}
		else
		{
			ori.push_back(players);
		}*/
	}
	int m, k;
	cin >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		tables[i].ID = i;
	}

	for (int i = 0; i < k; i++)
	{
		int cur;
		cin >> cur;
		tables[cur].vip = true;
	}
	//将所有玩家按到来时间排列
	/*sort(ori.begin(), ori.end(), cmp1);
	sort(Vip.begin(), Vip.end(), cmp1);*/
	sort(user.begin(), user.end(), cmp1);
	while (user.size() > 0)
	{
		vector <Pair> t;
		vector <Table> tl;
		int mintime = INT_MAX;
		for (int i = 1; i <= m; i++)
		{
			mintime = min(tables[i].avaliable, mintime);
		}
		int timepoint = max(mintime, user[0].arrive);
		if (timepoint >= 21 * 3600)
		{
			break;
		}
		for (int i = 1; i <= m; i++)
		{
			if (tables[i].avaliable <= timepoint)
			{
				tl.push_back(tables[i]);
			}
		}
		for (int i = 0; i < user.size(); i++)
		{
			if (user[i].arrive <= timepoint)
			{
				t.push_back(user[i]);
			}
		}
		bool flag = false;
		if (t.size() == 1 && tl.size() > 1)
		{
			if (t.front().isVIP)
			{

			}
		}

	}

	sort(ans.begin(), ans.end(), cmp2);
	//cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		printTime(ans[i].arrive);
		cout << " ";
		printTime(ans[i].serve);
		cout << " " << (ans[i].serve - ans[i].arrive + 30) / 60 << endl;
	}
	for (int i = 1; i < m; i++)
	{
		cout << tables[i].cnt << " ";
	}
	cout << tables[m].cnt << endl;
	system("pause");
	return 0;
}
/*
9
11:54:13 112 1
11:48:59 9 0
14:59:18 64 1
21:00:00 10 0
14:51:47 20 0
15:26:58 3 1
13:11:14 75 0
08:46:22 61 0
16:49:20 115 0
50 33
6 17 32 20 27 50 31 9 30 48 29 8 38 38 1 8 17 38 4 26 1 18 13 38 13 16 9 45 45 49 30 19 18*/
