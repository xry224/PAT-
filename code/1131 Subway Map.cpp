#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <limits.h>
using namespace std;
class Station
{
public:
	int lineNo;
	int staNo;
	Station()
	{

	}
	Station(int a, int b)
	{
		lineNo = a;
		staNo = b;
	}
};
class Segment
{
public:
	int start;
	int end;
	int line;
	Segment()
	{

	}
	Segment(int a, int b, int c)
	{
		start = a;
		end = b;
		line = c;
	}
};
class Map
{
public:
	vector<Station> list;
	Map()
	{

	}
};
class Route
{
public:
	vector<Segment> section;
	int len;
	bool operator <(const Route &A) const
	{
		if (len == A.len)
		{
			return section.size() < A.section.size();
		}
		return len < A.len;
	}
	Route()
	{
		len = INT_MAX;
	}
};
Route ans;
Route curroute;
Map Subway[10005];
bool visit[10005];
void dfs(int cur, int des)
{
	if (cur == des)
	{
		if (curroute < ans)
		{
			ans = curroute;
		}
		return;
	}
	if (ans < curroute)
	{
		return;
	}
	for (int i = 0; i < Subway[cur].list.size(); i++)
	{
		Station next = Subway[cur].list[i];
		int nextsta = next.staNo;
		if (!visit[nextsta])
		{
			Route t = curroute;
			curroute.len++;
			if (next.lineNo == curroute.section.back().line)
			{
				curroute.section.back().end = nextsta;
			}
			else
			{
				curroute.section.push_back(Segment(cur, nextsta, next.lineNo));
			}
			visit[nextsta] = true;
			dfs(nextsta, des);
			//»ØËÝ
			visit[nextsta] = false;
			curroute = t;
		}
	}
}
void Ini()
{
	memset(visit, false, sizeof(visit));
	ans.len = INT_MAX;
	ans.section.clear();
	curroute.len = 0;
	curroute.section.clear();
	curroute.section.push_back(Segment(-1, -1, -1));
}
int main()
{
	int n;
	int m;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		int preNo;
		cin >> preNo;
		for (int j = 1; j < m; j++)
		{
			int no;
			cin >> no;
			Subway[preNo].list.push_back(Station(i, no));
			Subway[no].list.push_back(Station(i, preNo));
			preNo = no;
		}
	}
	int query;
	cin >> query;
	for (int i = 0; i < query; i++)
	{
		int start, des;
		cin >> start >> des;
		Ini();
		dfs(start, des);
		cout << ans.len << endl;
		for (int i = 1; i < ans.section.size(); i++)
		{
			printf("Take Line#%d from %04d to %04d.\n", ans.section[i].line, ans.section[i].start, ans.section[i].end);
		}
	}
	
	system("pause");
	return 0;
}