#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string.h>
using namespace std;
#define SIZE 99999+5
class Node
{
public:
	int id;
	int next;
	int key;
	Node()
	{

	}
}list[SIZE];
bool visit[10005];
int main()
{
	memset(visit, false, sizeof(visit));
	int head, n;
	scanf("%d %d", &head, &n);
	int add, key, next;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &add, &key, &next);
		list[add].id = add;
		list[add].key = key;
		list[add].next = next;
	}
	int t = head;
	vector<Node> linkList;
	while (list[t].next != -1)
	{
		linkList.push_back(list[t]);
		t = list[t].next;
	}
	linkList.push_back(list[t]);
	vector<Node> removed;
	vector<Node> result;
	for (int i = 0; i < linkList.size(); i++)
	{
		int key = abs(linkList[i].key);
		if (!visit[key])
		{
			visit[key] = true;
			result.push_back(linkList[i]);
		}
		else
		{
			removed.push_back(linkList[i]);
		}
	}
	int size;
	size = result.size();
	for (int i = 0; i < size - 1; i++)
	{
		printf("%05d %d %05d\n", result[i].id, result[i].key, result[i + 1].id);
	}
	printf("%05d %d -1\n", result[size - 1].id, result[size - 1].key);

    size = removed.size();
	if (size > 0)
	{
		for (int i = 0; i < size - 1; i++)
		{
			printf("%05d %d %05d\n", removed[i].id, removed[i].key, removed[i + 1].id);
		}
		printf("%05d %d -1\n", removed[size - 1].id, removed[size - 1].key);
	}
	system("pause");
	return 0;
}