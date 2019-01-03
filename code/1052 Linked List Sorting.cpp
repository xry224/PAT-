#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Node
{
public:
	int addre;
	int next;
	int key;
	Node(int a, int n, int k)
	{
		addre = a;
		next = n;
		key = k;
	}
	Node()
	{

	}
	bool operator < (const Node &A)const
	{
		return key < A.key;
	}
};	
Node linklist[100005];
Node ans[100005];
int add2int[100005];
int main()
{
	int n, head;

	scanf("%d %d", &n, &head);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &linklist[i].addre, &linklist[i].key, &linklist[i].next);
		add2int[linklist[i].addre] = i;
	}
	int t = head;
	int cnt = 0;
	while (t != -1)
	{
		ans[cnt++] = linklist[add2int[t]];
		t = linklist[add2int[t]].next;
	}
	sort(ans, ans + cnt);
	if (cnt == 0)
	{
		printf("0 -1\n");
	}
	else
	{
		printf("%d %05d\n", cnt, ans[0].addre);
		for (int i = 0; i < cnt - 1; i++)
		{
			printf("%05d %d %05d\n", ans[i].addre, ans[i].key, ans[i + 1].addre);
		}
		printf("%05d %d -1\n", ans[cnt - 1].addre, ans[cnt - 1].key);
	}

	system("pause");
	return 0;
}