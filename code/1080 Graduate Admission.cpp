#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Node
{
public:
	int id;
	int ge;
	int gi;
	int finalgrade;
	int rank;
	int school[101];
	Node()
	{

	}
	bool operator < (const Node &A) const
	{
		if (finalgrade == A.finalgrade)
		{
			return ge > A.ge;
		}
		return finalgrade > A.finalgrade;
	}
}Applicant[40005];
class School
{
public:
	int quota;
	int lastrank;
	vector<int> student;
	School()
	{
		lastrank = 1;
	}
}school[105];
int main()
{
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		cin >> school[i].quota;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> Applicant[i].ge >> Applicant[i].gi;
		Applicant[i].id = i;
		Applicant[i].finalgrade = (Applicant[i].ge + Applicant[i].gi) / 2;
		for (int j = 0; j < k; j++)
		{
			cin >> Applicant[i].school[j];
		}
	}
	sort(Applicant, Applicant + n);
	//�Ƚ�ͷ��ѧ������
	Applicant[0].rank = 1;
	int last = 1;
	int preferred = Applicant[0].school[0];
	//������뵽��һ־ԸѧУ�Ľ����б���
	school[preferred].lastrank = 1;
	school[preferred].student.push_back(Applicant[0].id);
	//cout << Applicant[0].finalgrade << " " << Applicant[0].ge << " " << Applicant[0].rank << endl;
	for (int i = 1; i < n; i++)
	{
		if (Applicant[i].finalgrade == Applicant[i - 1].finalgrade && Applicant[i].ge == Applicant[i - 1].ge)
		{
			Applicant[i].rank = last;
		}
		else
		{
			Applicant[i].rank = i + 1;
			last = i + 1;
		}
		//cout << Applicant[i].finalgrade << " " << Applicant[i].ge << " " << Applicant[i].rank << endl;
		for (int j = 0; j < k; j++)
		{
			int target = Applicant[i].school[j];
			//־ԸѧУδ����
			if (school[target].student.size() < school[target].quota)
			{
				school[target].lastrank = Applicant[i].rank;
				school[target].student.push_back(Applicant[i].id);
				break;
			}
			//־ԸѧУ���������������һ������ͬ��ǰ
			else if (school[target].lastrank == Applicant[i].rank)
			{
				school[target].lastrank = Applicant[i].rank;
				school[target].student.push_back(Applicant[i].id);
				break;
			}
		}
		
	}

	for (int i = 0; i < m; i++)
	{
		sort(school[i].student.begin(), school[i].student.end());
		for (int j = 0; j < school[i].student.size(); j++)
		{
			if (j == 0)
			{
				cout << school[i].student[j];
			}
			else
			{
				cout << " " << school[i].student[j];
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}