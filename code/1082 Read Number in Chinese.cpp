#include <iostream>
#include <string>
using namespace std;
string getUnit(int cur, int length)
{
	string ans = "";
	if (cur == length - 1)
	{
		return ans;
	}
	//ans = " ";
	int pos = length - cur;	
	switch (pos)
	{
	case 2:
	{
		ans += "Shi";
		break;
	}
	case 3:
	{
		ans += "Bai";
		break;
	}
	case 4:
	{
		ans += "Qian";
		break;
	}
	case 5:
	{
		ans += "Wan";
		break;
	}
	case 6:
	{
		ans += "Shi";
		break;
	}
	case 7:
	{
		ans += "Bai";
		break;
	}
	case 8:
	{
		ans += "Qian";
		break;
	}
	}

	return ans;
}
int main()
{
	string number[] = { "ling","yi", "er", "san", "si", "wu","liu","qi","ba","jiu" };
	string unit[] = {"Qian", "Bai", "Shi","Wan" };
	int t;
	string str;
	cin >> t;
	if (t == 0)
	{
		cout << "ling" << endl;
		return 0;
	}
	str = to_string(t);
	if (str[0] == '-')
	{
		cout << "Fu ";
		str = str.substr(1);
	}
	int i = 0;
	if (str.length() == 9)
	{
		if (str[0] != '0')
		{
			cout << number[str[0] - '0'] << " Yi";
		}
		i = 1;
	}
	for (; i < str.length(); i++)
	{
		if (str[i] != '0')
		{
			if (i != 0)
			{
				cout << " ";
			}
			cout << number[str[i] - '0'];
			string unit = getUnit(i, str.length());
			if (unit != "")
			{
				cout << " " + unit;
			}
		}
		else
		{
			bool flag = false;
			int j;
			for (j = i; j < str.length(); j++)
			{
				if (str[j] != '0')
				{
					break;
				}
				else
				{
					if (getUnit(j, str.length()) == "Wan")
					{
						cout << " Wan";
						flag = true;
					}
				}
			}
			if (j != str.length())
			{
				cout << " ling";
			}
			i = j - 1;
		}

	}
	cout << endl;
	system("pause");
	return 0;
}