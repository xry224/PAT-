#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define SIZE 1005
class Node
{
public:
	int weight;
	int rank;
	int id;
	Node()
	{

	}
	bool operator < (const Node &A) const
	{
		return weight < A.weight;
	}
}pro[SIZE];
bool cmp(Node A, Node B)
{
	return A.id < B.id;
}
int main()
{
	int order[SIZE];
	int n, groupsize;
	cin >> n >> groupsize;
	for (int i = 0; i < n; i++)
	{
		cin >> pro[i].weight;
		pro[i].id = i;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> order[i];
	}
	vector <Node> ans;
	priority_queue<Node> group[SIZE];
	int leftsize = n;
	while (ans.size() < n)
	{
		
		int groupcnt = 0;
		//仅剩最后一个人
		if (leftsize == 1)
		{
			pro[0].rank = 1;
			ans.push_back(pro[0]);
			break;
		}
		//遍历所有剩下的人，将其分组
		for (int i = 0; i < leftsize; i += groupsize)
		{
			for (int j = i; j < i + groupsize && j < leftsize; j++)
			{
				group[groupcnt].push(pro[order[j]]);
			}
			groupcnt++;
		}
		//cout << groupcnt << endl;
		leftsize = groupcnt;
		//取出每组头名
		for (int i = 0; i < groupcnt; i++)
		{
			pro[i] = group[i].top();
			order[i] = i;
			group[i].pop();
		}
		//将其余玩家出队
		for (int i = 0; i < groupcnt; i++)
		{
			while (!group[i].empty())
			{
				Node t = group[i].top();
				t.rank = leftsize + 1;
				ans.push_back(t);
				group[i].pop();
			}
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size() - 1; i++)
	{
		cout << ans[i].rank << " ";
	}
	cout << ans[ans.size() - 1].rank << endl;
	system("pause");
	return 0;
}