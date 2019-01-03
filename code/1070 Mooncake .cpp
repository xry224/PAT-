#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
class Cake
{
public:
	double amout;
	double price;
	double profit;
	Cake()
	{

	}
	bool operator < (const Cake &A) const
	{
		return profit > A.profit;
	}
}Moon[2005];
int main()
{
	int n, demand;
	cin >> n >> demand;
	for (int i = 0; i < n; i++)
	{
		cin >> Moon[i].amout;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> Moon[i].price;
		Moon[i].profit = Moon[i].price / Moon[i].amout;
	}
	sort(Moon, Moon + n);
	double cur = 0;
	double pro = 0;
	int pos = 0;
	while (cur < demand && pos < n)
	{
		int amount = demand - cur;
		if (Moon[pos].amout <= amount)
		{
			pro += Moon[pos].price;
			cur += Moon[pos].amout;
		}
		else
		{
			cur = demand;
			pro += amount * Moon[pos].profit;
			break;
		}
		pos++;
	}
	cout << fixed << setprecision(2) << pro << endl;
	system("pause");
	return 0;
}