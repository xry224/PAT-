#include <iostream>
#include<queue>
#include<functional>
using namespace std;
int main()
{
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		q.push(t);
	}
	while (q.size() != 1)
	{
		int first = q.top();
		q.pop();
		int second = q.top();
		q.pop();
		int next = (first + second) / 2;
		q.push(next);
	}
	cout << q.top() << endl;
	system("pause");
	return 0;
}