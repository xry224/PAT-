#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;
//��i������������λ��
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
	//��һ��λ�ô�������֣���֮ǰ������λ�þ��ڷ���ȷ
	int first = check(n, 1);
	int cnt = 0;
	while (first != -1)
	{
		if (num[0] == 0)
		{
			//���������λ�ý���
			cnt++;
			num[0] = num[first];
			num[first] = 0;
		}
		while (num[0] != 0)
		{
			//��ȡ0���ڵ�λ��
			int t = num[0];
			//��0����λ���ƶ�
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