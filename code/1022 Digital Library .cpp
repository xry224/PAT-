#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
class Book
{
public:
	string ID;
	string title;
	string author;
	string keyword;
	string publisher;
	string year;
	bool operator < (const Book &A) const
	{
		return ID < A.ID;
	}
	Book()
	{

	}
};
Book library[10001];
void searchName(string key)
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (library[i].title == key)
		{
			flag = true;
			cout << library[i].ID << endl;
		}
	}
	if (!flag)
	{
		cout << "Not Found" << endl;
	}
}
void searchAuthor(string key)
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (library[i].author == key)
		{
			flag = true;
			cout << library[i].ID << endl;
		}
	}
	if (!flag)
	{
		cout << "Not Found" << endl;
	}
}
void searchkey(string key)
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (library[i].keyword.find(key) != string::npos)
		{
			flag = true;
			cout << library[i].ID << endl;
		}
	}
	if (!flag)
	{
		cout << "Not Found" << endl;
	}
}
void searchPublisher(string key)
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (library[i].publisher == key)
		{
			flag = true;
			cout << library[i].ID << endl;
		}
	}
	if (!flag)
	{
		cout << "Not Found" << endl;
	}
}
void searchYear(string key)
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (library[i].year == key)
		{
			flag = true;
			cout << library[i].ID << endl;
		}
	}
	if (!flag)
	{
		cout << "Not Found" << endl;
	}
}
int main()
{
	string ID;
	string title;
	string author;
	string keyword;
	string publisher;
	string year;
	string t;
	cin >> n;
	//吃回车
	getline(cin, t);
	for (int i = 0; i < n; i++)
	{
		getline(cin, ID);
		getline(cin, title);
		getline(cin, author);
		getline(cin, keyword);
		getline(cin, publisher);
		getline(cin, year);
		library[i].ID = ID;
		library[i].title = title;
		library[i].author = author;
		library[i].keyword = keyword;
		library[i].publisher = publisher;
		library[i].year = year;
	}
	sort(library, library + n);
	cin >> m;
	//吃回车
	getline(cin, t);
	string request;
	for (int i = 0; i < m; i++)
	{
		getline(cin, request);

		cout << request << endl;
		string key = request.substr(3);
		char command = request[0];
		switch (command)
		{
		case '1':
		{
			searchName(key);
			break;
		}
		case '2':
		{
			searchAuthor(key);
			break;
		}
		case '3':
		{
			searchkey(key);
			break;
		}
		case '4':
		{
			searchPublisher(key);
			break;
		}
		case '5':
		{
			searchYear(key);
			break;
		}
		default:
			break;
		}
	}
	system("pause");
	return 0;
}