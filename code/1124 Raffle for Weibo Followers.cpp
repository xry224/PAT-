#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	int n, skip, first;
	cin >> n >> skip >> first;
	string followers[1005];
	map<string, int> appear;
	for (int i = 1; i <= n; i++)
	{
		cin >> followers[i];
	}
	if (n < first)
	{
		cout << "Keep going..." << endl;
	}
	int cur = first;
	for (; cur <= n; )
	{
		if (appear[followers[cur]] == 0)
		{
			appear[followers[cur]]++;
			cout << followers[cur] << endl;
			cur += skip;
			
		}
		else
		{
			cur++;
		}
	}
	system("pause");
	return 0;
}