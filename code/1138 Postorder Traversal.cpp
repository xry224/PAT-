#include <iostream>
using namespace std;
class Node
{
public:
	int value;
	Node *lchild, *rchild;
	Node()
	{
		lchild = rchild = NULL;
	}
	Node(int val)
	{
		value = val;
		lchild = rchild = NULL;
	}
};
int preOrder[50005];
int inOrder[50005];
int find(int target, int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		if (inOrder[i] == target)
		{
			return i;
		}
	}
	return -1;
}
Node *Build(int mids, int mide, int pres, int pree)
{
	int val = preOrder[pres];
	Node *root = new Node(val);
	int index = find(val, mids, mide);
	//×ó×ÓÊ÷²»Îª¿Õ
	if (index != mids)
	{
		int length = index - mids;
		root->lchild = Build(mids, index - 1, pres + 1, pres + length);
	}
	if (index != mide)
	{
		int length = mide - index;
		root->rchild = Build(index + 1, mide, pree - length + 1, pree);
	}
	return root;
}
bool out = false;
void DeleteRoot(Node *root)
{
	if (root->rchild == NULL && root->lchild == NULL)
	{
		if (!out)
		{
			out = true;
			cout << root->value << endl;
		}
		delete root;
		return;
	}
	if (root->lchild != NULL)
	{
		DeleteRoot(root->lchild);
	}
	if (root->rchild != NULL)
	{
		DeleteRoot(root->rchild);
	}
	delete root;

}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> preOrder[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> inOrder[i];
	}
	Node *root = NULL;
	root = Build(0, n - 1, 0, n - 1);
	DeleteRoot(root);
	system("pause");
	return 0;
}