#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Node
{
	int val;
	Node *lchild, *rchild;
	Node(int va)
	{
		val = va;
		lchild = NULL;
		rchild = NULL;
	}
};
int num[1005];
int n;
int pos = 0;
Node *Build(Node *root, int cur)
{
	if (cur > n)
	{
		return NULL;
	}
    root = new Node(1);
	root->lchild = Build(root->lchild, cur * 2);
	root->val = num[pos++];
	root->rchild = Build(root->rchild, cur * 2 + 1);
	return root;
}
void Level(Node *root)
{
	queue<Node*> q;
	cout << root->val;
	if (root->lchild != NULL)
	{
		q.push(root->lchild);
	}
	if (root->rchild != NULL)
	{
		q.push(root->rchild);
	}
	while (!q.empty())
	{
		Node *cur = q.front();
		if (cur->lchild != NULL)
		{
			q.push(cur->lchild);
		}
		if (cur->rchild != NULL)
		{
			q.push(cur->rchild);
		}
		cout << " " << cur->val;
		q.pop();
		delete cur;
	}
	cout << endl;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n);
	Node *root = new Node(1);
	root = Build(root, 1);
	Level(root);
	system("pause");
	return 0;
}