#include <iostream>
using namespace std;

const int MAX = 30;
const int NIL = -1;

struct Node {
  int parent, left, right;
};
Node Tree[MAX];

//  先行順巡回
void preParse(int u) {
  if (u == NIL) return;
  cout << " " << u;
  preParse(Tree[u].left);
  preParse(Tree[u].right);
}

//  中間順巡回
void inParse(int u) {
  if (u == NIL) return;
  inParse(Tree[u].left);
  cout << " " << u;
  inParse(Tree[u].right);
}

//  後行順巡回
void postParse(int u) {
  if (u == NIL) return;
  postParse(Tree[u].left);
  postParse(Tree[u].right);
  cout << " " << u;
}

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) Tree[i].parent = -1;
  int v, l, r;
  int root;
  for (int i = 0; i < n; i++) {
    cin >> v >> l >> r;
    Tree[i].left = l;
    Tree[i].right = r;
    if (l != NIL) Tree[l].parent = v;
    if (r != NIL) Tree[r].parent = v;
  }

  for (int i = 0; i < n; i++) if (Tree[i].parent == NIL) root = i;
  cout << "Preorder" << endl;
  preParse(root);
  cout << endl;
  cout << "Inorder" << endl;
  inParse(root);
  cout << endl;
  cout << "Postorder" << endl;
  postParse(root);
  cout << endl;

  return 0;
}