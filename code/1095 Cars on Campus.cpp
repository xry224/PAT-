#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include<vector>
#include<algorithm>
using namespace std;
class Time
{
public:
	int hour;
	int minute;
	int second;
	Time()
	{
		hour = -1;
		minute = -1;
		second = -1;
	}
	Time(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
	}
	void Ouput()
	{
		printf("%02d:%02d:%02d\n", hour, minute, second);
	}
	Time operator - (const Time &A) const
	{
		Time ans;
		ans.second = second - A.second;
		ans.minute = minute - A.minute;
		ans.hour = hour - A.hour;
		if (ans.second < 0)
		{
			ans.minute--;
			ans.second += 60;
		}
		if (ans.minute < 0)
		{
			ans.hour--;
			ans.minute += 60;
		}
		return ans;
	}
	bool operator < (const Time &A) const
	{
		if (hour == A.hour)
		{
			if (minute == A.minute)
			{
				return second < A.second;
			}
			return minute < A.minute;
		}
		return hour < A.hour;
	}
	bool operator == (const Time &A) const
	{
		return second == A.second && minute == A.minute && hour == A.hour;
	}
};
class Node
{
public:
	string id;
	Time in;
	Time out;
	Time parked;
	Node()
	{
		
	}
	bool operator < (const Node& A)const
	{
		if (parked == A.parked)
		{
			return id < A.id;
		}
		return A.parked < parked;
	}
}cars[10005];
bool cmp(Node A, Node B)
{
	return A.in < B.in;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string id;
	int hour, minute, second;
	string status;
	map<string, int> name2id;
	int idnum = 1;
	vector<Node> park;
	vector<Node>::iterator it;
	for (int i = 0; i < n; i++)
	{
		cin >> id;
		if (name2id[id] == 0)
		{
			name2id[id] = idnum;
			idnum++;
		}
		int index = name2id[id];
		cars[index].id = id;
		//cout << index << endl;
		scanf("%d:%d:%d", &hour, &minute, &second);
		cin >> status;
		if (status == "in")
		{
			cars[index].in.hour = hour;
			cars[index].in.minute = minute;
			cars[index].in.second = second;

			if (cars[index].out.hour != -1)
			{
				cars[index].parked = cars[index].out - cars[index].in;
				bool flag = false;
				for (int j = 0; j < park.size(); j++)
				{
					if (park[j].id == id)
					{
						park[j] = cars[index];
						flag = true;
					}
				}
				if (!flag)
				{
					park.push_back(cars[index]);
				}

			}
		}
		else
		{
			if (cars[index].out.hour == -1)
			{
				Time t = Time(hour, minute, second);
				if (cars[index].in < t)
				{
					cars[index].out = t;
					if (cars[index].in.hour != -1)
					{
						cars[index].parked = cars[index].out - cars[index].in;
						park.push_back(cars[index]);
					}
				}
			}
		}
	}
	sort(park.begin(), park.end(), cmp);
	int rem = 0;
	for (int i = 0; i < k; i++)
	{

		int cnt = 0;
		scanf("%d:%d:%d", &hour, &minute, &second);
		Time t = Time(hour, minute, second);
		for (int j = 0; j < park.size(); j++)
		{
			if ((park[j].in < t || park[j].in == t) && (t < park[j].out))
			{
				/*if (cnt == 0)
				{
					rem = j;
				}*/
				cnt++;
			}
			if (t < park[j].in)
			{
				break;
			}
		}
		cout << cnt << endl;
	}
	sort(park.begin(), park.end());
	Time t = park[0].parked;
	for (int i = 0; i < park.size(); i++)
	{
		if (!(park[i].parked == t))
		{
			break;
		}
		cout << park[i].id << " ";
	}
	t.Ouput();
	system("pause");
	return 0;
}