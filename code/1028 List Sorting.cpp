#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Student
{
public:
	int ID;
	char name[10];
	int grade;
	Student()
	{

	}
}students[100001];
bool cmp1(Student A, Student B)
{
	return A.ID < B.ID;
}

bool cmp2(Student A, Student B)
{
	if ((strcmp(A.name, B.name) == 0))
	{
		return cmp1(A, B);
	}
	return strcmp(A.name, B.name) < 0;
}
bool cmp3(Student A, Student B)
{
	if (A.grade == B.grade)
	{
		return cmp1(A, B);
	}
	return A.grade < B.grade;
}
int main()
{
	int n, C;
	scanf("%d%d", &n, &C);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%s%d", &students[i].ID, &students[i].name, &students[i].grade);
	}
	switch (C)
	{
	case 1:
	{
		sort(students, students + n, cmp1);
		break;
	}
	case 2:
	{
		sort(students, students + n, cmp2);
		break;
	}
	case 3:
	{
		sort(students, students + n, cmp3);
		break;
	}
	default:
		break;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%06d %s %d\n", students[i].ID, students[i].name, students[i].grade);
	}
	system("pause");
	return 0;
}