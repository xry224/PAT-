#include <iostream>
#include <string.h>
#include <queue>
#include <string>
#include <math.h>
using namespace std;
class Node
{
public:
	int id;
	int left, right;
	Node()
	{
		left = right = -1;
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
			troot = i;
			break;
		}
	}
	int maxlevel;
	if (n == 1)
	{
		maxlevel = 1;
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			int low = pow(2, i);
			int up = pow(2, i + 1) - 1;
			if (low <= n && n <= up)
			{
				maxlevel = i + 1;
				break;
			}
		}
	}
	bool flag = true;
	queue<Node> q;
	Node last;
	q.push(Tree[troot]);
	int level = 1;
	int size = 1;
	while (!q.empty() && flag)
	{
		int qsize = q.size();
		size = level == maxlevel ? n - pow(2, maxlevel - 1) + 1 : (pow(2, level) - pow(2, level - 1));
		if (qsize != size)
		{
			flag = false;
			break;
		}
		bool hasempty = false;
		for (int i = 0; i < qsize; i++)
		{
			Node t = q.front();
			q.pop();
			if (hasempty && t.left != -1 && t.right != -1)
			{
				flag = false;
				break;
			}
			if (t.left == -1 && t.right != -1)
			{
				flag = false;
				break;
			}
			else if (t.left != -1 && t.right!=-1)
			{
				last = Tree[t.left];
				q.push(last);
				last = Tree[t.right];
				q.push(last);
			}
			else if (t.left != -1 && t.right == -1)
			{
				last = Tree[t.left];
				q.push(last);
				hasempty = true;
			}
			else if (t.left == -1 && t.right == -1)
			{
				hasempty = true;
			}
		}
		level++;
	}
	if (flag)
	{
		cout << "YES " << last.id << endl;
	}
	else
	{
		cout << "NO " << troot << endl;
	}
	system("pause");
	return 0;
}