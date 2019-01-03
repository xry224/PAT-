#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;
//第i个数字所处的位置
int num[100005];
int check(int n, int start)
{
	for (int i = start; i < n; i++)
	{
		if (num[i] != i)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	//int cur;
	int t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		num[t] = i;
	}
	//第一个位置错误的数字，其之前的数字位置均摆放正确
	int first = check(n, 1);
	int cnt = 0;
	while (first != -1)
	{
		if (num[0] == 0)
		{
			//与最近错误位置交换
			cnt++;
			num[0] = num[first];
			num[first] = 0;
		}
		while (num[0] != 0)
		{
			//获取0所在的位置
			int t = num[0];
			//将0所在位置移动
			num[0] = num[t];
			num[t] = t;
			cnt++;
			//cout << "s" << endl;
		}
		first = check(n, first);

		//cout << first << endl;
	}
	printf("%d\n", cnt);
	system("pause");
	return 0;
}