#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
#include <functional>
#include <stdio.h>
using namespace std;
multiset<int> upper;   //存放大于中位数的数， 小到大排列
multiset<int, greater<int> > lower;  //存放小于等于中位数的数（包括中位数本身），大到小排列
void adjust(int &mid)
{
	if (upper.size() > lower.size())
	{
		int t = *upper.begin();
		lower.insert(t);
		upper.erase(upper.find(t));
	}
	else if (lower.size() - upper.size() > 1)
	{
		int t = *lower.begin();
		upper.insert(t);
		lower.erase(lower.find(t));
	}
	mid = *lower.begin();
}
int main()
{
	vector<int> stack;
	int n;
	int mid = 0;
	scanf("%d", &n);
	//string command;
	char command[15];
	int key;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &command);
		if (strcmp(command, "Push") == 0)
		{
			scanf("%d", &key);
			stack.push_back(key);
			if (key <= mid)
			{
				lower.insert(key);
			}
			else
			{
				upper.insert(key);
			}
			adjust(mid);
		}
		else if (!stack.empty())
		{
			if (strcmp(command, "Pop") == 0)
			{
				int res = stack[stack.size() - 1];
				stack.pop_back();
				if (res > mid)
				{
					upper.erase(upper.find(res));
				}
				else
				{
					lower.erase(lower.find(res));
				}
				if (stack.empty())
				{
					mid = 0;
				}
				else
				{
					adjust(mid);
				}
				printf("%d\n", res);
			}
			else
			{
				printf("%d\n", mid);
			}
		}
		else
		{
			printf("Invalid\n");
		}
	}
	system("pause");
	return 0;
}