#include <iostream>
#include <string>
using namespace std;
class Time
{
public:
	int hour;
	int minute;
	int second;
	Time()
	{

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
	bool operator > (const Time &A) const
	{
		if (hour == A.hour)
		{
			if (minute == A.minute)
			{
				return second > A.second;
			}
			return minute > A.minute;
		}
		return hour > A.hour;
	}
};
Time getTime(string time)
{
	Time t;
	t.hour = (time[0] - '0') * 10 + time[1] - '0';
	t.minute = (time[3] - '0') * 10 + time[4] - '0';
	t.second = (time[6] - '0') * 10 + time[7] - '0';
	return t;
}
int main()
{
	int n;
	Time ansin, ansout, curin, curout;
	string ans1, ans2;
	cin >> n;
	string name, in, out;
	cin >> name >> in >> out;
	ans1 = ans2 = name;
	ansin = getTime(in);
	ansout = getTime(out);
	for (int i = 1; i < n; i++)
	{
		cin >> name >> in >> out;
		curin = getTime(in);
		curout = getTime(out);
		if (curin < ansin)
		{
			ans1 = name;
			ansin = curin;
		}
		if (curout > ansout)
		{
			ans2 = name;
			ansout = curout;
		}
	}
	cout << ans1 << " " << ans2 << endl;
	system("pause");
	return 0;
}