#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Cus
{
	int arrsec;
	int cost;
	bool operator < (const Cus &A) const
	{
		return arrsec < A.arrsec;
	}
}Customer[10001];
int window[101];
int getNum(string str, int index)
{
	int t = 0;
	t = (str[index] - '0') * 10 + (str[index + 1] - '0');
	return t;
}
int findWindow(int sec, int m)
{
	for (int i = 1; i <= m; i++)
	{
		if (window[i] <= sec)
		{
			return i;
		}
	}
	return -1;
}
int findEar(int sec, int m)
{
	int cur = 1;
	for (int i = 2; i <= m; i++)
	{
		if (window[i] < window[cur])
		{
			cur = i;
		}
	}
	return cur;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		window[i] = 8 * 3600;
	}
	int cnt = 0;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		string time;
		int cost;
		cin >> time >> cost;
		if (time > "17:00:00")
		{
			continue;
		}
		Customer[cnt].cost = cost * 60;
		int hour = getNum(time, 0);
		int minute = getNum(time, 3);
		int sec = getNum(time, 6);
		Customer[cnt].arrsec = sec + minute * 60 + hour * 3600;
		cnt++;
	}
	sort(Customer, Customer + cnt);
	for (int i = 0; i < cnt; i++)
	{
		int win = findWindow(Customer[i].arrsec, m);
		if (win != -1)
		{
			if (Customer[i].arrsec < 8 * 3600)
			{
				window[win] = 8 * 3600 + Customer[i].cost;
			}
			else
			{
				window[win] = Customer[i].arrsec + Customer[i].cost;
			}
		}
		else
		{
			win = findEar(Customer[i].arrsec, m);
			total += window[win] - Customer[i].arrsec;
			window[win] = window[win] + Customer[i].cost;
		}
		cout << total << endl;
	}
	cout << fixed << setprecision(1) << (total*1.0 / 60 / cnt) << endl;
	system("pause");
	return 0;
}