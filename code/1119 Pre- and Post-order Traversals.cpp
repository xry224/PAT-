#include <iostream>
using namespace std;
class Node
{
public:
	int val;
	Node *lchild, *rchild;
	Node(int ini)
	{
		val = ini;
		lchild = rchild = NULL;
	}
	Node()
	{
		val = -1;
		lchild = rchild = NULL;
	}
};
bool unique = true;
int pre[35];
int post[35];
int n;
int findTar(int target)
{
	for (int i = 0; i < n; i++)
	{
		if (post[i] == target)
		{
			return i;
		}
	}
	return -1;
}
Node *Build(int preL, int preR, int postL, int postR)
{
	if (preL > preR || postL > postR)
	{
		return NULL;
	}
	int val = pre[preL];
	Node *root = new Node(val);
	if (preL == preR)
	{
		return root;
	}
	int next = pre[preL + 1];
	int index = findTar(next);
	int length = index - postL;
	if (preL + 1 + length == preR)
	{
		unique = false;
	}
	root->lchild = Build(preL + 1, preL + 1 + length, postL, index);
	if (preL + 1 + length < preR)
	{
		root->rchild = Build(preL + 2 + length, preR, index + 1, postR - 1);
	}
	return root;
}
bool first = true;
void inOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	inOrder(root->lchild);
	if (first)
	{
		cout << root->val;
		first = false;
	}
	else
	{
		cout << " " << root->val;
	}
	inOrder(root->rchild);
	delete root;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pre[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> post[i];
	}
	Node *root = Build(0, n - 1, 0, n - 1);
	if (unique)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	inOrder(root);
	cout << endl;
	system("pause");
	return 0;
}