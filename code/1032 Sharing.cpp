#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;
int linklist[100005];
int exist[100005];
int main()
{
	memset(linklist, -1, sizeof(linklist));
	memset(exist, -1, sizeof(exist));
	int first, second;
	int n;
	scanf("%d %d %d", &first, &second, &n);
	char no;
	int add, next;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %c %d", &add, &no, &next);	
		linklist[add] = next;
	}
	int t = first;
	while (t != -1)
	{
		exist[t] = 1;
		t = linklist[t];
	}
	t = second;
	while (t != -1)
	{
		if (exist[t] == 1)
		{
			break;
		}
		t = linklist[t];
	}
	if (t == -1)
	{
		printf("%d", t);
	}
	else
	{
		printf("%05d\n", t);
	}
	system("pause");
	return 0;
}