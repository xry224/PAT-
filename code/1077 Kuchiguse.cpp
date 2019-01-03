#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector <string> setence[1002];
void Process(string str, int index)
{
	string temp = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			temp += str[i];
		}
		else
		{
			setence[index].push_back(temp);
			temp = "";
		}
	}
	if (temp != "")
	{
		setence[index].push_back(temp);
	}
}
int main()
{
	string str[1002];
	string space;
	int n;
	cin >> n;
	//³Ô¿Õ¸ñ
	getline(cin, space);
	for (int i = 0; i < n; i++)
	{
		getline(cin, str[i]);
		//Process(str, i);
	}
	string t = "";
	string ans = "";
	for (int i = str[0].size() - 1; i >= 0; i--)
	{
		bool flag = true;
		t = str[0][i] + t;
		for (int j = 1; j < n; j++)
		{
			int k, l;
			for (k = str[j].size() - 1, l = t.length() - 1; k >= 0 && l >= 0; k--, l--)
			{
				if (str[j][k] != t[l])
				{
					break;
				}
			}
			if (l != -1)
			{
				flag = false;
				break;
			}
		}
		if (!flag)
		{
			break;
		}
		ans = t;
	}
	if (ans == "")
	{
		cout << "nai" << endl;
	}
	else
	{
		cout << ans << endl;
	}
	system("pause");
	return 0;
}