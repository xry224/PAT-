#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
int sum = 0;
int rate[24];
struct Date
{
	int month;
	int day;
	int hour;
	int minute;
	bool operator < (const Date &A) const
	{
		if (month == A.month)
		{
			if (day == A.day)
			{
				if (hour == A.hour)
				{
					return minute < A.minute;
				}
				return hour < A.hour;
			}
			return day < A.day;
		}
		return month < A.month;
	}
	bool equal(Date A)
	{
		return (A.day == day && A.hour == hour && A.minute == minute);
	}
	void operator ++ ()
	{
		minute++;
		if (minute >= 60)
		{
			minute -= 60;
			hour++;
			if (hour >= 24)
			{
				hour -= 24;
				day++;
			}
		}
	}
	Date operator + (int t)
	{
		Date res;
		res.minute = minute;
		res.day = day;
		res.hour = hour;
		res.minute = minute + t;
		if (res.minute >= 60)
		{
			res.minute -= 60;
			res.hour++;
			if (res.hour >= 24)
			{
				res.hour -= 24;
				res.day++;
			}
		}
		return res;
	}
};
struct Record
{
	string name;
	Date date;
	bool status;
	bool operator < (const Record &A)const
	{
		/*if (name == A.name)
		{
			return date < A.date;
		}
		return name < A.name;*/
		return date < A.date;
	}
};
double CalMoney(Date d1, Date d2)
{
	double m = 0;
	Date t = d1;
	while (!t.equal(d2))
	{
		int toll = rate[t.hour];
		m += toll;
		t = t + 1;
	}
	return m / 100;
}
int CalLen(Date d1, Date d2)
{
	int ans = 0;
	Date t = d1;
	while (!t.equal(d2))
	{
		ans++;
		t = t + 1;
	}
	return ans;
}
void Solve(Record rec[], int len)
{
	double total = 0;
	//false表示上一个
	bool flag = rec[0].status;
	bool first = true;
	int last = 0;
	double cur = 0;
	for (int i = 1; i < len; i++)
	{
		if (flag == true && rec[i].status == false)
		{
			cur = CalMoney(rec[last].date , rec[i].date);
			Date d1 = rec[last].date;
			Date d2 = rec[i].date;
			total += cur;
			int len = CalLen(d1, d2);
			if (first)
			{
				printf("%s %02d\n", rec[0].name.c_str(), rec[0].date.month);
				first = false;
			}
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.02f\n", d1.day, d1.hour, d1.minute, d2.day, d2.hour, d2.minute, len, cur);
			flag = false;
		}
		else if (rec[i].status == true)
		{
			flag = true;
			last = i;
		}
	}
	if (!first)
	{
		printf("Total amount: $%.02f\n", total);
	}
}
int main()
{
	int n;
	for (int i = 0; i < 24; i++)
	{
		cin >> rate[i];
		sum += rate[i];
	}
	cin >> n;
	Record rec[1001];
	int mouth, day, hour, minute;
	string name, status;
	string customer[1001];
	int cnt = 0;
	map<string, int> m;
	for (int i = 0; i < n; i++)
	{
		Date t;
		cin >> name;
		m[name]++;
		if (m[name] == 1)
		{
			customer[cnt++] = name;
		}
		scanf("%d:%d:%d:%d", &mouth, &day, &hour, &minute);
		cin >> status;
		t.month = mouth;
		t.day = day;
		t.hour = hour;
		t.minute = minute;
		rec[i].name = name;
		rec[i].status = status == "on-line" ? true : false;
		rec[i].date = t;
	}
	sort(rec, rec + n);
	sort(customer, customer + cnt);
	Record t[1001];
	for (int i = 0; i < cnt; i++)
	{
		int reccnt = 0;
		string tname = customer[i]; 
		for (int i = 0; i < n; i++)
		{
			if (rec[i].name == tname)
			{
				t[reccnt++] = rec[i];
			}
		}
		Solve(t, reccnt);
	}
	system("pause");
	return 0;
}