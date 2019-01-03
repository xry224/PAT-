#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
	int val;
	Node *lchild, *rchild;
	int height;
	Node()
	{
		lchild = rchild = NULL;
		height = 0;
		val = -1;
	}
	Node(int ini)
	{
		val = ini;
		lchild = rchild = NULL;
		height = 0;
	}
};
int getHeight(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return root->height;
	}
}
int max(int a, int b)
{
	return a > b ? a : b;
}
Node *LLRotation(Node *root)
{
	Node *t = root->lchild;
	root->lchild = t->rchild;
	t->rchild = root;

	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
	t->height = max(getHeight(t->lchild), getHeight(t->rchild)) + 1;
	return t;
}
Node *RRRotation(Node *root)
{
	Node *t = root->rchild;
	root->rchild = t->lchild;
	t->lchild = root;

	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
	t->height = max(getHeight(t->lchild), getHeight(t->rchild)) + 1;
	return t;
}
Node *LRRotation(Node *root)
{
	root->lchild = RRRotation(root->lchild);
	return LLRotation(root);	
}
Node *RLRotation(Node *root)
{
	root->rchild = LLRotation(root->rchild);
	return RRRotation(root);
}
Node *Insert(Node *root, int val)
{
	if (root == NULL)
	{
		root = new Node(val);
	}
	//插入左子树
	else if (val < root->val)
	{
		root->lchild = Insert(root->lchild, val);
		if (getHeight(root->lchild) - getHeight(root->rchild) > 1)
		{
			//插入左子树的左子树
			if (val < root->lchild->val)
			{
				root = LLRotation(root);
			}
			else
			{
				root = LRRotation(root);
			}
		}
	}
	else
	{
		root->rchild = Insert(root->rchild, val);
		if (getHeight(root->rchild) - getHeight(root->lchild) > 1)
		{
			if (val < root->rchild->val)
			{
				root = RLRotation(root);
			}
			else
			{
				root = RRRotation(root);
			}
		}
	}
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
	return root;
}
int main()
{
	int n;
	Node *root = NULL;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		root = Insert(root, t);
	}
	queue<Node*> q;
	cout << root->val;
	q.push(root->lchild);
	q.push(root->rchild);
	delete root;
	int cnt = 1;
	bool flag = true;
	while (!q.empty())
	{
		Node *cur = q.front();
		q.pop();
		if (cur == NULL)
		{
			flag = false;
			continue;
		}
		if (flag)
		{
			cnt++;
		}
		cout << " " << cur->val;
		q.push(cur->lchild);
		q.push(cur->rchild);
	}
	cout << endl;
	if (cnt == n)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	system("pause");
	return 0;
}