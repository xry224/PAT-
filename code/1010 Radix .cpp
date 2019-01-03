#include <iostream>
#include <string>
#include <math.h>
using namespace std;
long long Cal(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else
	{
		return (c - 'a') + 10;
	}
}
long long getNum(string n, int radix)
{
	long long ans = 0;
	for (int i = 0; i < n.length(); i++)
	{
		long long num = Cal(n[i]);
		ans = ans * radix + num;
		if (ans < 0)
		{
			return -1;
		}
	}
	return ans;
}
long long check(string n)
{
	long long max = Cal(n[0]);
	for (int i = 1; i < n.length(); i++)
	{
		long long num = Cal(n[i]);
		if (max < num)
		{
			max = num;
		}
	}
	return max;
}
int main()
{
	string n1, n2;
	int tag, radix;
	long long decn1 = 0;
	long long decn2 = 0;
	long long ans = -1;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2)
	{
		string t = n1;
		n1 = n2;
		n2 = t;
	}
	//计算给定进制数的十进制值
	decn1 = getNum(n1, radix);
	//遍历所有进制可能
	long long low = check(n2) + 1;
	long long up = decn1 + 1;
	long long mid;
	//cout << low << " " << up << endl;
	while (low <= up)
	{
		mid = (low + up) / 2;
		//cout << mid << endl;
		//cout << low << " " << up << endl;
		decn2 = getNum(n2, mid);
		if (decn2 > decn1 || decn2 == -1)
		{
			up = mid - 1;
		}
		else if (decn2 < decn1)
		{
			low = mid + 1;
		}
		else if (decn1 == decn2)
		{
			ans = mid;
			break;
		}
	}
	if (ans != -1)
	{
		cout << ans << endl;
	}
	else
	{
		cout << "Impossible" << endl;
	}

	system("pause");
	return 0;
}