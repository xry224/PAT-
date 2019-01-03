#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <string>
using namespace std;
class Node
{
public:
	int id;
	int left, right;
	Node()
	{
		id = left = right = -1;
	}
}Tree[25];
int main()
{
	int n;
	cin >> n;
	bool root[25];
	memset(root, true, sizeof(root));
	for (int i = 0; i < n; i++)
	{
		string l, r;
		cin >> l >> r;
		Tree[i].id = i;
		if (l != "-")
		{
			Tree[i].left = atoi(l.c_str());
			root[Tree[i].left] = false;
		}
		if (r != "-")
		{
			Tree[i].right = atoi(r.c_str());
			root[Tree[i].right] = false;
		}
	}
	int troot;
	for (int i = 0; i < n; i++)
	{
		if (root[i])
		{
			//cout << i << endl;
			troot = i;
			break;
		}
	}
	queue<int> q;
	int last;
	q.push(troot);
	int cnt = 0;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		if (t == -1)
		{
			break;
		}
		cnt++;
		last = t;
		q.push(Tree[t].left);
		q.push(Tree[t].right);
	}
	if (cnt == n)
	{
		cout << "YES " << last << endl;
	}
	else
	{
		cout << "NO " << troot << endl;
	}
	system("pause");
	return 0;
}