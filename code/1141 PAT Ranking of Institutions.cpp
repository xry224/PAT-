#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
class Institution
{
public:
	string code;
	int scoreA;
	int scoreB;
	int scoreT;
	int tws;
	int ns;
	bool operator < (const Institution &A) const
	{
		if (tws == A.tws)
		{
			if (ns == A.ns)
			{
				return code < A.code;
			}
			return ns < A.ns;
		}
		return tws > A.tws;
	}
	Institution()
	{
		tws = ns = 0;
		scoreB = scoreA = scoreT = 0;
	}
	Institution(string name)
	{
		code = name;
		tws = ns = 0;
		scoreB = scoreA = scoreT = 0;
	}
};
string process(string original)
{
	string ans = "";
	for (int i = 0; i < original.size(); i++)
	{
		char c = original[i];
		if (c <= 'z' && c >= 'a')
		{
			ans += c;
		}
		else
		{
			ans += c - 'A' + 'a';
		}
	}
	return ans;
}
int main()
{
	map<string, Institution> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string id, code;
		int score;
		cin >> id >> score >> code;
		code = process(code);
		char c = id[0];
		m[code].ns++;
		m[code].code = code;
		if (c == 'A')
		{
			m[code].scoreA += score;
		}
		else if (c == 'B')
		{
			m[code].scoreB += score;
		}
		else
		{
			m[code].scoreT += score;
		}
	}
	vector<Institution> ans;
	map<string, Institution>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
	{
		Institution t = it->second;
		t.tws = t.scoreA + (double)t.scoreB / 1.5 + (double)t.scoreT * 1.5;
		ans.push_back(t);
	}
	sort(ans.begin(), ans.end());
	int lastrank = 1;
	cout << ans.size() << endl;
	cout << 1 << " " << ans[0].code << " " << ans[0].tws << " " << ans[0].ns << endl;
	for (int i = 1; i < ans.size(); i++)
	{
		if (ans[i].tws == ans[i - 1].tws)
		{
			cout << lastrank << " " << ans[i].code << " " << ans[i].tws << " " << ans[i].ns << endl;
		}
		else
		{
			cout << i + 1 << " " << ans[i].code << " " << ans[i].tws << " " << ans[i].ns << endl;
			lastrank = i + 1;
		}
	}
	system("pause");
	return 0;
}