#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Member
{
public:
	string ID;
	int score;
	int locationID;
	int locationRank;
	Member()
	{

	}
	bool operator < (const Member &A)const
	{
		if (score == A.score)
		{
			return ID < A.ID;
		}
		return score > A.score;
	}
};
Member testee[301];
Member ans[30001];
int main()
{
	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		string name;
		int score;
		for (int j = 0; j < m; j++)
		{
			cin >> name >> score;
			testee[j].ID = name;
			testee[j].score = score;
			testee[j].locationID = i + 1;
		}
		sort(testee, testee + m);
		testee[0].locationRank = 1;
		for (int j = 1; j < m; j++)
		{
			if (testee[j].score == testee[j - 1].score)
			{
				testee[j].locationRank = testee[j - 1].locationRank;
			}
			else
			{
				testee[j].locationRank = j + 1;
			}
		}
		for (int j = 0; j < m; j++)
		{
			ans[cnt++] = testee[j];
		}
	}
	sort(ans, ans + cnt);
	cout << cnt << endl;
	cout << ans[0].ID << " " << 1 << " " << ans[0].locationID << " " << ans[0].locationRank << endl;
	int cur = 1;
	int score = ans[0].score;
	for (int i = 1; i < cnt; i++)
	{
		if (ans[i].score == score)
		{
			cout << ans[i].ID << " " << cur << " " << ans[i].locationID << " " << ans[i].locationRank << endl;
		}
		else
		{
			cur = i + 1;
			score = ans[cur - 1].score;
			cout << ans[i].ID << " " << cur << " " << ans[i].locationID << " " << ans[i].locationRank << endl;
		}
	}
	system("pause");
	return 0;
}