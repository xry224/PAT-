#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
	int id;
	vector<int> child;
	Node()
	{

	}
}gen[105];
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int id, num;
		cin >> id >> num;
		for (int j = 0; j < num; j++)
		{
			int t;
			cin >> t;
			gen[id].child.push_back(t);
		}
	}
	int population = 0;
	int level = 1;
	int ans = 1;
	queue<Node> q;
	q.push(gen[1]);	
	while (!q.empty())
	{
		int size = q.size();
		if (size > population)
		{
			ans = level;
			population = size;
		}
		for (int i = 0; i < size; i++)
		{
			Node top = q.front();
			q.pop();
			for (int j = 0; j < top.child.size(); j++)
			{
				int childid = top.child[j];
				q.push(gen[childid]);
			}
		}

		level++;
	}
	cout << population << " " << ans << endl;
	system("pause");
	return 0;
}