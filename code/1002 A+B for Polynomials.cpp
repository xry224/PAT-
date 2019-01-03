#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
int main()
{
	int k;
	int poly;
	double number;
	double num[1001];
	memset(num, 0, sizeof(num));
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> poly >> number;
		num[poly] += number;
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> poly >> number;
		num[poly] += number;
	}
	int cnt = 0;
	for (int i = 0; i <= 1000; i++)
	{
		if (num[i] != 0)
		{
			cnt++;
		}
	}
	cout << cnt;
	for (int i = 1000; i >= 0; i--)
	{
		if (num[i] != 0)
		{
			cout << fixed << setprecision(1) << " " << i << " " << num[i];
		}
	}
	cout << endl;
	return 0;
}