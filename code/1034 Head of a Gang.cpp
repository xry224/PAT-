#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
#define SIZE 2005
class Node
{
public:
	string name;
	int cnt;
	Node()
	{

	}
	bool operator < (const Node &A)const
	{
		return name < A.name;
	}
}ans[SIZE];
int sum[SIZE];
int Tree[SIZE];
int amount[SIZE];
map<string, int> name2id;
int findRoot(int x)
{
	if (x == Tree[x])
	{
		return x;
	}
	int t = findRoot(Tree[x]);
	Tree[x] = t;
	return t;
}
void Ini()
{
	for (int i = 0; i < SIZE; i++)
	{
		Tree[i] = i;
		sum[i] = 0;
		amount[i] = 1;
	}
}
string getName(int head)
{
	map<string, int>::iterator it;
	for (it = name2id.begin(); it != name2id.end(); it++)
	{
		if (it->second == head)
		{
			return it->first;
		}
	}
	return "Ha";	
}
int main()
{
	int n, k;
	cin >> n >> k;
	string name1, name2;
	int len;
	int numCnt = 1;
	Ini();
	for (int i = 0; i < n; i++)
	{
		cin >> name1 >> name2 >> len;
		if (name2id[name1] == 0)
		{
			name2id[name1] = numCnt++;
		}
		if (name2id[name2] == 0)
		{
			name2id[name2] = numCnt++;
		}

		int n1 = name2id[name1];
		int n2 = name2id[name2];
		sum[n1] += len;
		sum[n2] += len;
		n1 = findRoot(n1);
		n2 = findRoot(n2);
		if (n1 != n2)
		{
			Tree[n1] = n2;
			amount[n2] += amount[n1];
		}
	}
	int posscnt = 0;
	int possible[SIZE];
	for (int i = 1; i <= numCnt; i++)
	{
		if (amount[i] > 2 && Tree[i] == i)
		{
			possible[posscnt++] = i;
		}
	}

	int anscnt = 0;
	for (int i = 0; i < posscnt; i++)
	{
		int head = possible[i];
		int total = 0;
		int larg = 0;
		int boss;
		for (int j = 1; j <= numCnt; j++)
		{
			if (findRoot(j) == head)
			{
				total += sum[j];
				if (sum[j] > larg)
				{
					larg = sum[j];
					boss = j;
				}
			}
		}
		if (total / 2 > k)
		{
			string name = getName(boss);
			Node t;
			t.cnt = amount[head];
			t.name = name;
			
			ans[anscnt++] = t;
		}
	}
	sort(ans, ans + anscnt);
	cout << anscnt << endl;
	for (int i = 0; i < anscnt; i++)
	{
		cout << ans[i].name << " " << ans[i].cnt << endl;
	}
	return 0;
}