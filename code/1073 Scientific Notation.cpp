#include <iostream>
#include <string>
using namespace std;
int getNum(string str)
{
	int ans = 0;
	for (int i = 0; i < str.length(); i++)
	{
		ans *= 10;
		ans += str[i] - '0';
	}
	return ans;
}
string Neg(int expnum, int point, string number)
{
	int cnt = 0;
	//移动小数点
	while (cnt < expnum && point > 0)
	{
		cnt++;
		number[point] = number[point - 1];
		number[point - 1] = '.';
		point--;
	}
	if (point != 0)
	{
		return number;
	}
	number = number.substr(1);
	//前置位加0
	while (cnt < expnum)
	{
		cnt++;
		number = "0" + number;
	}
	number = "0." + number;
	return number;
}
string pos(int expnum, int point, string number)
{
	int cnt = 0;
	while (cnt < expnum && point < number.length() - 1)
	{
		number[point] = number[point + 1];
		number[point + 1] = '.';
		cnt++;
		point++;
	}
	if (point != number.length() - 1)
	{
		return number;
	}
	number = number.substr(0, number.length() - 1);
	while (cnt < expnum)
	{
		cnt++;
		number += '0';
	}
	return number;
}
bool judge(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != '0' && str[i] != '.')
		{
			return true;
		}
	}
	return false;
}
void Out(string number, bool numnegtive)
{
	if (numnegtive)
	{
		cout << '-' << number << endl;
	}
	else
	{
		cout << number << endl;
	}
}
int main()
{
	bool numnegtive = false;
	bool expnegtive = false;
	string ori;
	string number;
	string exp;
	while (cin >> ori)
	{
		//判定整体数字正负
		if (ori[0] == '-')
		{
			numnegtive = true;
		}
		ori = ori.substr(1);
		int index = ori.find('E');
		//获取纯数字部分
		number = ori.substr(0, index);
		//获取指数部分
		ori = ori.substr(index + 1);
		if (ori[0] == '-')
		{
			expnegtive = true;
		}
		exp = ori.substr(1);
		int expnum = getNum(exp);
		if (expnum == 0)
		{
			Out(number, numnegtive);
			continue;
		}
		//获取小数点位置
		int point = number.find('.');
		if (expnegtive)
		{
			number = Neg(expnum, point, number);
		}
		else
		{
			number = pos(expnum, point, number);
		}
		Out(number, numnegtive);
	}
	return 0;
}