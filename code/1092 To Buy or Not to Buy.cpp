#include <iostream>
#include <string>
using namespace std;
int main()
{
	string shop, eva;
	cin >> shop;
	cin >> eva;
	int cnt = 0;
	for (int i = 0; i < eva.length(); i++)
	{
		int index = shop.find(eva[i]);
		if (index != string::npos)
		{
			shop[index] = ' ';
		}
		else
		{
			cnt++;
		}
	}
	if (cnt == 0)
	{
		cout << "Yes " << shop.size() - eva.size() << endl;
	}
	else
	{
		cout << "No " << cnt << endl;
	}
	system("pause");
	return 0;
}