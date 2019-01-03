#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
class Node
{
public:
	int value;
	Node *lchild, *rchild;
	Node()
	{
		lchild = NULL;
		rchild = NULL;
	}
	Node(int ini)
	{
		value = ini;
		lchild = NULL;
		rchild = NULL;
	}
};
struct pairs
{
	int left;
	int right;
};
void Level(Node *root)
{
	queue<Node*> q;
	cout << root->value;
	if (root->lchild != NULL)
	{
		q.push(root->lchild);
	}
	if (root->rchild != NULL)
	{
		q.push(root->rchild);
	}
	delete root;
	while (!q.empty())
	{
		Node *cur = q.front();
		q.pop();
		cout << " " << cur->value;
		if (cur->lchild != NULL)
		{
			q.push(cur->lchild);
		}
		if (cur->rchild != NULL)
		{
			q.push(cur->rchild);
		}
		delete cur;
	}
	cout << endl;
}	
int n;
pairs childs[105];
int value[105];
int index = 0;
Node *Build(Node * cur, int node)
{
	if (cur == NULL)
	{
		cur = new Node();
	}
	if (childs[node].left != -1)
	{
		cur->lchild = Build(cur->lchild, childs[node].left);
	}
	cur->value = value[index++];
	if (childs[node].right != -1)
	{
		cur->rchild = Build(cur->rchild, childs[node].right);
	}
	return cur;
}
int main()
{

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> childs[i].left >> childs[i].right;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> value[i];
	}
	sort(value, value + n);
	Node *root = NULL;
	root = Build(root, 0);
	Level(root);
	system("pause");
	return 0;
}