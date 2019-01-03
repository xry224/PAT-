#include <iostream>
#include <math.h>
using namespace std;
class Node
{
public:
	int value;
	Node *lchild, *rchild;
	bool black;
	Node()
	{
		lchild = rchild = NULL;
		black = true;
	}
	Node(int val)
	{
		lchild = rchild = NULL;
		black = val >= 0;
		value = abs(val);
	}
	void setValue(int newval)
	{
		value = abs(newval);
		black = newval >= 0;
	}
};
int nums[50];
Node *Build(Node *root, int val)
{
	if (root == NULL)
	{
		root = new Node(val);
	}
	else if (abs(val) < root->value)
	{
		root->lchild = Build(root->lchild, val);
	}
	else
	{
		root->rchild = Build(root->rchild, val);
	}
	return root;
}
bool flag = true;
void inOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	inOrder(root->lchild);
	cout << root->value << " ";
	inOrder(root->rchild);
}
void deleteNode(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	deleteNode(root->lchild);
	deleteNode(root->rchild);
	delete root;
}
int lastcnt = -1;
void Judge(Node *cur, int blackcnt)
{
	if (!flag)
	{
		return;
	}
	if (cur == NULL)
	{
		if (lastcnt == -1)
		{
			lastcnt = blackcnt;
		}
		else if (lastcnt != blackcnt)
		{
			flag = false;
		}
		return;
	}
	if (cur->black)
	{
		blackcnt++;
	}
	else
	{
		if (cur->lchild != NULL && !cur->lchild->black || cur->rchild != NULL && !cur->rchild->black)
		{
			flag = false;
		}
	}
	Judge(cur->lchild, blackcnt);
	Judge(cur->rchild, blackcnt);
}
int main()
{
	int casenum;
	cin >> casenum;
	while (casenum--)
	{
		int n;
		cin >> n;
		flag = true;
		lastcnt = -1;
		Node *root = NULL;
		for (int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			root = Build(root, t);
		}
		flag = root->black;
		if (flag)
		{
			Judge(root, 0);	
			if (flag)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		else
		{
			cout << "No" << endl;
		}
		deleteNode(root);
	}
	system("pause");
	return 0;
}