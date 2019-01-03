#include<iostream>
#include<math.h>
#include <vector>
#include <string.h>
#include <iomanip>
using namespace std;
int check[10015] = { 0 };
int prime[10015];
int visit[100005];
int primecnt = 0;
/*�����ͻ������Hi = (H(key) + di) % TSize (���ŵ�ַ���������η�̽����ɢ��)
����diΪ 1*1 , -1*1 , 2*2 , -2*2 , ������ k*k , -k*k (k <= MSize-1)
��Ŀ���ᵽ with positive increments only ��������ֻ��Ҫ��������������*/
void Prime()
{
	for (int i = 2; i < 10015; i++)
	{
		if (check[i] == 0)
		{
			prime[primecnt++] = i;
		}
		for (int j = 0; j < primecnt && i * prime[j] < 10015; j++)
		{
			check[i*prime[j]] = 1;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
int main()
{
	Prime();
	int size, n, m;
	cin >> size >> n >> m;
	if (check[size] != 0)
	{
		for (int i = 0; i < primecnt; i++)
		{
			if (prime[i] > size)
			{
				size = prime[i];
				break;
			}
		}
	}
	memset(visit, -1, sizeof(visit));
	for (int i = 0; i < n; i++)
	{
		int numbers;
		cin >> numbers;
		int j;
		for ( j = 0; j < size; j++)
		{
			int pos = (numbers + j * j) % size;
			if (visit[pos] == -1)
			{
				visit[pos] = numbers;
				break;
			}
		}
		if (j == size)
		{
			cout << numbers << " cannot be inserted." << endl;
		}
	}
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		int j;
		for ( j = 0; j < size; j++)
		{
			cnt++;
			int pos = (t + j * j) % size;
			if (visit[pos] == t || visit[pos] == -1)
			{
				break;
			}
		}
		//���k <= Msize-1 ��Χ��û���ҵ������Ҳ�ȷ���Ƿ��и�Ԫ�أ���˵����Ԫ���޷����룬����ѯ����+1
		if (j == size)
		{
			cnt++;
		}
	}
	cout << fixed << setprecision(1) << (double)cnt / (double)m << endl;
	system("pause");
	return 0;
}