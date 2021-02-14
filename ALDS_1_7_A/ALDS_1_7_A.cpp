#include <iostream>
using namespace std;

const int MAX = 100005;
const int NIL = -1;

//  左子右兄弟表現
struct Node {
  int parent, left, right;
};
Node T[MAX];
//  深さを記憶する
int D[MAX];

void print(int u) {
  int i, c;
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].parent << ", ";
  cout << "depth = " << D[u] << ", ";

  if (T[u].parent == NIL) cout << "root, ";
  else if (T[u].left == NIL) cout << "leaf, ";
  else cout << "internal node, ";

  cout << "[";

  for (i = 0, c = T[u].left; c != NIL; i++, c = T[c].right) {
    if (i) cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}

//  再帰的に深さを求める
void rec(int u, int p) {
  D[u] = p;
  if (T[u].right != NIL) rec(T[u].right, p);
  if (T[u].left != NIL) rec(T[u].left, p + 1);
}

int main() {
  int n; cin >> n;
  int r;
  //  Treeを初期化
  for (int i = 0; i < n; i++) T[i].parent = T[i].left = T[i].right = NIL;

  int id, dim, child, l;
  for (int i = 0; i < n; i++) {
    cin >> id >> dim;
    for (int j = 0; j < dim; j++) {
      cin >> child;
      if (j == 0) T[id].left = child;
      else T[l].right = child;
      l = child;
      T[child].parent = id;
    }
  }
  for (int i = 0; i < n; i++) {
    if (T[i].parent == NIL) r = i;
  }

  rec(r, 0);

  for (int i = 0; i < n; i++) print(i);

  return 0;
}