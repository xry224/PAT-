#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
class People
{
public:
	int ID;
	vector<int> boyfriend;
	vector<int> girlfriend;
	bool gender;   //ture为女性，false为男性
	People()
	{

	}
	void AddFriend(string fid)
	{
		int id = abs(atoi(fid.c_str()));
		if (fid.length() == 5)
		{
			girlfriend.push_back(id);
		}
		else
		{
			boyfriend.push_back(id);
		}
	}
}friendship[10005];
class ansPair
{
public:
	int first;
	int second;
	ansPair()
	{

	}
	ansPair(int a, int b)
	{
		first = a;
		second = b;
	}
	bool operator < (const ansPair &A) const
	{
		if (first == A.first)
		{
			return second < A.second;
		}
		return first < A.first;
	}
};
void SolveSame(string a, string b)
{
	int id1 = abs(atoi(a.c_str()));
	int id2 = abs(atoi(b.c_str()));
	bool gender = friendship[id1].gender;
	vector<ansPair> ans;
	if (gender)//均是女孩
	{
		for (int i = 0; i < friendship[id1].girlfriend.size(); i++)
		{
			int friendid = friendship[id1].girlfriend[i];
			if (friendid == id2 || friendid == id1)
			{
				continue;
			}
			for (int j = 0; j < friendship[friendid].girlfriend.size(); j++)
			{
				int secondid = friendship[friendid].girlfriend[j];
				if (secondid == id2 || secondid == id1)
				{
					continue;
				}
				for (int k = 0; k < friendship[secondid].girlfriend.size(); k++)
				{
					int id = friendship[secondid].girlfriend[k];
					if (id == id2)
					{
						ans.push_back(ansPair(friendid, secondid));
						break;
					}
				}
			}
		}
	}
	else  //均是男孩
	{
		for (int i = 0; i < friendship[id1].boyfriend.size(); i++)
		{
			int friendid = friendship[id1].boyfriend[i];
			if (friendid == id2 || friendid == id1)
			{
				continue;
			}
			for (int j = 0; j < friendship[friendid].boyfriend.size(); j++)
			{
				int secondid = friendship[friendid].boyfriend[j];
				if (secondid == id2 || secondid == id1)
				{
					continue;
				}
				for (int k = 0; k < friendship[secondid].boyfriend.size(); k++)
				{
					int id = friendship[secondid].boyfriend[k];
					if (id == id2)
					{
						ans.push_back(ansPair(friendid, secondid));
						break;
					}
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%04d %04d\n", ans[i].first, ans[i].second);
	}
}
void SolveDiff(string a, string b)
{
	int id1 = abs(atoi(a.c_str()));
	int id2 = abs(atoi(b.c_str()));
	bool gender = friendship[id1].gender;
	vector<ansPair> ans;
	if (gender)   //女找男
	{
		for (int i = 0; i < friendship[id1].girlfriend.size(); i++)
		{
			int firstid = friendship[id1].girlfriend[i];
			if (firstid == id1)
			{
				continue;
			}
			for (int j = 0; j < friendship[firstid].boyfriend.size(); j++)
			{
				int secondid = friendship[firstid].boyfriend[j];
				if (secondid == id2)
				{
					continue;
				}
				for (int k = 0; k < friendship[secondid].boyfriend.size(); k++)
				{
					int id = friendship[secondid].boyfriend[k];
					if (id == id2)
					{
						ans.push_back(ansPair(firstid, secondid));
					}
				}
			}
		}
	}
	else   //男找女
	{
		for (int i = 0; i < friendship[id1].boyfriend.size(); i++)
		{
			int firstid = friendship[id1].boyfriend[i];
			if (firstid == id1)
			{
				continue;
			}
			for (int j = 0; j < friendship[firstid].girlfriend.size(); j++)
			{
				int secondid = friendship[firstid].girlfriend[j];
				if (secondid == id2)
				{
					continue;
				}
				for (int k = 0; k < friendship[secondid].girlfriend.size(); k++)
				{
					int id = friendship[secondid].girlfriend[k];
					if (id == id2)
					{
						ans.push_back(ansPair(firstid, secondid));
					}
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%04d %04d\n", ans[i].first, ans[i].second);
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		string a, b;
		//int a, b;
		cin >> a >> b;
		int id1 = abs(atoi(a.c_str()));
		int id2 = abs(atoi(b.c_str()));
		friendship[id1].AddFriend(b);
		friendship[id1].ID = id1;
		friendship[id1].gender = a.length() == 5;

		friendship[id2].AddFriend(a);
		friendship[id2].ID = id2;
		friendship[id2].gender = b.length() == 5;
	}
	int	query;
	cin >> query;
	for (int i = 0; i < query; i++)
	{
		string a, b;
		cin >> a >> b;
		int id1 = abs(atoi(a.c_str()));
		int id2 = abs(atoi(b.c_str()));
		if (friendship[id1].gender == friendship[id2].gender)
		{
			SolveSame(a, b);
		}
		else
		{
			SolveDiff(a, b);
		}
	}
	system("pause");
	return 0;
}