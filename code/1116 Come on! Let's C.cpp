#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include<stdio.h>
using namespace std;
bool exist[10005];
bool visit[10005];
void Ini()
{
	memset(visit, false, sizeof(visit));
	memset(exist, false, sizeof(exist));
}
class Contestant
{
public:
	int id;
	int rank;
	string award;
	Contestant()
	{

	}
}Participants[10005];
bool isPrime(int num)
{
	int up = sqrt(num);
	for (int i = 2; i <= up; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int id;
		cin >> id;
		exist[id] = true;
		Participants[id].id = id;
		Participants[id].rank = i;
		if (i == 1)
		{
			Participants[id].award = "Mystery Award";
		}
		else if (isPrime(i))
		{
			Participants[id].award = "Minion";
		}
		else
		{
			Participants[id].award = "Chocolate";
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int id;
		cin >> id;
		if (!exist[id])
		{
			printf("%04d: Are you kidding?\n", id);
		}
		else if (!visit[id])
		{
			printf("%04d: %s\n", id, Participants[id].award.c_str());
			visit[id] = true;
		}
		else
		{
			printf("%04d: Checked\n", id);
		}
	}
	system("pause");
	return 0;
}