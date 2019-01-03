#include <iostream>
#include <string>
#include <queue>
using namespace std;
int n;
class Node
{
public:
	int val;
	Node *lchild;
	Node *rchild;
	Node(int v)
	{
		val = v;
		lchild = NULL;
		rchild = NULL;
	}
};
Node *Build(int inorder[], int postorder[], int instart, int inend, int poststart, int postend)
{
	Node *t = new Node(postorder[postend]);
	int index;
	for (int i = 0; i < n; i++)
	{
		if (inorder[i] == postorder[postend])
		{
			index = i;
			break;
		}
	}
	//左子树不为空
	if (index != instart)
	{
		int llen = index - instart;
		t->lchild = Build(inorder, postorder, instart, index - 1, poststart, poststart + llen - 1);
	}
	//右子树不为空
	if (index != inend)
	{
		int rlen = inend - index;
		t->rchild = Build(inorder, postorder, index + 1, inend, postend - rlen, postend - 1);
	}
	return t;
}
int main()
{
	cin >> n;
	int postorder[30];
	int inorder[30];
	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> postorder[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> inorder[i];
	}
	Node *root = Build(inorder, postorder, 0, n - 1, 0, n - 1);
	queue<Node *> q;
	q.push(root);
	int cnt = 0;
	while (!q.empty())
	{
		Node *t = q.front();
		int val = t->val;
		if (cnt == n - 1)
		{
			cout << val << endl;
		}
		else
		{
			cout << val << " ";
		}
		if (t->lchild != NULL)
		{		
			q.push(t->lchild);
		}
		if (t->rchild != NULL)
		{
			q.push(t->rchild);
		}
		q.pop();
		delete t;
		cnt++;
	}
	system("pause");
	return 0;
}
/*
30
16 17 8 18 19 9 4 20 21 10 22 23 11 5 2 24 25 12 26 27 13 6 28 29 14 30 15 7 3 1
16 8 17 4 18 9 19 2 20 10 21 5 22 11 23 1 24 12 25 6 26 13 27 3 28 14 29 7 30 15
*/