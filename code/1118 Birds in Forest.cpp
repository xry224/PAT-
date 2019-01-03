#include <iostream>
using namespace std;
int Tree[10005];
int findRoot(int x)
{
	if (Tree[x] == x)
	{
		return x;
	}
	int t = findRoot(Tree[x]);
	Tree[x] = t;
	return t;
}
void ini()
{
	for (int i = 0; i < 10005; i++)
	{
		Tree[i] = i;
	}
}
int main()
{
	int n;
	int maxnum = -1;
	cin >> n;
	ini();
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		int firstb;
		cin >> firstb;
		maxnum = firstb > maxnum ? firstb : maxnum;
		int root = findRoot(firstb);
		for (int j = 1; j < num; j++)
		{
			int t;
			cin >> t;
			maxnum = t > maxnum ? t : maxnum;
			int troot = findRoot(t);
			if (troot != root)
			{
				Tree[troot] = root;
			}
		}
	}
	int treecnt = 0;
	for (int i = 1; i <= maxnum; i++)
	{
		if (Tree[i] == i)
		{
			//cout << i << endl;
			treecnt++;
		}
	}
	cout << treecnt << " " << maxnum << endl;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		a = findRoot(a);
		b = findRoot(b);
		if (a == b)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	system("pause");
	return 0;
}