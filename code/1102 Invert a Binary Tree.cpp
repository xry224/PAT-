#include <iostream>
#include<vector>
#include <queue>
using namespace std;
class Node
{
public:
	int id;
	int lchild;
	int rchild;
	Node()
	{
		lchild = rchild = -1;
	}
}Tree[20];
int cnt = 0;
int n;
void Count(Node cur)
{
	cnt++;
	if (cur.lchild != -1)
	{
		Count(Tree[cur.lchild]);
	}
	if (cur.rchild != -1)
	{
		Count(Tree[cur.rchild]);
	}
}
void level(Node root)
{
	queue<Node> q;
	cout << root.id;
	if (root.lchild != -1)
	{
		q.push(Tree[root.lchild]);
	}
	if (root.rchild != -1)
	{
		q.push(Tree[root.rchild]);
	}
	while (!q.empty())
	{
		Node cur = q.front();
		q.pop();
		cout << " " << cur.id;
		if (cur.lchild != -1)
		{
			q.push(Tree[cur.lchild]);
		}
		if (cur.rchild != -1)
		{
			q.push(Tree[cur.rchild]);
		}
	}
	cout << endl;
}
void inOrder(Node root)
{
	
	if (root.lchild != -1)
	{
		inOrder(Tree[root.lchild]);
	}
	cout << root.id;
	cnt++;
	if (cnt == n)
	{
		cout << endl;
	}
	else
	{
		cout << " ";
	}
	
	if (root.rchild != -1)
	{
		inOrder(Tree[root.rchild]);
	}
}
int main()
{
	vector<Node> possible;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		bool isroot = false;
		char l, r;
		cin >> r >> l;
		Tree[i].id = i;
		if (l != '-')
		{
			isroot = true;
			Tree[i].lchild = (l - '0');
		}
		if (r != '-')
		{
			isroot = true;
			Tree[i].rchild = (r - '0');
		}
		if (isroot)
		{
			possible.push_back(Tree[i]);
		}
	}
	Node root;
	for (int i = 0; i < possible.size(); i++)
	{
		cnt = 0;
		Count(possible[i]);
		if (cnt == n)
		{
			root = possible[i];
			break;
		}
	}
	level(root);
	cnt = 0;
	inOrder(root);
	system("pause");
	return 0;
}