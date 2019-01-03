#include <iostream>
#include <stack>
#include <string>
using namespace std;
int cnt = 0;
int cnt2 = 0;
int inorder[200];
int preorder[200];
int n;
class Node
{
public:
	int val;
	Node *lchild, *rchild;
	Node()
	{
		lchild = NULL;
		rchild = NULL;
	}
	Node(int ini)
	{
		val = ini;
		lchild = NULL;
		rchild = NULL;
	}
};
void PostOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	cout << root->val << " ";
	delete root;
}
int find(int target, int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		if (inorder[i] == target)
		{
			return i;
		}
	}
	return -1;
}
Node *Build(int mids, int mide, int pres, int pree)
{
	Node *root = new Node(preorder[pres]);
	int index;
	int index = find(preorder[pres], mids, mide);
	
	if (mids != index)   //×ó×ÓÊ÷²»Îª¿Õ
	{
		int len = index - mids;
		root->lchild = Build(mids, index - 1, pres + 1, pres + len);
	}
	if (index != mide)
	{
		int len = mide - index;
		root->rchild = Build(index + 1, mide, pree + 1 - len, pree);
	}

	return root;
}
int main()
{
	stack<int> s;
	string command;
	int number;
	cin >> n;
	for (int i = 0; i < n * 2; i++)
	{
		cin >> command;
		if (command == "Push")
		{
			cin >> number;
			s.push(number);
			preorder[cnt2++] = number;
		}
		else if (command == "Pop")
		{
			number = s.top();
			s.pop();
			inorder[cnt++] = number;
		}
	}
	Node *root = Build(0, cnt - 1, 0, cnt2 - 1);
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	cout << root->val << endl;
	system("pause");
	return 0;
}