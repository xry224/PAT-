#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double game[3][3];
	int ans[3];
	char Buy[3] = { 'W','T','L' };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> game[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		double cur = game[i][0];
		ans[i] = 0;
		for (int j = 1; j < 3; j++)
		{
			if (cur < game[i][j])
			{
				ans[i] = j;
				cur = game[i][j];
			}
		}
	}
	double res;
	for (int i = 0; i < 3; i++)
	{
		cout << Buy[ans[i]] << " ";
	}
	//cout << game[0][ans[0]] << " " << game[1][ans[1]] << " " << game[2][ans[2]] << endl;
	res = (game[0][ans[0]] * game[1][ans[1]] * game[2][ans[2]] * 0.65 - 1) * 2;
	cout << fixed << setprecision(2) << (res ) << endl;
	system("pause");
	return 0;
}