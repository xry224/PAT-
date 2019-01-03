#include <iostream>
#include <algorithm>
using namespace std;
int ini[105];
int nexts[105];
int ans[105];
int temp[105];
bool finds = false;
int n;
bool check(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (temp[i] != nexts[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ini[i];
		temp[i] = ini[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> nexts[i];
	}
	bool insert = false;
	for (int i = 0; i < n - 1; i++)
	{
		if (temp[i] > temp[i + 1])
		{
			int t = temp[i + 1];
			int pos = i + 1;
			while (pos > 0 && temp[pos - 1] > t)
			{
				temp[pos] = temp[pos - 1];
				pos--;
			}
			temp[pos] = t;
		}
		if (insert)
		{
			for (int i = 0; i < n; i++)
			{
				ans[i] = temp[i];
			}
			break;
		}
		if (check(n))
		{
			insert = true;
		}
	}
	if (insert)
	{
		cout << "Insertion Sort" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << ans[i];
			if (i != n - 1)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	else
	{
		cout << "Merge Sort" << endl;
		int k = 1, flag = 1;
		while (flag)
		{
			flag = 0;
			for (int i = 0; i < n; i++)
			{
				if (ini[i] != nexts[i])
				{
					flag = 1;
					break;
				}
			}
			k *= 2;
			for (int i = 0; i < n / k; i++)
			{
				sort(ini + i * k, ini + (i + 1)*k);
			}
			sort(ini + (n / k)*k, ini + n);
		}
		for (int i = 0; i < n; i++)
		{
			cout << ini[i];
			if (i != n - 1)
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	system("pause");
	return 0;
}