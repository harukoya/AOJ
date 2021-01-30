#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

//  リストの各「ノード」
struct Node {
  int key;
  Node *prev, *next;
};

//  リストの先頭を表す特別なノード「番兵」
Node *nil;
//  リストの初期化をする
//  番兵を作り、空のリストとする
void init() {
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

//  双方向リストへの要素の挿入
void insert(int key) {
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  //  番兵の直後に要素を追加
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

//  双方向リストの要素の削除
void deleteNode(Node *t) {
  if (t == nil) return;
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

//  先頭の要素の削除
void deleteFirst() {
  deleteNode(nil->next);
}

//  最後尾の要素の削除
void deleteLast() {
  deleteNode(nil->prev);
}

//  双方向リストの要素の探索
Node* listSearch(int key) {
  Node *cur = nil->next;   //  番兵の次の要素から辿る
  while (cur != nil && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

//  指定した要素の削除
void deleteKey(int key) {
  deleteNode(listSearch(key));
}

//  表示
void printList() {
  Node* cur = nil->next;
  int isf = 0;
  while(1) {
    if ( cur == nil) break;
    if (isf++ > 0) printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
  }
  printf("\n");
}

int main() {
  int key;
  int n;
  int i;
  char com[20];
  int np = 0;
  int nd = 0;

  scanf("%d", &n);
  init();

  for (int i = 0; i < n; i++) {
    scanf("%s%d", com, &key);
    if (com[0] == 'i') {
      insert(key);
    } else if (com[0] == 'd') {
      if (strlen(com) > 6) {
        if (com[6] == 'F') deleteFirst();
        else if (com[6] == 'L') deleteLast();
      } else {
        deleteKey(key);
      }
    }
  }

  printList();

  return 0;
}