#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
  int val;
  Node* lchild;
  Node* rchild;
  Node(int v) : val(v), lchild(nullptr), rchild(nullptr) {}
};
void dfs(Node* curNode, vector<int> curPath, vector<vector<int>>& paths) {
  curPath.push_back(curNode->val);
  if (!curNode->lchild && !curNode->rchild) {
    paths.push_back(curPath);
    return;
  }

  if (curNode->rchild)
    dfs(curNode->rchild, curPath, paths);
  if (curNode->lchild)
    dfs(curNode->lchild, curPath, paths);
}
int main() {
  int N;
  while (cin >> N) {
    int num;
    queue<Node*> q;
    Node* root = nullptr;
    // 输入同时构建树
    for (int i = 0; i < N; ++i) {
      cin >> num;
      Node* nNode = new Node(num);
      if (i == 0) {
        root = nNode;
      }

      if (!q.empty()) {
        Node* top = q.front();
        if (top->lchild == nullptr) {
          top->lchild = nNode;
        }
        else {
          top->rchild = nNode;
          q.pop();
        }
      }

      q.push(nNode);
    }
    /*
     0: undefined
     1: maxHeap
     2: minHeap;
     -1: notHeap;
    */
    int type = 0;
    vector<vector<int>> paths;
    // get all paths
    dfs(root, {}, paths);

    for (int i = 0; i < paths.size(); ++i) {
      cout << paths[i][0];
      for (int j = 1; j < paths[i].size(); ++j) {
        cout << " " << paths[i][j];
        if (type == -1) {
          continue;
        }
        // max Heap
        if (paths[i][j - 1] > paths[i][j]) {
          if (type == 2) {
            type = -1;
          }
          else {
            type = 1;
          }
        }

        // min Heap
        if (paths[i][j - 1] < paths[i][j]) {
          if (type == 1) {
            type = -1;
          }
          else {
            type = 2;
          }
        }
      }
      cout << endl;
    }
    if (type == 1)
      cout << "Max Heap\n";
    else if (type == 2)
      cout << "Min Heap\n";
    else
      cout << "Not Heap\n";
  }
  return 0;
}