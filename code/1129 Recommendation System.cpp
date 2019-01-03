#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
struct Item
{
	int index;
	int cnt;
	bool operator < (const Item &A)const
	{
		if (cnt == A.cnt)
		{
			return index < A.index;
		}
		return cnt > A.cnt;
	}
	Item(int a, int b)
	{
		index = a;
		cnt = b;
	}
};
int main()
{
	int n, k;
	int num[50005] = { 0 };
	cin >> n >> k;
	int first;
	cin >> first;
	num[first]++;
	set<Item> items;
	set<Item>::iterator it;
	items.insert(Item(first, 1));
	for (int i = 1; i < n; i++)
	{
		int query;
		cin >> query;
		cout << query << ":";
		int tempcnt = 0;
		for (it = items.begin(); tempcnt < k && it != items.end(); it++, tempcnt++)
		{
			cout << " " << it->index;
		}
		cout << endl;
		it = items.find(Item(query, num[query]));
		if (it != items.end())
		{
			items.erase(it);
		}
		num[query]++;
		items.insert(Item(query, num[query]));
	}
	system("pause");
	return 0;
}