#include <iostream>
#include <string>
using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int k) {
  //  xの親
  Node *y = NIL;
  Node *x = root;
  Node *z = new Node;
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL) {
    //  親を設定
    y = x;
    if (z->key < x->key) {
      //  左の子へ移動
      x = x->left;
    } else {
      //  右の子へ移動
      x = x->right;
    }
  }

  z->parent = y;

  if ( y == NIL) root = z;
  else if ( z->key < y->key) y->left = z;
  else y->right = z;
}

void inorder(Node *u) {
  if (u == NIL) return;
  inorder(u->left);
  cout << " " << u->key;
  inorder(u->right);
}

void preorder(Node *u) {
  if (u == NIL) return;
  cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
}

int main () {
  int n; cin >> n;
  int num;
  string command;
  for (int i = 0; i < n; i++) {
    cin >> command;
    if (command == "insert") {
      cin >> num;
      insert(num);
    } else {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
  }

  return 0;
}