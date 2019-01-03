#include <iostream>
#include <string>
using namespace std;
string content[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
int main()
{
	string num;
	cin >> num;
	long long ans = 0;
	for (int i = 0; i < num.length(); i++)
	{
		ans += num[i] - '0';
	}
	num = to_string(ans);
	int index = num[0] - '0';
	cout << content[index];
	for (int i = 1; i < num.length(); i++)
	{
		index = num[i] - '0';
		cout << " " << content[index];
	}
	cout << endl;
	system("pause");
	return 0;
}