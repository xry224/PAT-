#include <iostream>
#include <string>
#include <queue>
using namespace std;
class FStudent
{
public:
	int grade;
	string name;
	string id;
	bool operator < (const FStudent &A)const
	{
		return grade < A.grade;
	}
};
class MStudent
{
public:
	int grade;
	string name;
	string id;
	bool operator < (const MStudent &A)const
	{
		return grade > A.grade;
	}
};
int main()
{
	priority_queue<MStudent> male;
	priority_queue<FStudent> female;
	int n;
	cin >> n;
	char gender;
	string name;
	string id;
	int grade;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> gender >> id >> grade;
		if (gender == 'F')
		{
			FStudent t;
			t.id = id;
			t.grade = grade;
			t.name = name;
			female.push(t);
		}
		else
		{
			MStudent t;
			t.id = id;
			t.grade = grade;
			t.name = name;
			male.push(t);
		}
	}
	int cnt = 0;
	if (female.empty())
	{
		cout << "Absent" << endl;
	}
	else
	{
		cnt++;
		cout << female.top().name << " " << female.top().id << endl;
	}
	if (male.empty())
	{
		cout << "Absent" << endl;
	}
	else
	{
		cnt++;
		cout << male.top().name << " " << male.top().id << endl;
	}
	if (cnt == 2)
	{
		cout << female.top().grade - male.top().grade << endl;
	}
	else
	{
		cout << "NA" << endl;
	}
	system("pause");
	return 0;
}