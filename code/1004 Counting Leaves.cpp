#include <iostream>
#include <string>
#include <iostream>
using namespace std;

int level = 0;
int ans[101] = { 0 };
class Node
{
public:
	int childcnt;	
	int childs[101];
	Node()
	{

	}
};
Node Tree[101];
void Count(int root, int depth)
{
	if (Tree[root].childcnt == 0)
	{
		level = level > depth ? level : depth;
		ans[depth]++;
		return;
	}
	for (int i = 0; i < Tree[root].childcnt; i++)
	{
		Count(Tree[root].childs[i], depth + 1);
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int num, name, child;
		cin >> name >> num;
		Tree[name].childcnt = num;
		for (int j = 0; j < num; j++)
		{
			cin >> child;
			Tree[name].childs[j] = child;
		}
	}
	Count(1, 1);
	cout << ans[1];
	for (int i = 2; i <= level; i++)
	{
		cout << " " << ans[i];
	}
	cout << endl;
	system("pause");
	return 0;
}