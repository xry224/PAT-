#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
bool isCapital(char c)
{
	if (c <= 'Z' && c >= 'A')
	{
		return true;
	}
	return false;
}
bool isNum(char c)
{
	if (c <= '9' && c >= '0')
	{
		return true;
	}
	return false;
}
bool isLetter(char c)
{
	if ((c <= 'z' && c >= 'a') || isCapital(c))
	{
		return true;
	}
	return false;
}
int main()
{
	string days[] = { "MON","TUE","WED", "THU", "FRI", "SAT", "SUN" };
	string n1, n2, n3, n4;
	int day, hour, minute;
	bool flag = false;
	cin >> n1 >> n2 >> n3 >> n4;
	for (int i = 0; i < n1.length() && i < n2.length(); i++)
	{
		if (isCapital(n1[i]) && isCapital(n2[i]) && n1[i] == n2[i] && !flag)
		{
			day = n1[i] - 'A';
			if (day < 7)
			{
				flag = true;	
			}
			continue;
		}
		if (flag && n1[i] == n2[i])
		{
			if (isNum(n1[i]))
			{
				hour = n1[i] - '0';
				break;
			}
			else if (isCapital(n1[i]))
			{
				if (n1[i] <= 'N')
				{
					hour = n1[i] - 'A' + 10;
					break;
				}

			}
		}
	}
	for (int i = 0; i < n3.length() && i < n4.length(); i++)
	{
		if (n3[i] == n4[i] && isLetter(n3[i]))
		{
			minute = i;
			break;
		}
	}
	cout << days[day] <<" ";
	printf("%02d:%02d\n", hour, minute);
	system("pause");
	return 0;
}