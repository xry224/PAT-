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
/*处理冲突方法：Hi = (H(key) + di) % TSize (开放地址发——二次方探测再散列)
其中di为 1*1 , -1*1 , 2*2 , -2*2 , ··· k*k , -k*k (k <= MSize-1)
题目中提到 with positive increments only 所以我们只需要考虑正增量即可*/
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
		//如果k <= Msize-1 范围内没有找到，并且不确定是否有该元素，则说明该元素无法插入，将查询总数+1
		if (j == size)
		{
			cnt++;
		}
	}
	cout << fixed << setprecision(1) << (double)cnt / (double)m << endl;
	system("pause");
	return 0;
}