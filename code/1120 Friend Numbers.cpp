#include <iostream>
#include <string>
#include <set>
using namespace std;
int getFriend(string str)
{
	int ans = 0;
	for (int i = 0; i < str.length(); i++)
	{
		ans += (str[i] - '0');
	}
	return ans;
}
int main()
{
	int n;
	string number;
	set<int> fid;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		int res = getFriend(number);
		fid.insert(res);
	}
	set<int>::iterator it;
	cout << fid.size() << endl;
	it = fid.begin();
	cout << *it;
	it++;
	for (; it != fid.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;
	system("pause");
	return 0;
}