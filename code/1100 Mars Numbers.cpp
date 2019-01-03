#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isNumber(char c)
{
	if (c >= '0' && c <= '9')
	{
		return true;
	}
	return false;
}
int getBase(string number)
{
	int num = 0;
	for (int i = 0; i < number.size(); i++)
	{
		num *= 10;
		num += (number[i] - '0');
	}
	return num;
}
int find(string str[], string target, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (str[i] == target)
		{
			return i;
		}
	}
	return -1;
}
string n1[] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string n2[] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
void earth2mars(int t)
{
	if (t < 12)
	{
		cout << n1[t] << endl;
	}
	else if (t % 13 == 0)
	{
		cout << n2[t / 13 - 1] << endl;
	}
	else
	{
		int gewei = t % 13;
		int shiwei = t / 13;
		cout << n2[shiwei - 1] << " " << n1[gewei] << endl;
	}
}
void mars2earth(string number)
{
	int index = number.find(' ');
	if (index == string::npos)
	{
		int num = find(n1, number, 13);
		if (num == -1)
		{
			num = find(n2, number, 12);
			cout << (num + 1) * 13 << endl;
			return;
		}
		else
		{
			cout << num << endl;
			return;
		}
	}
	string high = number.substr(0, index);
	string low = number.substr(index + 1);
	int higher = find(n2, high, 12);
	int lower = find(n1, low, 13);
	cout << (higher + 1) * 13 + lower << endl;
}
int main()
{
	int n;
	cin >> n;
	string number;
	getline(cin, number); //³Ô¿Õ¸ñ
	for (int i = 0; i < n; i++)
	{
		getline(cin, number);
		if (isNumber(number[0]))
		{
			earth2mars(getBase(number));
		}
		else
		{
			mars2earth(number);
		}
	}
	system("pause");
	return 0;
}