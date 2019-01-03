#include <iostream>
#include <map>
#include <vector>
#include <string.h>
using namespace std;
map<int, int> appear;
class Node
{
public:
	int val;
	Node *lchild, *rchild;
	Node(int value)
	{
		val = value;
		lchild = rchild = NULL;
	}
	Node()
	{
		lchild = rchild = NULL;
	}
};
map<int, Node *> mapping;
Node * Build(vector<int> &inorder, vector<int> &preorder, int ins, int ine, int pres, int pree)
{
	int value = preorder[pres];
	Node *root = new Node(value);
	mapping[value] = root;
	int index;
	for (int i = ins; i <= ine; i++)
	{
		if (inorder[i] == value)
		{
			index = i;
			break;
		}
	}
	if (index != ins)
	{
		int length = index - ins;
		root->lchild = Build(inorder, preorder, ins, index - 1, pres + 1, pres + length);
	}
	if (index != ine)
	{
		int length = ine - index;
		root->rchild = Build(inorder, preorder, index + 1, ine, pree - length + 1, pree);
	}
	return root;
}
Node *find(Node *root, Node *first, Node *second)
{
	if (root == first || root == second || root == NULL)
	{
		return root;
	}
	Node *left = find(root->lchild, first, second);
	Node *right = find(root->rchild, first, second);
	if (left == NULL)
	{
		return right;
	}
	if (right == NULL)
	{
		return left;
	}
	return root;
}
int main()
{
	int m, n;
	cin >> m >> n;
	vector<int> inorder(n);
	vector<int> preorder(n);
	for (int i = 0; i < n; i++)
	{
		cin >> inorder[i];
		appear[inorder[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> preorder[i];
	}
	Node *root = NULL;
	root = Build(inorder, preorder, 0, n - 1, 0, n - 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (appear[a] == 0 && appear[b] == 0)
		{
			cout << "ERROR: " << a << " and " << b << " are not found." << endl;
			continue;
		}
		else if (appear[a] == 0)
		{
			cout << "ERROR: " << a << " is not found." << endl;
			continue;
		}
		else if (appear[b] == 0)
		{
			cout << "ERROR: " << b << " is not found." << endl;
			continue;
		}
		Node *ans = find(root, mapping[a], mapping[b]);
		int value = ans->val;
		if (value == a)
		{
			cout << a << " is an ancestor of " << b << "." << endl;
		}
		else if (value == b)
		{
			cout << b << " is an ancestor of " << a << "." << endl;
		}
		else
		{
			cout << "LCA of " << a << " and " << b << " is " << value << "." << endl;
		}
	}
	system("pause");
	return 0;
}