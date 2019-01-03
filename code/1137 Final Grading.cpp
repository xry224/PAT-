#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
class Student
{
public:
	string ID;
	int Gp;
	int Gmid;
	int Gfinal;
	int G;
	Student()
	{
		Gp = Gmid = Gfinal = G = -1;
	}
	Student(string name)
	{
		ID = name;
		Gp = Gmid = Gfinal = G = -1;
	}
	bool operator < (const Student &A) const
	{
		if (G == A.G)
		{
			return ID < A.ID;
		}
		return G > A.G;
	}
}students[10005];
int main()
{
	int p, m, n;
	cin >> p >> m >> n;
	int index = 1;
	map<string, int> name2id;
	string id;
	int score;
	for (int i = 0; i < p; i++)
	{
		cin >> id >> score;
		if (name2id[id] == 0)
		{
			name2id[id] = index++;
		}
		int numid = name2id[id];
		students[numid].ID = id;
		students[numid].Gp = score;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> id >> score;
		if (name2id[id] == 0)
		{
			continue;
		}
		int numid = name2id[id];
		students[numid].Gmid = score;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> id >> score;
		if (name2id[id] == 0)
		{
			continue;
		}
		int numid = name2id[id];
		students[numid].Gfinal = score;
	}
	vector<Student> ans;
	for (int i = 1; i <= index; i++)
	{
		if (students[i].Gmid > students[i].Gfinal)
		{
			students[i].G = students[i].Gmid * 0.4 + students[i].Gfinal * 0.6 + 0.5;
		}
		else
		{
			students[i].G = students[i].Gfinal;
		}
		if (students[i].G >= 60 && students[i].Gp >= 200)
			ans.push_back(students[i]);

	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].ID << " " << ans[i].Gp << " " << ans[i].Gmid << " " << ans[i].Gfinal << " " << ans[i].G << endl;
	}
	system("pause");
	return 0;
}