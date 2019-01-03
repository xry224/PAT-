#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include<vector>
using namespace std;
class Node
{
public:
	int address;
	int value;
	int next;
	Node()
	{
		next = -1;
	}
}linkList[100005];
bool first = true;
void Output(vector<Node> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (first)
		{
			printf("%05d %d ", list[i].address, list[i].value);
			first = false;
		}
		else
		{
			printf("%05d\n%05d %d ", list[i].address, list[i].address, list[i].value);
		}
	}
}
int main()
{
	int start, n, k;
	cin >> start >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int add, val, next;
		cin >> add >> val >> next;
		linkList[add].address = add;
		linkList[add].value = val;
		linkList[add].next = next;
	}
	vector<Node> validlist;
	vector<Node>::iterator it;
	vector<Node> neglist;
	vector<Node> rangelist;
	int t = start;
	while (t != -1)
	{
		if (linkList[t].value < 0)
		{
			neglist.push_back(linkList[t]);
		}
		else if (linkList[t].value >= 0 && linkList[t].value <= k)
		{
			rangelist.push_back(linkList[t]);
		}
		else
		{
			validlist.push_back(linkList[t]);
		}
		t = linkList[t].next;
	}
	
	Output(neglist);
	Output(rangelist);
	Output(validlist);
	printf("-1\n");
	system("pause");
	return 0;
}