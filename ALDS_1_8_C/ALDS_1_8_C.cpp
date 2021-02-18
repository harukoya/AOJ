#include <iostream>
#include <string>
using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;
};
Node *root, *NIL;

void insertNode(int value) {
  Node *y = NIL;         //  zの親
  Node *x = root;
  Node *z = new Node;
  z->key = value;
  z->left = NIL;
  z->right = NIL;

  while(x != NIL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
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

Node * findNode(int value) {
  Node *x = root;
  while (x != NIL && x->key != value) {
    if (value < x->key) x = x->left;
    else x = x->right;
  }

  return x;
}

Node * getMinimum(Node *z) {
  while (z->left != NIL) {
    z = z->left;
  }
  return z;
}

Node * getSuccessor(Node *z) {
  if (z->right != NIL) return getMinimum(z->right);

  //  親をたどっていく
  Node *y = z->parent;
  while (y != NIL && z == y->right) {
    z = y;
    y = y->parent;
  }
  return y;
}

void deleteNode(Node *z) {
  //  削除する対象をyとする
  Node *y = new Node;
  if (z->left == NIL || z->right == NIL) y = z;
  else y = getSuccessor(z);

  //  yの子xを決める
  Node *x;
  if (y->left != NIL) x = y->left;
  else x = y->right;

  if (x != NIL) x->parent = y->parent;

  if (y->parent == NIL) root = x;
  else if (y == y->parent->left) y->parent->left = x;
  else y->parent->right = x;

  if (y != z) z->key = y->key;
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

int main() {
  int k; cin >> k;
  string command;
  int value;
  for (int i = 0; i < k; i++) {
    cin >> command;
    if (command == "insert") {
      cin >> value;
      insertNode(value);
    } else if (command == "find") {
      cin >> value;
      Node *t = findNode(value);
      if (t != NIL) cout << "yes" << endl;
      else cout << "no" << endl;
    } else if (command == "delete") {
      cin >> value;
      deleteNode(findNode(value));
    } else {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
  }
  
  return 0;
}