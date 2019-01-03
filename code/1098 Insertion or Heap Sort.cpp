#include <iostream>
using namespace std;
int ini[105];
int temp[105];
int nexts[105];
int ans[105];
bool check(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (nexts[i] != temp[i])
		{
			return false;
		}
	}
	return true;
}
void adjust(int nexts[], int n)
{
	int exchange = 0;
	int t = nexts[0];
	for (int i = 1; i < n; i = i * 2 + 1)
	{
		if (i + 1 < n&&nexts[i] < nexts[i + 1]) //指向左右孩子中较大的那个
		{
			i++;
		}
		if (t >= nexts[i])
		{
			break;
		}
		else
		{
			nexts[exchange] = nexts[i];
			exchange = i;
		}
	}
	nexts[exchange] = t;
}
int main()
{
	int n;
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
			int pos = i + 1;
			int t = temp[i + 1];
			while (pos > 0 && temp[pos - 1] > t)
			{
				temp[pos] = temp[pos - 1];
				pos--;
			}
			temp[pos] = t;
		}
		if (insert)
		{
			cout << "Insertion Sort" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << temp[i];
				if (i != n - 1)
				{
					cout << " ";
				}
			}
			cout << endl;
			system("pause");
			return 0;
		}
		if (check(n))
		{
			insert = true;
		}
	}
	int index = n - 1;
	while (index >= 0 && nexts[index] > nexts[0])
	{
		index--;
	}
	int t = nexts[0];
	nexts[0] = nexts[index];
	nexts[index] = t;
	adjust(nexts, index);
	cout << "Heap Sort" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << nexts[i];
		if (i != n - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}