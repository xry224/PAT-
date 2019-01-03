#include<iostream>
#include <queue>
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
		lchild = rchild = NULL;
	}
};
int inOrder[50];
int postOrder[50];
int findTar(int tatget, int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		if (inOrder[i] == tatget)
		{
			return i;
		}
	}
	return -1;
}
Node *Build(int mids, int mide, int posts, int poste)
{
	int val = postOrder[poste];
	Node *root = new Node(val);
	int index = findTar(val, mids, mide);
	if (index == -1)
	{
		cout << "Damn it" << endl;
		return NULL;
	}
	//左子树不为空
	if (mids != index)
	{
		int length = index - mids;
		root->lchild = Build(mids, index - 1, posts, posts + length - 1);
	}
	//右子树不为空
	if (index != mide)
	{
		int length = mide - index;
		root->rchild = Build(index + 1, mide, poste - length, poste - 1);
	}
	return root;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inOrder[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> postOrder[i];
	}
	Node *root = NULL;
	root = Build(0, n - 1, 0, n - 1);
	queue<Node*> q;
	cout << root->val;
	if (root->lchild != NULL)
	{
		q.push(root->lchild);
	}
	if (root->rchild != NULL)
	{
		q.push(root->rchild);
	}
	delete root;
	bool left2eight = true;
	vector<int> output;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			Node *cur = q.front();
			q.pop();
			output.push_back(cur->val);
			if (cur->lchild != NULL)
			{
				q.push(cur->lchild);
			}
			if (cur->rchild != NULL)
			{
				q.push(cur->rchild);
			}
			delete cur;
		}
		if (left2eight)
		{
			for (int i = 0; i < output.size(); i++)
			{
				cout << " " << output[i];
			}
		}
		else
		{
			for (int i = output.size() - 1; i >= 0; i--)
			{
				cout << " " << output[i];
			}
		}
		output.clear();
		left2eight = !left2eight;
	}
	cout << endl;
	system("pause");
	return 0;
}