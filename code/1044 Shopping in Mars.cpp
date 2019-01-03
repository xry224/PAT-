#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm> 
#include <limits.h>
#include <stdio.h>
using namespace std;
class Node
{
public:
	int left;
	int right;
	bool operator < (const Node &A)const
	{
		return left < A.left;
	}
	Node(int i, int j)
	{
		left = i;
		right = j;
	}
};
int seq[100005];
vector<Node> ans;
int main()
{
	int n, target;
	scanf("%d %d", &n, &target);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &seq[i]);
	}
	bool flag = false;
	int curmin = INT_MAX;
	int total = 0;
	int jump = 0;
	for (int i = 0; i < n; i++)
	{
		flag = false;
		for (int j = i + jump; j < n; j++)
		{
			total += seq[j];
			if (total >= target)
			{
				flag = true;
				if (total < curmin)
				{
					ans.clear();
					ans.push_back(Node(i + 1, j + 1));
					curmin = total;
				}
				else if (total == curmin)
				{
					ans.push_back(Node(i + 1, j + 1));
				}
				if (total == target && j != i)
				{
					jump = j - i;
					total -= seq[i];
				}
				else
				{
					total = 0;
					jump = 0;
				}
				break;
			}
		}
		if (!flag)
		{
			total = 0;
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d-%d\n", ans[i].left, ans[i].right);
	}
	system("pause");
	return 0;
}