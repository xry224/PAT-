#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
struct Student
{
	string name;
	int math;
	int cprogram;
	int english;
	double avg;
	int best;
	int t;
	char bestr;
};
Student s[2001];
bool cmpm(Student A, Student B)
{
	return A.math > B.math;
}
bool cmpe(Student A, Student B)
{
	return A.english > B.english;
}
bool cmpc(Student A, Student B)
{
	return A.cprogram > B.cprogram;
}
bool cmpa(Student A, Student B)
{
	return A.avg > B.avg;
}
Student getStu(string name, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (s[i].name == name)
		{
			return s[i];
		}
	}

}
int main()
{
	int n, m;
	map<string, int> mt;
	cin >> n >> m;
	string stu;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i].name >> s[i].cprogram >> s[i].math >> s[i].english;
		s[i].avg = (s[i].cprogram + s[i].math + s[i].english) / 3;
		//全部学生默认Avg均排名第一
		s[i].best = 1;
		s[i].bestr = 'A';
	}
	/*处理*/
	//先对Avg分数排序并以此为每名学生的当前BestRank
	sort(s, s + n, cmpa);
	for (int i = 1; i < n; i++)
	{
		if (s[i].avg == s[i - 1].avg)
		{
			s[i].best = s[i - 1].best;
		}
		else
		{
			s[i].best = i + 1;
		}
	}

	sort(s, s + n, cmpc);
	s[0].t = 1;
	if (s[0].t < s[0].best)
	{
		s[0].best = s[0].t;
		s[0].bestr = 'C';
	}
	for (int i = 1; i < n; i++)
	{
		int level = i + 1;
		if (s[i].cprogram == s[i - 1].cprogram)
		{
			s[i].t = s[i - 1].t;
		}
		else
		{
			s[i].t = level;
		}
		if (s[i].t < s[i].best)
		{
			s[i].best = s[i].t;
			s[i].bestr = 'C';
		}
	}

	sort(s, s + n, cmpm);
	s[0].t = 1;
	if (s[0].t < s[0].best)
	{
		s[0].best = s[0].t;
		s[0].bestr = 'M';
	}
	for (int i = 1; i < n; i++)
	{
		int level = i + 1;
		if (s[i].math == s[i - 1].math)
		{
			s[i].t = s[i - 1].t;
		}
		else
		{
			s[i].t = level;
		}
		if (s[i].t < s[i].best)
		{
			s[i].best = s[i].t;
			s[i].bestr = 'M';
		}
	}

	sort(s, s + n, cmpe);
	s[0].t = 1;
	if (s[0].t < s[0].best)
	{
		s[0].best = s[0].t;
		s[0].bestr = 'E';
	}
	for (int i = 1; i < n; i++)
	{
		int level = i + 1;
		if (s[i].english == s[i - 1].english)
		{
			s[i].t = s[i - 1].t;
		}
		else
		{
			s[i].t = level;
		}
		if (s[i].t < s[i].best)
		{
			s[i].best = s[i].t;
			s[i].bestr = 'E';
		}
	}


	for (int i = 0; i < n; i++)
	{
		mt[s[i].name] = i + 1;
	}
	/*处理*/
	for (int i = 0; i < m; i++)
	{
		cin >> stu;
		if (mt[stu] == 0)
		{
			cout << "N/A" << endl;
		}
		else
		{
			Student t = s[mt[stu] - 1];
			cout << t.best << " " << t.bestr << endl;
		}
	}
	system("pause");
	return 0;
}