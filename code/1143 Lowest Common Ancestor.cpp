#pragma warning(disable:4996)
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
class Node
{
public:
	int value;
	Node *lchild, *rchild;
	Node(int val)
	{
		value = val;
		lchild = rchild = NULL;
	}
};
void Process(Node *root, int u, int v)
{
	if (root == NULL)
	{
		return;
	}
	if (root->value == u)
	{
		cout << u << " is an ancestor of " << v << "." << endl;
		return;
	}
	if (root->value == v)
	{
		cout << v << " is an ancestor of " << u << "." << endl; 
		return;
	}
	if (u < v)
	{
		if (u < root->value && v >= root->value)
		{
			cout << "LCA of " << u << " and " << v << " is " << root->value << "." << endl;
			return;
		}
	}
	else
	{
		if (u >= root->value && v < root->value)
		{
			cout << "LCA of " << u << " and " << v << " is " << root->value << "." << endl;
			return;
		}
	}
	if (u < root->value && v < root->value)
	{
		Process(root->lchild, u, v);
	}
	else
	{
		Process(root->rchild, u, v);
	}
}
void Create(Node * &root, int mids, int mide, int pres, int pree, vector<int> &preorder, vector<int> &inorder)
{
	int val = preorder[pres];
	root = new Node(val);
	int index = -1;
	for (int i = mids; i <= mide; i++)
	{
		if (inorder[i] == val)
		{
			index = i;
			break;
		}
	}
	if (index != mids)
	{
		int length = index - mids;
		Create(root->lchild, mids, index - 1, pres + 1, pres + length, preorder, inorder);
	}
	if (index != mide)
	{
		int length = mide - index;
		Create(root->rchild, index + 1, mide, pree - length + 1, pree, preorder, inorder);
	}
}
int main()
{
	int n, m;
	cin >> m >> n;
	Node *root = NULL;
	vector<int> preorder(n);
	unordered_set<int> appear;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &preorder[i]);
		appear.insert(preorder[i]);
	}
	vector<int> inorder = preorder;
	sort(inorder.begin(), inorder.end());
	Create(root, 0, n - 1, 0, n - 1, preorder, inorder);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (appear.find(a) == appear.end() && appear.find(b) == appear.end())
		{
			cout << "ERROR: " << a << " and " << b << " are not found." << endl;
		}
		else if (appear.find(a) == appear.end())
		{
			cout << "ERROR: " << a << " is not found." << endl;
		}
		else if (appear.find(b) == appear.end())
		{
			cout << "ERROR: " << b << " is not found." << endl;
		}
		else
		{
			Process(root, a, b);
		}
	}
	system("pause");
	return 0;
}