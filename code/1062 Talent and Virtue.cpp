#pragma warning(disable:4996)
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
class People
{
public:
	int ID;
	int virtue;
	int talent;	
	People()
	{

	}
	bool operator < (const People &A)const
	{
		int total1 = virtue + talent;
		int total2 = A.virtue + A.talent;
		if (total1 == total2)
		{
			if (virtue == A.virtue)
			{
				return ID < A.ID;
			}
			return virtue > A.virtue;
		}
		return total1 > total2;
	}
};
int main()
{
	vector<People> sages;
	vector<People> noblemen;
	vector<People> fool;
	vector<People> rest;
	int n, L, H;
	People t;
	int id, tal, vir;
	scanf("%d %d %d", &n, &L, &H);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &id, &vir, &tal);
		if (vir < L || tal < L)
		{
			continue;
		}
		t.ID = id;
		t.talent = tal;
		t.virtue = vir;
		if (vir >= H && tal >= H)
		{
			sages.push_back(t);
		}
		else if (vir >= H && tal < H)
		{
			noblemen.push_back(t);
		}
		else if (vir < H && tal < H && tal <= vir)
		{
			fool.push_back(t);
		}
		else
		{
			rest.push_back(t);
		}
	}
	sort(sages.begin(), sages.end());
	sort(noblemen.begin(), noblemen.end());
	sort(fool.begin(), fool.end());
	sort(rest.begin(), rest.end());
	int number = sages.size() + noblemen.size() + fool.size() + rest.size();
	printf("%d\n", number);
	for (int i = 0; i < sages.size(); i++)
	{
		printf("%08d %d %d\n", sages[i].ID, sages[i].virtue, sages[i].talent);
	}
	for (int i = 0; i < noblemen.size(); i++)
	{
		printf("%08d %d %d\n", noblemen[i].ID, noblemen[i].virtue, noblemen[i].talent);
	}
	for (int i = 0; i < fool.size(); i++)
	{
		printf("%08d %d %d\n", fool[i].ID, fool[i].virtue, fool[i].talent);
	}
	for (int i = 0; i < rest.size(); i++)
	{
		printf("%08d %d %d\n", rest[i].ID, rest[i].virtue, rest[i].talent);
	}
	system("pause");
	return 0;
}