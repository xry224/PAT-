#include <iostream>
#include <string.h>
#include <string>
using namespace std;
bool isPrime[100000];
int P[100000];
string toAnother(long long n, int d)
{
	string res = "";
	long long t = n;
	while (t > 0)
	{
		int temp = t % d;
		res += temp + '0';
		t = t / d;
	}
	return res;
}
string inverse(string ori)
{
	string res = "";
	for (int i = ori.length() - 1; i >= 0; i--)
	{
		res += ori[i];
	}
	return res;
}
long long toDecimal(string other, int radix)
{
	long long res = 0;
	for (int i = 0; i < other.length(); i++)
	{
		res = res * radix + other[i] - '0';
	}
	return res;
}
void Prime()
{
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int cnt = 0;
	for (int i = 2; i < 100000; i++)
	{
		if (isPrime[i])
		{
			P[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * P[j] < 100000; j++)
		{
			isPrime[i * P[j]] = false;
			if (i % P[j] == 0)
			{
				break;
			}
		}
	}
}
int main()
{
	long long n;
	int d;
	Prime();
	while (cin >> n)
	{
		if (n < 0)
		{
			break;
		}
		cin >> d;
		string res = toAnother(n, d);
		//res = inverse(res);
		long long ans = toDecimal(res, d);
		if (isPrime[ans] && isPrime[n])
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}