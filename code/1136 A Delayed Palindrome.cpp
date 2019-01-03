#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
#define SIZE 1005
class BigInt
{
public:
	int Digit[SIZE] = { 0 };
	int pos;
	BigInt()
	{
		pos = SIZE - 1;
	}
	BigInt(string str)
	{
		for (int i = str.length() - 1; i >= 0; i--)
		{
			int off = SIZE - str.length() + i;
			Digit[off] = str[i] - '0';
		}
		pos = SIZE - str.length();
	}
	BigInt operator + (BigInt A) 
	{
		BigInt ans;
		int k = SIZE - 1;
		int i = SIZE - 1, j = SIZE - 1;
		for (; i >= pos && j >= A.pos; i--, j--)
		{
			ans.Digit[k] += Digit[i] + A.Digit[j];
			if (ans.Digit[k] >= 10)
			{
				ans.Digit[k - 1]++;
				ans.Digit[k] -= 10;
			}
			k--;
		}
		while (i >= pos)
		{
			ans.Digit[k] += Digit[i];
			if (ans.Digit[k] >= 10)
			{
				ans.Digit[k - 1]++;
				ans.Digit[k] -= 10;
			}
			k--;
			i--;
		}
		while (j >= A.pos)
		{
			ans.Digit[k] += A.Digit[j];
			if (ans.Digit[k] >= 10)
			{
				ans.Digit[k - 1]++;
				ans.Digit[k] -= 10;
			}
			k--;
			j--;
		}
		for (int i = 0; i < SIZE; i++)
		{
			if (ans.Digit[i] != 0)
			{
				ans.pos = i;
				break;
			}
		}
		return ans;
	}
	string toString()
	{
		string t = "";
		for (int i = pos; i < SIZE; i++)
		{
			t += (Digit[i] + '0');
		}
		return t;
	}
	void OutPut()
	{
		for (int i = pos; i < SIZE; i++)
		{
			cout << Digit[i];
		}
	}
};
bool check(BigInt num)
{
	int length = SIZE - num.pos + 1;
	for (int i = num.pos; i < num.pos + length / 2; i++)
	{
		int off = SIZE - 1 - (i - num.pos);
		if (num.Digit[i] != num.Digit[off])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string num;
	cin >> num;
	int turn = 0;
	BigInt number = BigInt(num);
	for (; turn < 10; turn++)
	{
		if (check(number))
		{
			break;
		}
		string t = number.toString();
		string t2 = t;
		reverse(t2.begin(), t2.end());
		BigInt a = BigInt(t);
		BigInt b = BigInt(t2);
		number = a + b;
		cout << t << " + " << t2 << " = ";
		number.OutPut();
		cout << endl;
	}
	if (check(number))
	{
		number.OutPut();
		cout << " is a palindromic number." << endl;
	}
	else
	{
		cout << "Not found in 10 iterations." << endl;
	}
	system("pause");
	return 0;
}