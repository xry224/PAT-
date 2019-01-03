#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
class People
{
public:
	char name[9];
	int age;
	int wealthy;
	People()
	{

	}
	bool operator < (const People &A)const
	{
		if (wealthy == A.wealthy)
		{
			if (age == A.age)
			{
				return strcmp(name, A.name) < 0;
			}
			return age < A.age;
		}
		return wealthy > A.wealthy;
	}
};
People rankList[100005];
People filter[100005];
int agecnt[201] = { 0 };
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d %d", &rankList[i].name, &rankList[i].age, &rankList[i].wealthy);
	}
	sort(rankList, rankList + n);
	int valid = 0;
	for (int i = 0; i < n; i++)
	{
		int curage = rankList[i].age;
		if (agecnt[curage] < 100)
		{
			agecnt[curage]++;
			filter[valid++] = rankList[i];
		}
		else
		{
			continue;
		}
	}
	int m, left, right;
	for (int i = 1; i <= k; i++)
	{
		scanf("%d %d %d", &m, &left, &right);
		printf("Case #%d:\n", i);
		int cnt = 0;
		for (int i = 0; i < valid; i++)
		{
			if (filter[i].age >= left && filter[i].age <= right)
			{
				printf("%s %d %d\n", filter[i].name, filter[i].age, filter[i].wealthy);
				cnt++;
			}
			if (cnt >= m)
			{
				break;
			}
		}
		if (cnt == 0)
		{
			printf("None\n");
		}
	}
	system("pause");
	return 0;
}