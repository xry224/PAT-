#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	string number;
	long long num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		num = atoll(number.c_str());
		int half = number.length() / 2;
		long long n1 = 0;
		long long n2 = 0;
		for (int i = 0; i < half; i++)
		{
			n1 *= 10;
			n1 += (number[i] - '0');
		}
		for (int i = half; i < number.length(); i++)
		{
			n2 *= 10;
			n2 += (number[i] - '0');
		}
		if (num == 0 || n1 == 0 || n2 == 0)
		{
			cout << "No" << endl;
		}
		else if (num % n1 == 0 && num / n1 % n2 ==0)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

	system("pause");
	return 0;
}