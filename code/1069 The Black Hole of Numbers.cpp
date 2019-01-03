#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int Convert(int n, bool decrease)
{
	int num[4] = { 0 };
	num[3] = n % 10;
	num[2] = (n / 10) % 10;
	num[1] = (n / 100) % 10;
	num[0] = n / 1000;
	sort(num, num + 4);
	if (!decrease)
	{
		return num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
	}
	else
	{
		return num[3] * 1000 + num[2] * 100 + num[1] * 10 + num[0];
	}
}
int main()
{
	int n;
	cin >> n;
	do
	{
		int n1 = Convert(n, true);
		int n2 = Convert(n, false);
		n = n1 - n2;
		printf("%04d - %04d = %04d\n", n1, n2, n);
	} while (n != 6174 && n != 0);
	system("pause");
	return 0;

}