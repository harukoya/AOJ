#include <iostream>
#include <string>
using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int value) {
  Node *y = NIL;      //  zの親
  Node *x = root;     //  木の根
  Node *z = new Node;
  z->key = value;
  z->left = NIL;
  z->right = NIL;
  while (x != NIL) {
    y = x;            //  親を設定
    if (z->key < x->key) {
      x = x->left;    //  左の子へ移動
    } else {
      x = x->right;   //  右の子へ移動
    }
  }

  z->parent = y;
  if (y == NIL) {
    root = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }
}

void find(int value) {
  Node *x = root;
  while (x != NIL && value != x->key) {
    if (value < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  if (x != NIL) cout << "yes" << endl;
  else cout << "no" << endl;
}

//  中間順巡回
void inorder(Node *u) {
  if (u == NIL) return;
  inorder(u->left);
  cout << " " << u->key;
  inorder(u->right);
}

//  先行順巡回
void preorder(Node *u) {
  if (u == NIL) return;
  cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int m; cin >> m;
  int value;
  string command;
  for (int i = 0; i < m; i++) {
    cin >> command;
    if (command == "insert") {
      cin >> value;
      insert(value);
    } else if (command == "find") {
      cin >> value;
      find(value);
    } else {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
  }

  return 0;
}