#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 3000
vector<int> course[SIZE];
int name2id(char name[])
{
	int ans = 0;
	ans = (name[3] - '0') + (name[2] - 'A') * 10 + (name[1] - 'A') * 10 * 26 + (name[0] - 'A') * 10 * 26 * 26;
	return ans;
}
int main()
{
	char name[5];
	int n, k;
	scanf("%d %d", &n, &k);
	int number;
	int cid;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &name);
		int index = name2id(name);
		scanf("%d", &number);
		for (int j = 0; j < number; j++)
		{
			scanf("%d", &cid);
			course[cid].push_back(index);	
		}
	}
	vector<int>::iterator it;
	for (int i = 1; i <= k; i++)
	{
		sort(course[i].begin(), course[i].end());
		printf("%d %d\n", i, course[i].size());
		for (it = course[i].begin(); it!=course[i].end(); it++)
		{
			int index = *it;
			char a = index / (26 * 26 * 10) + 'A';
			char b = (index % (26 * 26 * 10)) / (26 * 10) + 'A';
			char c = (index % (26 * 10)) / (10) + 'A';
			char d = index % 10 + '0';
			printf("%c%c%c%c\n", a, b, c, d);
		}
	}
	system("pause");
	return 0;
}