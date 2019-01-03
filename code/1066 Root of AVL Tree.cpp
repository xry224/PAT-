#include <iostream>
using namespace std;
class Node
{
public:
	int val;
	Node *lchild;
	Node *rchild;
	int height;
	Node()
	{
		lchild = NULL;
		rchild = NULL;
		height = 0;
	}
	Node(int inival)
	{
		val = inival;
		lchild = NULL;
		rchild = NULL;
		height = 0;
	}
};
int max(int a, int b)
{
	return a > b ? a : b;
}
int getHeight(Node * A)
{
	if (A != NULL)
	{
		return A->height;
	}
	return 0;
}
Node *LLRotation(Node * root)
{
	Node *t;
	t = root->lchild;
	root->lchild = t->rchild;
	t->rchild = root;

	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
	t->height = max(getHeight(t->lchild), getHeight(t->rchild)) + 1;
	return t;
}
Node *RRRotation(Node *root)
{
	Node *t;
	t = root->rchild;
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
		if (getHeight(root->lchild) - getHeight(root->rchild) >= 2)
		{
			//插入左子树的左子树
			if (val < root->lchild->val)
			{
				root = LLRotation(root);
			}
			//插入左子树的右子树
			else
			{
				root = LRRotation(root);
			}
		}
	}
	else
	{
		root->rchild = Insert(root->rchild, val);
		if (getHeight(root->rchild) - getHeight(root->lchild) >= 2)
		{
			//插入右子树的左子树
			if (val < root->rchild->val)
			{
				root = RLRotation(root);
			}
			//插入右子树的右子树
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
	cin >> n;
	Node *root = NULL;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		root = Insert(root, t);
	}
	cout << root->val << endl;
	system("pause");
	return 0;
}