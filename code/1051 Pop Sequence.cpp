#include <iostream>
#include <stack>
using namespace std;
int number[1005];
int main()
{
	int cap, length, k;
	cin >> cap >> length >> k;

	for (int i = 0; i < k; i++)
	{
		bool flag = true;
		stack<int> s;
		int cnt = 0;
		for (int j = 0; j < length; j++)
		{
			cin >> number[j];
		}
		for (int j = 0; j < length; j++)
		{
			if (s.empty() && number[j] - cnt > cap)
			{
				flag = false;
				break;
			}
			else if (s.empty() && number[j] - cnt <= cap)
			{
				for (int o = cnt + 1; o <= number[j]; o++)
				{
					s.push(o);
				}
				cnt = number[j];
				s.pop();
			}
			else if (!s.empty())
			{
				if (s.top() == number[j])
				{
					s.pop();
				}
				else if (s.top() > number[j])
				{
					flag = false;
					break;
				}
				else
				{
					if (number[j] - cnt <= cap - s.size())
					{
						for (int o = cnt + 1; o <= number[j]; o++)
						{
							s.push(o);
						}
						cnt = number[j];
						s.pop();
					}
					else
					{
						flag = false;
						break;
					}
				}
			}
		}
		if (!flag)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
	system("pause");
	return 0;
}