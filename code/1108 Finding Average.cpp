#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace std;
#define ERROR -2000
bool isAllNum(string str)
{
	if (str[0] == '-' || str[0] == '+')
	{
		str = str.substr(1);
	}
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			if (i == 0)
			{
				return false;
			}
			cnt++;
			continue;
		}
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return false;
		}
	}
	if (cnt > 1)
	{
		return false;
	}
	return true;
}
double isLegal(string str)
{
	if (!isAllNum(str))
	{
		return ERROR;
	}
	int index = str.find(".");
	if (index != string::npos)
	{
		if (str.length() - 1 - index > 2)
		{
			return ERROR;
		}
	}
	double t = atof(str.c_str());
	if (t < -1000 || t > 1000)
	{
		return ERROR;
	}
	return t;
}
int main()
{
	int n;
	double sum = 0;
	int cnt = 0;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		double res = isLegal(str);
		if (res != ERROR)
		{
			cnt++;
			sum += res;
		}
		else
		{
			cout << "ERROR: " << str << " is not a legal number" << endl;
		}
	}
	if (cnt == 0)
	{
		cout << "The average of 0 numbers is Undefined" << endl;
	}
	else if (cnt == 1)
	{
		cout << fixed << setprecision(2) << "The average of 1 number is " << sum / (double)cnt << endl;
	}
	else
	{
		cout << "The average of " << cnt << " numbers is " << fixed << setprecision(2) << sum / (double)cnt << endl;
	}
	system("pause");
	return 0;
}