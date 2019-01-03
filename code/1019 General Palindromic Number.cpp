#include <iostream>
#include <string>
using namespace std;
bool equal(string s1, string s2)
{
	if (s1.length() != s2.length())
	{
		//cout << s1.length() << " " << s2.length() << endl;
		return false;
	}
	for (int i = 0; i < s1.length(); i++)
	{
		int off = s1.length() - i - 1;
		if (s1[i] != s2[off])
		{
			//cout << s1[i] << " " << s2[off] << endl;
			return false;
		}
	}
	return true;
}
bool Judge(string str[], int len)
{
	for (int i = 0; i < len / 2; i++)
	{
		int off = len - i - 1;
		if (str[i]!=str[off])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string num[30];
	int number, radix;
	cin >> number >> radix;
	if (number == 0)
	{
		cout << "Yes" << endl;
		cout << 0 << endl;
		return 0;
	}
	int t = number;
	int cnt = 0;
	while (t > 0)
	{
		num[cnt++] = to_string(t % radix);
		t = t / radix;
	}
	bool flag = Judge(num, cnt);
	if (flag)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;	
	}
	for (int i = cnt - 1; i >= 1; i--)
	{
		cout << num[i] << " ";
	}
	cout << num[0] << endl;
	system("pause");
	return 0;
}