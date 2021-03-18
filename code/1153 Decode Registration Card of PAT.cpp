#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
char getType(string card) {
  return card[0];
}
int getTestSite(string card) {
  return stoi(card.substr(1, 3));
}
string getDate(string card) {
  return card.substr(4, 6);
}
string getNum(string card) {
  return card.substr(10);
}

struct Testee {
  string card;
  int score;
  Testee(string c, int sc) {
    card = c;
    score = sc;
  }
  bool operator < (Testee& a) {
    if (score == a.score) {
      return card < a.card;
    }
    return score > a.score;
  }
};

int main() {
  int N, M;
  while (cin >> N >> M) {
    char Level;
    string card;
    int score;
    int site;
    unordered_map<char, vector<Testee>> levelInfo;
    vector<int> scoreSum(1000, 0);
    vector<int> testeeCnt(1000, 0);
    unordered_map<string, unordered_map<int, int>> siteInDate;

    for (int i = 0; i < N; ++i) {
      cin >> card >> score;
      // for query 1
      Level = getType(card);
      levelInfo[Level].emplace_back(card, score);
      // for query 2
      site = getTestSite(card);
      scoreSum[site] += score;
      testeeCnt[site]++;
      // for query 3
      string date = getDate(card);
      siteInDate[date][site]++;
    }
    // sort for query 1
    for (auto it = levelInfo.begin(); it != levelInfo.end(); ++it) {
      sort(it->second.begin(), it->second.end());
    }

    int qType;
    string data;
    for (int i = 1; i <= M; ++i) {
      cin >> qType >> data;
      printf("Case %d: %d %s\n", i, qType, data.c_str());
      switch (qType) {
      case 1: {
        Level = data[0];
        vector<Testee> res = levelInfo[Level];
        if (res.empty()) {
          cout << "NA" << endl;
          break;
        }
        for (int i = 0; i < res.size(); ++i) {
          cout << res[i].card << " " << res[i].score << endl;
        }
        break;
      }

      case 2: {
        site = stoi(data);
        int sum = scoreSum[site];
        int cnt = testeeCnt[site];
        if (cnt == 0) {
          cout << "NA" << endl;
          break;
        }
        cout << cnt << " " << sum << endl;
        break;
      }

      case 3: {
        auto sites = siteInDate[data];
        if (sites.empty()) {
          cout << "NA" << endl;
          break;
        }

        vector<pair<int, int>> res;
        for (auto it = sites.begin(); it != sites.end(); ++it) {
          res.push_back(make_pair(it->first, it->second));
        }
        sort(res.begin(), res.end(), [](auto& a, auto& b) {
          if (a.second == b.second) {
            return a.first < b.first;
          }
          return a.second > b.second;
          });

        for (int i = 0; i < res.size(); ++i) {
          cout << res[i].first << " " << res[i].second << endl;
        }
        break;
      }
      }
    }
  }
  return 0;
}