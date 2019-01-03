#include <iostream>
#include <map>
#include <string>
using namespace std;
bool isChar(char c)
{
	if ((c <= 'Z' && c >= 'A') || c <= 'z' && c >= 'a')
	{
		return true;
	}
	return false;
}
bool isDigit(char c)
{
	if (c <= '9' && c >= '0')
	{
		return true;
	}
	return false;
}
bool isUpper(char c)
{
	if (c <= 'Z' && c >= 'A')
	{
		return true;
	}
	return false;
}
int main()
{
	map<string, int> m;
	string str;
	getline(cin, str);
	string temp = "";
	string ans;
	int cnt = -1;
	str = str + '.';
	for (int i = 0; i < str.length(); i++)
	{
		if (isDigit(str[i]))
		{
			temp += str[i];
		}
		else if (isChar(str[i]))
		{
			if (isUpper(str[i]))
			{
				temp += str[i] - 'A' + 'a';
			}
			else
			{
				temp += str[i];
			}
		}
		else
		{
			if (temp != "")
			{
				m[temp]++;
				if (m[temp] > cnt)
				{
					cnt = m[temp];
					ans = temp;
				}
				else if (m[temp] == cnt)
				{
					if (temp < ans)
					{
						ans = temp;
					}
				}
			}
			temp = "";
		}
	}

	cout << ans << " " << cnt << endl;
	system("pause");
	return 0;
}