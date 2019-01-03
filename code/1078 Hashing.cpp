#include <iostream>
#include <string.h>
using namespace std;
#define SIZE 100005
int check[SIZE] = { 0 };
int prime[SIZE];
int total = 0;
void Prime()
{
	check[0] = check[1] = 1;
	for (int i = 2; i < SIZE; i++)
	{
		if (check[i] == 0)
		{
			prime[total++] = i;
		}
		for (int j = 0; j < total && i * prime[j] < SIZE; j++)
		{
			check[i * prime[j]] = 1;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
bool isprime(int n) {                  //ÅÐ¶ÏÊÇ·ñÎªËØÊý
	if (n <= 1) return false;
	if (n == 2) return true;
	for (int i = 2; i<n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	Prime();
	//int number[10005];
	bool visit[10005];
	memset(visit, false, sizeof(visit));
	int size, n;
	cin >> size >> n;
	while (check[size]!=0)
	{
		size++;
	}
	int number;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		int j;
		for ( j = 0; j < size; j++)
		{
			int pos = (number + j * j) % size;
			if (!visit[pos])
			{
				visit[pos] = true;
				cout << pos;
				break;
			}
		}
		if (j == size)
		{
			cout << "-";
		}
		if (i != n - 1)
		{
			cout << " ";
		}
	}

	cout << endl;
	system("pause");
	return 0;
}