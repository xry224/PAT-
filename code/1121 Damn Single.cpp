#include<iostream>
#include<vector>
#include <set>
#include<algorithm>
#include <stdio.h>
using namespace std;	
vector<int> partner[100005];
int main()
{
	int n;
	cin >> n;	

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		partner[a].push_back(b);
		partner[b].push_back(a);
	}
	cin >> n;
	set<int> guest;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		guest.insert(num);
	}
	set<int>::iterator it;
	vector<int> ans;
	for (it = guest.begin(); it != guest.end(); it++)
	{
		int num = *it;
		if (partner[num].size() == 0)
		{
			ans.push_back(num);
		}
		else
		{
			int part = partner[num][0];
			if (guest.find(part) == guest.end())
			{
				ans.push_back(num);
			}
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%05d", ans[i]);
		if (i != ans.size() - 1)
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}
	system("pause");
	return 0;
}