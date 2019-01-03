#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define SIZE 200
class BigInt
{
public:
	int Digit[SIZE];
	int curpos;
	BigInt(string str)
	{
		memset(Digit, 0, sizeof(Digit));
		for (int i = str.length() - 1; i >= 0; i--)
		{
			int off = str.length() - 1 - i;
			Digit[SIZE - 1 - off] = str[i] - '0';
		}
		curpos = SIZE - str.length();
	}
	BigInt()
	{
		memset(Digit, 0, sizeof(Digit));
		curpos = SIZE - 1;
	}
	BigInt operator + (const BigInt &A) const
	{
		BigInt ans;
		int i, j, k = SIZE - 1;
		for (i = SIZE - 1, j = SIZE - 1; i >= curpos && j >= A.curpos && k>=0; i--, j--, k--)
		{
			ans.Digit[k] += Digit[i] + A.Digit[j];
			if (ans.Digit[k] >= 10)
			{
				ans.Digit[k - 1]++;
				ans.Digit[k] -= 10;
			}
		}
		while (i >= curpos)
		{
			ans.Digit[k] += Digit[i];
			if (ans.Digit[k] >= 10)
			{
				ans.Digit[k - 1]++;
				ans.Digit[k] -= 10;
			}
			i--;
			k--;
		}
		while (j >= A.curpos)
		{
			ans.Digit[k] += A.Digit[j];
			if (ans.Digit[k] >= 10)
			{
				ans.Digit[k - 1]++;
				ans.Digit[k] -= 10;
			}
			j--;
			k--;
		}
		for (int i = 0; i < SIZE; i++)
		{
			if (ans.Digit[i] != 0)
			{
				ans.curpos = i;
				break;
			}
		}
		return ans;
	}
	string toString()
	{
		string res = "";
		for (int i = curpos; i < SIZE; i++)
		{
			res += (Digit[i] + '0');
		}
		return res;
	}
};
bool check(string str)
{
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		int off = len - i - 1;
		if (str[i] != str[off])
		{
			return false;
		}
	}
	return true;
}
string inverse(string ori)
{
	string ans = "";
	for (int i = ori.length() - 1; i >= 0; i--)
	{
		ans += ori[i];
	}
	return ans;
}
string Add(string s1, string s2)
{ 
	BigInt n1 = BigInt(s1);
	BigInt n2 = BigInt(s2);
	BigInt ans = n1 + n2;
	return ans.toString();
}
string paired(string ori)
{
	string inv = inverse(ori);
	string res = Add(ori, inv);
	return res;
}
int main()
{
	string ori;
	int k;
	cin >> ori >> k;
	int i;
	bool flag = false;
	if (check(ori))
	{
		cout << ori << endl;
		cout << 0 << endl;
		return 0;
	}
	for (i = 1; i <= k; i++)
	{	
		ori = paired(ori);
		if (check(ori))
		{
			flag = true;
			break;
		}
	}
	cout << ori << endl;
	if (flag)
	{
		cout << i << endl;
	}
	else
	{
		cout << k << endl;
	}
	system("pause");
	return 0;
}