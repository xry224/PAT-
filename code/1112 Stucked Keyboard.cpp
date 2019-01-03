#include<iostream>
#include<string>
using namespace std;
int main()
{
	int k;
	int check[256] = { 0 };
	string str;
	string stucked = "";
	cin >> k >> str;
	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		int key = (int)c;
		if (check[key] == 1)
		{
			continue;
		}
		int next = i + 1;
		for (next; next < str.length(); next++)
		{
			if (str[next] != c)
			{
				break;
			}
		}
		int duplicate = next - i;
		if (duplicate % k != 0)
		{
			check[key] = 1;  //Ã»»µ
		}
		else
		{
			check[key] = 2;
		}	
		i = next - 1;
	}
	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		int key = (int)c;
		if (check[key] == 2 && stucked.find(c) == string::npos)
		{
			stucked += c;
		}
	}
	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		int key = (int)c;
		if (check[key] == 2)
		{
			str.erase(i, k - 1);
		}
	}
	cout << stucked << endl;
	cout << str << endl;
	system("pause");
	return 0;
}