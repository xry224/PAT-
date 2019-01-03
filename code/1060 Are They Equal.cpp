#include <iostream>
#include <string>
using namespace std;
string leadzero(string ori)
{
	int i;
	for (i = 0; i < ori.length(); i++)
	{
		if (ori[i] != '0')
		{
			if (ori[i] == '.')
			{
				i--;
			}
			break;
		}
	}
	if (i == ori.length())
	{
		return "0.0";
	}
	else
	{
		return ori.substr(i);
	}
}
string fix(string ori, int length, int targetlen)
{
	while (length < targetlen)
	{
		ori += '0';
		length++;
	}
	return ori;
}
string Convert(string ori, int n)
{
	//去除前导0
	ori = leadzero(ori);
	int len = ori.length();
	len--;
	if (ori.find('.') == string::npos)
	{
		ori += '.'; //整数化为xxx.的形式
	}
	//位数不足补0
	ori = fix(ori, len, n);
//	cout << ori << endl;
	
	string ans = "";
	int cnt = 0;
	int i;
	//寻找第一个非0数字的位置
	for (i = 0; i < ori.length(); i++)
	{
		if (ori[i] != '0' && ori[i] != '.')
		{
			break;
		}
	}
	//0.0000的形式
	if (i == ori.length())
	{
		int point = ori.find('.');
		int len = ori.length() - point - 1;
		//cout << len <<" "<<ori<< endl;
		//补0
		while (len < n)
		{
			ori += '0';
			len++;
		}
		//截断
		if (ori.length() - 2 > n)
		{
			ori = ori.substr(0, n + 2);
		}
		ori += "*10^0";
	}
	else
	{
		int point = ori.find('.');
		int exp;
		string ans;
		//计算指数
		//整数位不为0
		if (i < point)
		{
			exp = point - i;
		}
		//整数位为0
		else
		{
			exp = point - i + 1;
		}
		ans = "0.";
		int cnt = 0;
		for (i; i < ori.length() && cnt < n; i++, cnt++)
		{
			if (ori[i] == '.')
			{
				cnt--;
				continue;
			}
			ans += ori[i];
		}
		while (cnt < n)
		{
			ans += '0';
			cnt++;
		}
		if (ans.length() - 2 > n)
		{
			ans = ans.substr(0, n + 2);
		}
		ans += "*10^";
		ans += to_string(exp);
		ori = ans;
	}
	return ori;
}
int main()
{
	int n;
	string n1;
	string n2;
	
	while (cin >> n >> n1 >> n2)
	{
		bool flag = true;
		n1 = Convert(n1, n);
		n2 = Convert(n2, n);
		if (n1 == n2)
		{
			cout << "YES" << " " << n1 << endl;
		}
		else
		{
			cout << "NO " << n1 << " " << n2 << endl;
		}
	}
	return 0;
}