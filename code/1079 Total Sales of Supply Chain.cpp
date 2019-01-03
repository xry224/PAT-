#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;
class Node
{
public:
	int type;
	int amount;
	vector<int> next;
	Node()
	{

	}
};
Node members[100005];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	double price;
	double rate;
	cin >> n >> price >> rate;
	for (int i = 0; i < n; i++)
	{
		int size;
		cin >> size;
		if (size == 0)
		{
			members[i].type = 0;
			cin >> members[i].amount;
		}
		else
		{
			members[i].type = 1;
			int t;
			for (int j = 0; j < size; j++)
			{
				cin >> t;
				members[i].next.push_back(t);
			}
			
		}
	}
	double ans = 0;
	queue<Node> q;
	q.push(members[0]);
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			Node cur = q.front();
			q.pop();
			if (cur.type == 0)
			{
				ans += price * pow(1 + rate / 100, level) * cur.amount;;
			}
			else
			{
				for (int j = 0; j < cur.next.size(); j++)
				{
					q.push(members[cur.next[j]]);
				}
			}
		}
		level++;
	}
	cout << fixed << setprecision(1) << ans << endl;
	system("pause");
	return 0;
}