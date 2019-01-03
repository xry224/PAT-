/*Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given {32, 321, 3214, 0229, 87}, 
we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations of these segments, 
and the smallest number is 0229-321-3214-32-87.

Input Specification:

Each input file contains one test case. Each case gives a positive integer N (<=10000) followed by N number segments. 
Each segment contains a non-negative integer of no more than 8 digits. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the smallest number in one line. Do not output leading zeros.*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string number[10005];
bool cmp(string &a, string &b)
{
	return a + b < b + a;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> number[i];
	}
	sort(number, number + n, cmp);
	string ans = "";
	for (int i = 0; i < n; i++)
	{
		ans += number[i];
	}
	int i;
	for (i = 0; i < ans.length(); i++)
	{
		if (ans[i] != '0')
		{
			break;
		}
	}
	if (i == ans.length())
	{
		cout << 0 << endl;
	}
	else
	{
		cout << ans.substr(i) << endl;
	}
	system("pause");
	return 0;
}