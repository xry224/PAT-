#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
	string data;
	int lchild, rchild;
	Node()
	{
		lchild = rchild = -1;
	}
	Node(string val)
	{
		data = val;
		lchild = rchild = -1;
	}
}Tree[30];
string ans = "";
bool isLeaf(int root)
{
	if (Tree[root].lchild == -1 && Tree[root].rchild == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void inOrder(int cur, int root)
{
	if (cur == -1)
	{
		return;
	}
	if (isLeaf(cur))
	{
		ans += Tree[cur].data;
		return;
	}
	if (cur != root)
	{
		ans += "(";
		inOrder(Tree[cur].lchild, root);
		ans += Tree[cur].data;
		inOrder(Tree[cur].rchild, root);
		ans += ")";
	}
	else
	{
		inOrder(Tree[cur].lchild, root);
		ans += Tree[cur].data;
		inOrder(Tree[cur].rchild, root);
	}
}
int isroot[30] = { 0 };
int main()
{
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> Tree[i].data >> Tree[i].lchild >> Tree[i].rchild;
		if (Tree[i].lchild != -1)
		{
			isroot[Tree[i].lchild]++;
		}
		if (Tree[i].rchild != -1)
		{
			isroot[Tree[i].rchild]++;
		}
	}
	int root = 1;
	for (int i = 1; i <= n; i++)
	{
		if (isroot[i] == 0)
		{
			root = i;
			break;
		}
	}
	//cout << root << endl;
	inOrder(root, root);
	cout << ans << endl;
	system("pause");
	return 0;
}