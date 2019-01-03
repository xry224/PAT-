#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
class User
{
public:
	int id;
	int score[6];
	//bool successSubmit[6];
	int totalscore;
	int perfect;
	bool inrank;
	User()
	{
		inrank = false;
		perfect = 0;
		totalscore = 0;
		memset(score, -1, sizeof(score));
	}
	bool operator < (const User &A) const
	{
		if (totalscore == A.totalscore)
		{
			if (perfect == A.perfect)
			{
				return id < A.id;
			}
			return perfect > A.perfect;
		}
		return totalscore > A.totalscore;
	}
}Player[100002];
int main()
{
	ios::sync_with_stdio(false);
	int n, k, m;
	int id;
	int fullmark[6];
	int serial, score;
	cin >> n >> k >> m;
	for (int i = 1; i <= k; i++)
	{
		cin >> fullmark[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> id >> serial >> score;
		Player[id].id = id;
		if (score == -1)
		{
			if (Player[id].score[serial] == -1)
			{
				Player[id].score[serial] = 0;
			}
		}
		else if (Player[id].score[serial] == -1)
		{
			Player[id].totalscore += score;
			Player[id].score[serial] = score;
			if (score == fullmark[serial])
			{
				Player[id].perfect++;
			}
			Player[id].inrank = true;
		}
		else if (Player[id].score[serial] < score)
		{
			Player[id].totalscore = Player[id].totalscore - Player[id].score[serial] + score;
			Player[id].score[serial] = score;
			if (score == fullmark[serial])
			{
				Player[id].perfect++;
			}
			Player[id].inrank = true;
		}
	}
	vector<User> ans;
	for (int i = 1; i <= n; i++)
	{
		if (Player[i].inrank)
		{
			ans.push_back(Player[i]);
		}
	}
	sort(ans.begin(), ans.end());
	printf("1 %05d %d", ans[0].id, ans[0].totalscore);
	for (int i = 1; i <= k; i++)
	{
		if (ans[0].score[i] != -1)
		{
			printf(" %d", ans[0].score[i]);
		}
		else
		{
			printf(" -");
		}
	}
	printf("\n");
	int rank = 1;
	for (int i = 1; i < ans.size(); i++)
	{
		if (ans[i].totalscore != ans[i - 1].totalscore)
		{
			rank = i + 1;
		}
		printf("%d", rank);
		printf(" %05d %d", ans[i].id, ans[i].totalscore);
		for (int j = 1; j <= k; j++)
		{
			if (ans[i].score[j] != -1)
			{
				printf(" %d", ans[i].score[j]);
			}
			else
			{
				printf(" -");
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}