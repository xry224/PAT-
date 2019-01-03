#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <stdio.h>
using namespace std;
#define SIZE 100005
int main()
{
	priority_queue<int, vector<int>, greater<int> > NegPro;
	priority_queue<int, vector<int>, greater<int> > NegCou;
	priority_queue<int, vector<int>, less<int> > PosPro;
	priority_queue<int, vector<int>, less<int> > PosCou;
	int n, m;
	scanf("%d", &n);
	int t;
	for (int i=0;i<n;i++)
	{
		scanf("%d", &t);
		if (t < 0)
		{
			NegCou.push(t);
		}
		else
		{
			PosCou.push(t);
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &t);
		if (t < 0)
		{
			NegPro.push(t);
		}
		else
		{
			PosPro.push(t);
		}
	}
	int total = 0;
	while (!PosCou.empty() && !PosPro.empty())
	{
		total += PosCou.top() * PosPro.top();
		PosCou.pop();
		PosPro.pop();
	}
	while (!NegCou.empty() && !NegPro.empty())
	{
		total += NegCou.top() * NegPro.top();
		NegCou.pop();
		NegPro.pop();
	}
	cout << total << endl;
	system("pause");
	return 0;
}