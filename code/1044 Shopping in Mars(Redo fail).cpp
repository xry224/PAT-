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
		left = i + 1;
		right = j;
	}
};
int seq[100005];
vector<Node> ans;
int find(int left, int &right, int target)
{
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;cout << seq[mid] - seq[left] <<" "<<left<<" "<<right<< endl;
		if (seq[mid] - seq[left] >= target)
		{
			
			right = mid;
		}
		else 
		{
			left = mid + 1;
		}
	}	
	cout << endl;
	return seq[right] - seq[left];
}
int findBestSum(int i, int &right, int m) {
	int left = i + 1;
	int mid;
	while (left < right) {			//采用二分法查找
		mid = (left + right) / 2;
		if (seq[mid] - seq[i] >= m) {	//arr[x]-arr[i] 表示[i+1,...,x]的数据和
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return seq[right] - seq[i];
}
int main()
{
	int n, target;
	scanf("%d %d", &n, &target);
	int t = 0;
	seq[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t);
		seq[i] = seq[i - 1] + t;
	}
	bool flag = false;
	int curmin = INT_MAX;
	int total = 0;
	int jump = 0;
	for (int i = 0; i < n; i++)
	{
		int right = n ;
		int left = i;
		int res = findBestSum(left, right, target);
		if (res >= target)
		{
			if (res < curmin)
			{
				curmin = res;
				ans.clear();
				ans.push_back(Node(left, right));
			}
			else if (res == curmin)
			{
				ans.push_back(Node(left, right));
			}
			else
			{
				break;
			}
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