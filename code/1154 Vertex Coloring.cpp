#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
  int N, M, K;
  while (cin >> N >> M) {
    vector<pair<int, int>> edges;
    int pointA;
    int pointB;
    for (int i = 0; i < M; ++i) {
      cin >> pointA >> pointB;
      edges.push_back(make_pair(pointA, pointB));
    }

    cin >> K;
    for (int i = 0; i < K; ++i) {
      unordered_map<int, int> verColor;
      unordered_map<int, bool> visit;
      bool qualified = true;
      int cnt = 0;
      for (int j = 0; j < N; ++j) {
        int color;
        cin >> color;
        verColor[j] = color;
        if (!visit[color]) {
          cnt++;
          visit[color] = true;
        }
      }

      for (int j = 0; j < M; ++j) {
        if (verColor[edges[j].first] == verColor[edges[j].second]) {
          qualified = false;
          break;
        }
      }

      if (qualified)
        printf("%d-coloring\n", cnt);
      else
        cout << "No\n";
    }
  }
  return 0;
}