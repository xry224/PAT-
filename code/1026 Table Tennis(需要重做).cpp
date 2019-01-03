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
		if (vip == 1)
		{
			Vip.push_back(players);
		}
		else
		{
			ori.push_back(players);
		}
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
	sort(ori.begin(), ori.end(), cmp1);
	sort(Vip.begin(), Vip.end(), cmp1);
	while (Vip.size() > 0 || ori.size() > 0)
	{
		int mintime = INT_MAX;
		int minVIP = INT_MAX;
		//index：全部桌子中最早可以使用的
		//vipindex：vip桌子中最早可以使用的，vipindex的时间大于等于index的时间
		int index = -1, vipindex = -1;
		for (int i = 1; i <= m; i++)
		{
			if (tables[i].avaliable < mintime)
			{
				mintime = tables[i].avaliable;
				index = i;
			}
			if (tables[i].avaliable < minVIP && tables[i].vip)
			{
				minVIP = tables[i].avaliable;
				vipindex = i;
			}
		}
		if (tables[index].avaliable >= 21 * 3600)
		{
			break;
		}
		Pair next;
		if (ori.size() == 0)
		{
			next = Vip.front();
			Vip.erase(Vip.begin());
		}
		else if (Vip.size() == 0)
		{
			next = ori.front();
			ori.erase(ori.begin());
		}
		else
		{
			//最早可用的桌子是VIP桌子
			if (tables[index].vip)
			{
				Pair v = Vip.front();
				Pair o = ori.front();
				//vip用户来得早，或者其来的时间比vip桌子可用时间早或刚好
				if (v.arrive < o.arrive || v.arrive <= tables[index].avaliable)
				{
					next = Vip.front();
					Vip.erase(Vip.begin());
				}
				else
				{
					next = ori.front();
					ori.erase(ori.begin());
				}
			}
			//不是VIP桌子
			else
			{
				Pair v = Vip.front();
				Pair o = ori.front();
				//普通桌子先到先得
				if (v.arrive < o.arrive)
				{
					next = Vip.front();
					Vip.erase(Vip.begin());
				}
				else
				{
					next = ori.front();
					ori.erase(ori.begin());
				}
			}
		}
			//判断当前最早可用VIP桌是否能立即使用且下一位用户是否为VIP
			if (next.isVIP == 1 && tables[vipindex].avaliable <= next.arrive)
			{
				next.serve = next.arrive;
				tables[vipindex].cnt++;
				tables[vipindex].avaliable = next.arrive + next.playInsec;
			}
			else
			{
				//下一个被服务用户来的时间比当前最先可用桌子时间晚
				if (next.arrive > tables[index].avaliable)
				{
					next.serve = next.arrive;
					tables[index].cnt++;
					tables[index].avaliable = next.arrive + next.playInsec;
				}
				else
				{
					//cout << next.arrive <<" "<< tables[index].avaliable << endl;
					next.serve = tables[index].avaliable;
					tables[index].cnt++;
					tables[index].avaliable = tables[index].avaliable + next.playInsec;
				}
			}
		ans.push_back(next);
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
/*#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <limits.h>
using namespace std;

struct players
{
	int arriveTime;
	int startServe;
	int serveTime;
	int waitTime;
	int isVIP;
};
//等待队列中的VIP客户
vector<players >vipPlayers;
//普通客户
vector<players >ordinaryPlayers;
//处理完输出信息的客户
vector<players >total;
struct tables
{
	int VIP;
	int cnt;
	int vacantTime;
};
tables t[101];

bool cmpPlayers(players a, players b)
{
	return a.arriveTime<b.arriveTime;
}

bool cmpStartServe(players a, players b)
{
	return a.startServe<b.startServe;
}

int main()
{
	int N, K, M, i = 0;
	cin >> N;
	int hh, mm, ss, wait, vip;
	players temp;
	while (i<N)
	{
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &wait, &vip);
		temp.arriveTime = hh * 3600 + mm * 60 + ss;
		temp.serveTime = wait * 60;
		temp.isVIP = vip;
		i++;
		if (temp.arriveTime >= 3600 * 21)continue;
		if (vip == 1)vipPlayers.push_back(temp);
		else ordinaryPlayers.push_back(temp);
	}
	cin >> K >> M;
	for (int j = 1; j <= K; j++)
	{
		t[j].VIP = 0;
		t[j].vacantTime = 8 * 3600;
		t[j].cnt = 0;
	}
	int tag;
	for (int j = 0; j<M; j++)
	{
		cin >> tag;
		t[tag].VIP = 1;
	}

	if (ordinaryPlayers.size()>0)sort(ordinaryPlayers.begin(), ordinaryPlayers.end(), cmpPlayers);
	if (vipPlayers.size()>0)sort(vipPlayers.begin(), vipPlayers.end(), cmpPlayers);

	while (ordinaryPlayers.size()>0 || vipPlayers.size()>0)
	{
		int minVacant = INT_MAX;
		int minVipVacant = INT_MAX;
		int index;
		int vipIndex;
		for (int j = 1; j <= K; j++)
		{
			if (t[j].vacantTime<minVacant)
			{
				minVacant = t[j].vacantTime;
				index = j;
			}
			if (t[j].VIP == 1 && t[j].vacantTime<minVipVacant)
			{
				minVipVacant = t[j].vacantTime;
				vipIndex = j;
			}
		}
		if (t[index].vacantTime >= 21 * 3600)break;
		players nextPlayers;
		if (vipPlayers.size() == 0)
		{
			nextPlayers = ordinaryPlayers.front();
			ordinaryPlayers.erase(ordinaryPlayers.begin());
		}
		else if (ordinaryPlayers.size() == 0)
		{
			nextPlayers = vipPlayers.front();
			vipPlayers.erase(vipPlayers.begin());
		}
		else
		{
			if (t[index].VIP == 1)
			{
				if (vipPlayers.front().arriveTime<ordinaryPlayers.front().arriveTime || t[index].vacantTime >= vipPlayers.front().arriveTime)
				{
					nextPlayers = vipPlayers.front();
					vipPlayers.erase(vipPlayers.begin());
				}
				else
				{
					nextPlayers = ordinaryPlayers.front();
					ordinaryPlayers.erase(ordinaryPlayers.begin());
				}
			}
			else
			{
				if (vipPlayers.front().arriveTime<ordinaryPlayers.front().arriveTime)
				{
					nextPlayers = vipPlayers.front();
					vipPlayers.erase(vipPlayers.begin());
				}
				else
				{
					nextPlayers = ordinaryPlayers.front();
					ordinaryPlayers.erase(ordinaryPlayers.begin());
				}
			}
		}
		//控制每个人的时间在两小时之内,超过两小时按两个小时截断
		if (nextPlayers.serveTime>7200)nextPlayers.serveTime = 7200;
		//这里需要记清楚：一旦有VIP桌子空闲，等待队列中的VIP客户就会选择VIP桌子，不管是否有普通桌子空闲
		if (nextPlayers.isVIP == 1 && nextPlayers.arriveTime >= t[vipIndex].vacantTime)
		{
			nextPlayers.waitTime = 0;
			nextPlayers.startServe = nextPlayers.arriveTime;
			t[vipIndex].vacantTime = nextPlayers.arriveTime + nextPlayers.serveTime;
			t[vipIndex].cnt++;
		}
		else
		{
			if (nextPlayers.arriveTime <= t[index].vacantTime)
			{
				nextPlayers.waitTime = t[index].vacantTime - nextPlayers.arriveTime;
				nextPlayers.startServe = t[index].vacantTime;
				t[index].vacantTime += nextPlayers.serveTime;
			}
			else
			{
				nextPlayers.waitTime = 0;
				nextPlayers.startServe = nextPlayers.arriveTime;
				t[index].vacantTime = nextPlayers.arriveTime + nextPlayers.serveTime;
			}
			t[index].cnt++;
		}
		total.push_back(nextPlayers);
	}
	sort(total.begin(), total.end(), cmpStartServe);
	for (int i = 0; i<total.size(); i++)
	{
		int waitMinutes = total[i].waitTime / 60 + (total[i].waitTime % 60<30 ? 0 : 1);
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", total[i].arriveTime / 3600,
			(total[i].arriveTime % 3600) / 60, total[i].arriveTime % 60,
			total[i].startServe / 3600, (total[i].startServe % 3600) / 60,
			total[i].startServe % 60, waitMinutes);
	}
	int first = 1;
	for (int i = 1; i <= K; i++)
	{
		if (first)first = 0;
		else cout << " ";
		cout << t[i].cnt;
	}
	return 0;
}*/