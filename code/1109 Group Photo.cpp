#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class People
{
public:
	string name;
	int height;
	People()
	{

	}
	People(string str, int h)
	{
		name = str;
		height = h;
	}
	bool operator < (const People &A)const
	{
		if (height == A.height)
		{
			return name < A.name;
		}
		return height > A.height;
	}
};
int main()
{
	int n, k;
	cin >> n >> k;
	vector<People> students;
	People t;
	int num = n / k;
	int extra = n - num * k;//最后一排需要额外站的人
	int midpos = num / 2 + 1;
	int lastmid = (num + extra) / 2 + 1;
	for (int i = 0; i < n; i++)
	{
		string name;
		int height;
		cin >> name >> height;
		t = People(name, height);
		students.push_back(t);
	}
	sort(students.begin(), students.end());

	vector<vector<People> > ans(k);
	int cur = 0;
	for (int i = 0; i < k; i++)
	{
		int size = i == 0 ? num + extra : num;		
		ans[i].resize(size);
		int mid = i == 0 ? lastmid : midpos;
		mid--;
		ans[i][mid] = students[cur];		
		int off1 = 1;
		int off2 = 1;
		for (int j = cur + 1; j < cur + size; j++)
		{
			int index = j - cur;
			if (index % 2 != 0)
			{
				ans[i][mid - off1] = students[j];
				off1++;
			}
			else
			{
				ans[i][mid + off2] = students[j];
				off2++;
			}
		}
		cur = cur + size;
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j].name;
			if (j != ans[i].size() - 1)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}