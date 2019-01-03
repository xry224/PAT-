#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	bool flag[1001][1001];
	string str;
	getline(cin, str);
	int ans = 1;
	int length = str.length();
	memset(flag, false, sizeof(flag));
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			flag[i][j] = true;
		}
	}
	for (int i = 1; i < length; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (str[i] == str[j] && flag[j + 1][i - 1])	
			{
				flag[j][i] = true;
				ans = max(ans, i - j + 1);
			}
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}