#include <iostream>
#include <queue>
#include <vector>
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
Node *Build(int value, Node *cur)
{
	if (cur == NULL)
	{
		cur = new Node(value);
		return cur;
	}
	if (value <= cur->value)
	{
		cur->lchild = Build(value, cur->lchild);
	}
	else
	{
		cur->rchild = Build(value, cur->rchild);
	}
	return cur;
}
int main()
{
	Node *root = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		root = Build(num, root);
	}
	vector<int> levelsize;
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size();
		levelsize.push_back(size);
		for (int i = 0; i < size; i++)
		{
			Node *root = q.front();
			q.pop();
			if (root->lchild != NULL)
			{
				q.push(root->lchild);
			}
			if (root->rchild != NULL)
			{
				q.push(root->rchild);
			}
			delete root;
		}
	}
	int level = levelsize.size();
	cout << levelsize[level - 1] << " + " << levelsize[level - 2] << " = " << levelsize[level - 1] + levelsize[level - 2] << endl;	

	system("pause");
	return 0;
}