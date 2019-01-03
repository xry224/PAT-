/*
Zhejiang University has 40000 students and provides 2500 courses. 
Now given the student name lists of all the courses, you are supposed to output the registered course list for each student who comes for a query.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=40000), 
the number of students who look for their course lists, and K (<=2500), the total number of courses. 
Then the student name lists are given for the courses (numbered from 1 to K) in the following format: for each course i, first the course index i and the number of registered students N~i~ (<= 200) are given in a line. Then in the next line, N~i~ student names are given. A student name consists of 3 capital English letters plus a one-digit number. Finally the last line contains the N names of students who come for a query. All the names and numbers in a line are separated by a space.

Output Specification:

For each test case, print your results in N lines. Each line corresponds to one student, 
in the following format: first print the student's name, then the total number of registered courses of that student, 
and finally the indices of the courses in increasing order. The query results must be printed in the same order as input. 
All the data in a line must be separated by a space, with no extra space at the end of the line.
*/
#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <stdio.h>
#include <functional>
using namespace std;
#define SIZE 200000
//map<char *, int> name2id;
priority_queue<int, vector<int>, greater<int> > Student[SIZE];
char name[5];
int name2id(char *name)
{
	return (name[0] - 'A') * 26 * 26 * 10\
		+ (name[1] - 'A') * 26 * 10\
		+ (name[2] - 'A') * 10\
		+ (name[3] - '0');
}
int main()
{
	int n, k;
	//cin >> n >> k;
	scanf("%d %d", &n, &k);
	int numcnt = 1;
	//string name;
	for (int i = 0; i < k; i++)
	{
		int index, num;
		
		scanf("%d %d", &index, &num);
		for (int j = 0; j < num; j++)
		{
			scanf("%s", &name);
			int na = name2id(name);
			Student[na].push(index);
		}
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &name);
		int na = name2id(name);
		printf("%s %d", name, Student[na].size());
		while (!Student[na].empty())
		{
			printf(" %d", Student[na].top());
			Student[na].pop();
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
