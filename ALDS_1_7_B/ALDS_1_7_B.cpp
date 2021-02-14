#include <iostream>
using namespace std;

const int MAX = 30;
const int NIL = -1;

struct Node {
  int parent, left, right;
};
Node Tree[MAX];

//  各ノードの深さ
int D[MAX];
//  各ノードの高さ
int H[MAX];

//  深さをセットする関数
void setDepth(int u, int d) {
  if (u == NIL) return;
  D[u] = d;
  setDepth(Tree[u].left, d + 1);
  setDepth(Tree[u].right, d + 1);
}

//  高さをセットする関数
int setHeight(int u) {
  int h1 = 0;
  int h2 = 0;

  if (Tree[u].right != NIL) {
    h1 = setHeight(Tree[u].right) + 1;
  }
  if (Tree[u].left != NIL) {
    h2 = setHeight(Tree[u].left) + 1;
  }

  return H[u] = (h1 > h2 ? h1 : h2);
}

//  節点uの兄弟を返す
int getSibling(int u) {
  if (Tree[u].parent == NIL) return NIL;
  if (Tree[Tree[u].parent].left != u && Tree[Tree[u].parent].left != NIL) {
    return Tree[Tree[u].parent].left;
  }
  if (Tree[Tree[u].parent].right != u && Tree[Tree[u].parent].right != NIL) {
    return Tree[Tree[u].parent].right;
  }
  return NIL;
}

void print(int u) {
  cout << "node " << u << ": ";
  cout << "parent = " << Tree[u].parent << ", ";
  cout << "sibling = " << getSibling(u) << ", ";
  int deg = 0;
  if (Tree[u].left != NIL) deg++;
  if (Tree[u].right != NIL) deg++;
  cout << "degree = " << deg << ", ";
  cout << "depth = " << D[u] << ", ";
  cout << "height = " << H[u] << ", ";

  if (Tree[u].parent == NIL) {
    cout << "root" << endl;
  } else if (Tree[u].left == NIL && Tree[u].right == NIL) {
    cout << "leaf" << endl;
  } else {
    cout << "internal node" << endl;
  }
}

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) Tree[i].parent = NIL;

  int v, l, r;
  for (int i = 0; i < n; i++) {
    cin >> v >> l >> r;
    Tree[v].left = l;
    Tree[v].right = r;
    if (l != NIL) Tree[l].parent = v;
    if (r != NIL) Tree[r].parent = v;
  }

  //  rootを知りたい
  int root;
  for (int i = 0; i < n; i++) if (Tree[i].parent == NIL) root = i;

  //  各ノードの深さをセット
  setDepth(root, 0);
  //  各ノードの高さをセット
  setHeight(root);

  //  結果の表示
  for (int i = 0; i < n; i++) print(i);

  return 0;
}