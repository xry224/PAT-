#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
class Account
{
public:
	string uname;
	string password;
	Account()
	{

	}
};
bool check(string &password)
{
	bool flag = false;
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] == '1')
		{
			password[i] = '@';
			flag = true;
		}
		else if (password[i] == '0')
		{
			password[i] = '%';
			flag = true;
		}
		else if (password[i] == 'l')
		{
			password[i] = 'L';
			flag = true;
		}
		else if (password[i] == 'O')
		{
			password[i] = 'o';
			flag = true;
		}
	}
	return flag;
}
int main()
{
	Account ans[1001];
	int n, cnt = 0;
	string user, pw;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> user >> pw;
		if (check(pw))
		{
			ans[cnt].uname = user;
			ans[cnt++].password = pw;
		}
	}
	if (cnt == 0)
	{
		if (n == 1)
		{
			printf("There is 1 account and no account is modified\n");
		}
		else
		{
			printf("There are %d accounts and no account is modified\n", n);
		}
	}
	else
	{
		cout << cnt << endl;
		for (int i = 0; i < cnt; i++)
		{
			cout << ans[i].uname << " " << ans[i].password << endl;
		}
	}

	system("pause");
	return 0;
}