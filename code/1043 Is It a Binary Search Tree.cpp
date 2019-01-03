#include <iostream>
using namespace std;
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
int cnt1 = 0, cnt2 = 0;
int preOrder[1001];
int MIpreOrder[1001];
void Post(Node *root, int level)
{
	if (root == NULL)
	{
		return;
	}
	Post(root->lchild, level + 1);
	Post(root->rchild, level + 1);
	if (level != 0)
	{
		cout << root->val << " ";
	}
	else
	{
		cout << root->val << endl;
	}
	delete root;
}
void Pre1(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	preOrder[cnt1++] = root->val; 
	Pre1(root->lchild);
	Pre1(root->rchild);
}
void Pre2(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	MIpreOrder[cnt2++] = root->val;
	Pre2(root->lchild);
	Pre2(root->rchild);
}
Node *Insert1(Node *root, int val)
{
	if (root == NULL)
	{
		root = new Node(val);
		return root;
	}
	if (val < root->val)
	{
		root->lchild = Insert1(root->lchild, val);
	}
	else
	{
		root->rchild = Insert1(root->rchild, val);
	}
	return root;
}
Node *Insert2(Node *root, int val)
{
	if (root == NULL)
	{
		root = new Node(val);
		return root;
	}
	if (val >= root->val)
	{
		root->lchild = Insert2(root->lchild, val);
	}
	else
	{
		root->rchild = Insert2(root->rchild, val);
	}
	return root;
}
void check(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << preOrder[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << MIpreOrder[i] << " ";
	}
	cout << endl;
}
int main()
{
	int seq[1005];
	int n;
	Node *root = NULL;
	Node *MIroot = NULL;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
		root = Insert1(root, seq[i]);
		MIroot = Insert2(MIroot, seq[i]);
	}
	Pre1(root);
	Pre2(MIroot);
	//check(n);
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (preOrder[i] != seq[i])
		{
			flag = false;
			break;
		}
	}
	if (!flag)
	{
		flag = true;
		for (int i = 0; i < n; i++)
		{
			if (MIpreOrder[i] != seq[i])
			{
				flag = false;
				break;
			}
		}
		if (!flag)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
			Post(MIroot, 0);
		}
	}
	else
	{
		cout << "YES" << endl;
		Post(root, 0);
	}
	system("pause");
	return 0;
}