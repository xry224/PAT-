#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int length = str.length();
	int x = (length + 2) / 3;
	int y = length - 2 * x + 2;
	int space = length - 2 * x;
	int i;
	for (i = 0; i < x - 1; i++)
	{
		int off = length - 1 - i;
		cout << str[i];
		for (int j = 0; j < space; j++)
		{
			cout << " ";
		}
		cout << str[off] << endl;
	}
	for (i = x - 1; i < x - 1 + y; i++)
	{
		cout << str[i];
	}
	cout << endl;
	system("pause");
	return 0;
}