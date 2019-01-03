#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool first;
void PostOrder(vector<int> levelorder, int nodecnt, int curnode)
{
	if (curnode >= nodecnt)
	{
		return;
	}
	PostOrder(levelorder, nodecnt, curnode * 2 + 1);
	PostOrder(levelorder, nodecnt, curnode * 2 + 2);
	if (first)
	{
		cout << levelorder[curnode];
		first = false;
	}
	else
	{
		cout << " " << levelorder[curnode];
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		vector<int> levelorder(m);
		for (int j = 0; j < m; j++)
		{
			cin >> levelorder[j];
		}
		int heaptype;
		//С����
		if (levelorder[0] < levelorder[1])
		{
			heaptype = 1;
		}
		//�󶥶�
		else
		{
			heaptype = 2;
		}
		bool flag = true;
		for (int j = 0; j <= m / 2 - 1; j++)
		{
			int lchild = j * 2 + 1;
			int rchild = j * 2 + 2;
			if (heaptype == 1)
			{
				//С����
				if (lchild < m)
				{
					if (levelorder[j] > levelorder[lchild])
					{
						flag = false;
						break;
					}
				}
				if (rchild < m)
				{
					if (levelorder[j] > levelorder[rchild])
					{
						flag = false;
						break;
					}
				}
			}
			else
			{
				//�󶥶�
				if (lchild < m)
				{
					if (levelorder[j] < levelorder[lchild])
					{
						flag = false;
						break;
					}
				}
				if (rchild < m)
				{
					if (levelorder[j] < levelorder[rchild])
					{
						flag = false;
						break;
					}
				}
			}
		}
		if (!flag)
		{
			cout << "Not Heap" << endl;
		}
		else
		{
			if (heaptype == 1)
			{
				cout << "Min Heap" << endl;
			}
			else
			{
				cout << "Max Heap" << endl;
			}
		}
		first = true;
		PostOrder(levelorder, m, 0);
		cout << endl;
	}
	system("pause");
	return 0;
}