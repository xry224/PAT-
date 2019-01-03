#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Student
{
public:
	string name;
	string id;
	int grade;
	Student()
	{

	}
	bool operator < (const Student &A) const
	{
		return grade > A.grade;
	}
};
int main()
{
	Student t;
	vector<Student> ori;
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t.name >> t.id >> t.grade;
		ori.push_back(t);
	}
	int low, up;
	cin >> low >> up;
	sort(ori.begin(), ori.end());
	int cnt = 0;
	for (int i = 0; i < ori.size(); i++)
	{
		if (ori[i].grade >= low && ori[i].grade <= up)
		{
			cnt++;
			cout << ori[i].name << " " << ori[i].id << endl;
		}
	}
	if (cnt == 0)
	{
		cout << "NONE" << endl;
	}
	system("pause");
	return 0;
}