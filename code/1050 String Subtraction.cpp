#include <iostream>
#include <string>
using namespace std;
int main()
{
	int character[200] = { 0 };
	string str1, str2;
	string ans = "";
	getline(cin, str1);
	getline(cin, str2);
	for (int i = 0; i < str2.length(); i++)
	{
		character[str2[i]]++;
	}
	for (int i = 0; i < str1.length(); i++)
	{
		if (character[str1[i]] == 0)
		{
			ans += str1[i];
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}