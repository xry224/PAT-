#include <iostream>
#include <string>
#include <string.h>
using namespace std;
bool isLower(char c)
{
	if (c <= 'z' && c >= 'a')
	{
		return true;
	}
	return false;
}
int main()
{
	bool visit[300];
	memset(visit, false, sizeof(visit));
	string original;
	string broken;
	cin >> original >> broken;
	string ans = "";	
	for (int i = 0; i < broken.length(); i++)
	{
		if (isLower(broken[i]))
		{
			broken[i] = broken[i] - 'a' + 'A';
		}
	}
	for (int i = 0; i < original.length(); i++)
	{
		if (isLower(original[i]))
		{
			original[i] = original[i] - 'a' + 'A';
		}
		if (broken.find(original[i]) == string::npos)
		{
			if (!visit[original[i]])
			{
				visit[original[i]] = true;
				ans += original[i];
			}
		}
	}

	cout << ans << endl;
	system("pause");
	return 0;
}