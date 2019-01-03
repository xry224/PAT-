#pragma warning(disable:4996)
#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 100005
class Node
{
public:
	int addr;
	int val;
	int next;
	Node()
	{

	}
}Nodes[100005];
int main()
{
	map<int, int> m;
	ios::sync_with_stdio(false);
	int head, n, k;
	cin >> head >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int addr;
		cin >> addr;
		cin >> Nodes[addr].val >> Nodes[addr].next;
		Nodes[addr].addr = addr;
		m[addr] = Nodes[addr].next;
	}
	int t = head;
	vector<Node> stack;
	while (t != -1)
	{
		stack.push_back(Nodes[t]);
		t = m[t];
		if (stack.size() % k == 0)
		{
			reverse(stack.begin() + stack.size() - k, stack.begin() + stack.size());
		}
	}
	
	int size = stack.size();
	
	for (int i = 0; i < size - 1; i++)
	{
		printf("%05d %d %05d\n", stack[i].addr, stack[i].val, stack[i + 1].addr);
	}
	printf("%05d %d -1\n", stack[size - 1].addr, stack[size - 1].val);
	system("pause");
	return 0;
}