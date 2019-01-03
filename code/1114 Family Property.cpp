#pragma warning(disable:4996)
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
class Person
{
public:
	int id;
	int father;
	int mother;
	vector<int> childs;
	int estate;
	int area;
	Person()
	{
		father = mother = -1;
		estate = area = 0;
	}
}members[10005];
class Family
{
public:
	int minID;
	int number;
	int set;
	int area;
	Family()
	{
		minID = 10000;
		set = area = number = 0;
	}
	bool operator < (const Family &A)const
	{
		double avgarea = (double)area / (double)number;
		double avg = (double)A.area / (double)A.number;
		if (avgarea == avg)
		{
			return minID < A.minID;
		}
		return avgarea > avg;

	}
}families[10005];
int Tree[10005];
void Ini()
{
	for (int i = 0; i < 10005; i++)
	{
		Tree[i] = i;
	}
}
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
int main()
{
	int n;
	int id, fat, mot, num, estate, area;
	int child[5];
	set<int> idlist;
	cin >> n;
	Ini();
	for (int i = 0; i < n; i++)
	{
		cin >> id >> fat >> mot >> num;
		members[id].id = id;
		members[id].father = fat;
		members[id].mother = mot;
		int root = findRoot(id);
		if (mot != -1)
		{
			int rootm = findRoot(mot);
			if (root != rootm)
			{
				Tree[rootm] = root;
			}
		}
		if (fat != -1)
		{
			int rootf = findRoot(fat);
			if (rootf != root)
			{
				Tree[rootf] = root;
			}
		}
		for (int j = 0; j < num; j++)
		{
			cin >> child[j];
			members[id].childs.push_back(child[j]);
			int rootc = findRoot(child[j]);
			if (rootc != root)
			{
				Tree[rootc] = root;
			}
		}
		cin >> estate >> area;
		members[id].estate = estate;
		members[id].area = area;
		idlist.insert(id);
		//cout << root << endl;
	}
	bool visit[10005];
	memset(visit, false, sizeof(visit));
	set<int> famlicnt;
	set<int>::iterator it;
	for (it = idlist.begin(); it != idlist.end(); it++)
	{
		int tempID = *it;
		int root = findRoot(tempID);
		famlicnt.insert(root);
		families[root].area += members[tempID].area;
		families[root].set += members[tempID].estate;
		if (!visit[tempID])
		{
			families[root].number++;
			if (tempID < families[root].minID)
			{
				families[root].minID = tempID;
			}
			visit[tempID] = true;
		}
		int mot = members[tempID].mother;
		int fat = members[tempID].father;
		if (mot != -1 && !visit[mot])
		{
			families[root].number++;
			if (mot < families[root].minID)
			{
				families[root].minID = mot;
			}
			visit[mot] = true;
		}
		if (fat != -1 && !visit[fat])
		{
			families[root].number++;
			if (fat < families[root].minID)
			{
				families[root].minID = fat;
			}
			visit[fat] = true;
		}
		for (int i = 0; i < members[tempID].childs.size(); i++)
		{
			int child = members[tempID].childs[i];
			if (!visit[child])
			{
				visit[child] = true;
				families[root].number++;
				if (child < families[root].minID)
				{
					families[root].minID = child;
				}
			}
		}
	}
	vector<Family> ans;
	cout << famlicnt.size() << endl;
	for (it = famlicnt.begin(); it != famlicnt.end(); it++)
	{
		
		int root = *it;
		ans.push_back(families[root]);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		Family t = ans[i];
		double avgarea = (double)t.area / (double)t.number;
		double avgsets = (double)t.set / (double)t.number;
		printf("%04d %d %.3lf %.3lf\n", t.minID, t.number, avgsets, avgarea);
	}
	system("pause");
	return 0;
}