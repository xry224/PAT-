#include <iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> statement(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> statement[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int man = 0, wolf = 0;
			for (int k = 1; k <= n; k++)
			{
				if ((statement[k] > 0 && (statement[k] == i || statement[k] == j)) || (statement[k] < 0 && (-statement[k] != i && -statement[k] != j)))
				{
					if (k == i || k == j)
					{
						wolf++;
					}
					else
					{
						man++;
					}
				}
			}
			if (wolf == man && wolf == 1)
			{
				cout << i << " " << j << endl;
				system("pause");
				return 0;
			}
		}
	}
	cout << "No Solution" << endl;
	system("pause");
	return 0;
}