#include <iostream>
#include <string.h>
#include <string>
using namespace std;
class BigInt
{
public:
	int Digit[30];
	int curpos;
	BigInt(string ori)
	{
		memset(Digit, 0, sizeof(Digit));
		for (int i = ori.length() - 1; i >= 0; i--)
		{
			int off = ori.length() - 1 - i;
			Digit[29 - off] = ori[i] - '0';
		}
		curpos = 29 - (ori.length() - 1);
	}
	BigInt()
	{
		curpos = 29;
		memset(Digit, 0, sizeof(Digit));
	}
	BigInt operator * (int x)
	{
		BigInt ans;
		for (int i = 29; i >= curpos; i--)
		{
			ans.Digit[i] += Digit[i] * x;
			if (ans.Digit[i] >= 10)
			{
				ans.Digit[i-1]++;
				ans.Digit[i] -= 10;
			}
		}
		for (int i = 0; i < 29; i++)
		{
			if (ans.Digit[i] != 0)
			{
				ans.curpos = i;
				break;
			}
		}
		return ans;
	}
	void Output()
	{
		for (int i = curpos; i < 30; i++)
		{
			cout << Digit[i];
		}
		cout << endl;
	}
};
int main()
{
	int count2[10] = { 0 };
	int count1[10] = { 0 };
	string num;
	cin >> num;
	BigInt n1 = BigInt(num);
	BigInt n2 = n1 * 2;
	for (int i = 29; i >= n1.curpos; i--)
	{
		int t = n1.Digit[i];
		count1[t]++;
	}
	for (int i = 29; i >= n2.curpos; i--)
	{
		int t = n2.Digit[i];
		count2[t]++;
	}
	bool flag = true;
	for (int i = 0; i < 10; i++)
	{
		if (count1[i] != count2[i])
		{
			flag = false;
		}
	}
	if (flag)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	n2.Output();
	system("pause");
	return 0;

}