#pragma warning(disable:4996)
#include<stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int Tree[1001];
//int counts[1001];
int findRoot(int x)
{
	if (Tree[x] == x)
	{
		return x;
	}
	int t = findRoot(Tree[x]);
	Tree[x] = t;
	return t;
}
void Ini()
{
	for (int i = 0; i <= 1000; i++)
	{
		Tree[i] = i;
		//counts[i] = 1;
	}
}
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n; 
	Ini();
	int course[1001] = { 0 };  //有编号为i的兴趣的人中编号最小的
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int size;
		char c;
		cin >> size >> c;
		for (int j = 0; j < size; j++)
		{
			
			int t;
			cin >> t;
			if (course[t] == 0)
			{
				course[t] = i;
			}
			int a = findRoot(i);
			int b = findRoot(course[t]);
			if (a != b)
			{
				Tree[a] = b;
				//counts[b] += counts[a];
			}
		}
	}
	int ans = 0;
	int counts[1001] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		counts[findRoot(i)]++;
	}
	sort(counts + 1, counts + 1 + n, cmp);
	for (int i = 1; i <= n; i++)
	{
		if (counts[i] != 0)
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	cout << ans << endl;
	for (int i = 1; i <= ans; i++)
	{
		cout << counts[i];
		if (i != ans)
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