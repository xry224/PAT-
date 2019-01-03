#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int weight[105];
vector <int> son[105];
vector <int> curpath;
vector <vector<int> >path;
vector<string> ans;
int target;
void dfs(int curnode, int sum)
{
	sum += weight[curnode];
	curpath.push_back(weight[curnode]);
	if (sum >= target)
	{
		if (sum == target && son[curnode].size() == 0)
		{
			path.push_back(curpath);
		}
		return;
	}

	for (int i = 0; i < son[curnode].size(); i++)
	{
		int node = son[curnode][i];
		dfs(node, sum);
		curpath.pop_back();
	}
}
void dfs(int curnode, int sum, string path)
{
	sum += weight[curnode];
	if (sum >= target)
	{
		if (sum == target && son[curnode].size() == 0)
		{
			ans.push_back(path);
		}
		return;
	}

	for (int i = 0; i < son[curnode].size(); i++)
	{
		string nextpath = path;
		int node = son[curnode][i];	
		string w = " ";
		w += to_string(weight[node]);
		nextpath += w;
		dfs(node, sum, nextpath);
	}
}
bool cmp(const vector<int> &a, const vector<int> &b)
{
	return a > b;
}
bool cmp1(string a, string b)
{
	return a > b;
}
int main()
{
	int n, m;
	scanf("%d %d %d", &n, &m, &target);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &weight[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int id, num;
		int child;
		scanf("%d %d", &id, &num);
		for (int j = 0; j < num; j++)
		{
			scanf("%d", &child);
			son[id].push_back(child);
		}
	}
	dfs(0, 0);
	sort(path.begin(), path.end(), cmp);
	for (int i = 0; i < path.size(); i++)
	{
		for (int j = 0; j < path[i].size(); j++)
		{
			if (j == 0)
			{
				printf("%d", path[i][j]);
			}
			else
			{
				printf(" %d", path[i][j]);
			}
		}
		printf("\n");
	}
	/*
	string w = to_string(weight[0]);
	dfs(0, 0, to_string(weight[0]));
	sort(ans.begin(), ans.end(), cmp1);
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%s\n", ans[i].c_str());
	}*/
	system("pause");
	return 0;
}