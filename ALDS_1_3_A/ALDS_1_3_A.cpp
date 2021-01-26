#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//  スタックの先頭(スタックポインタ)を表す
int top;
//  スタックとして用いる配列
int S[1000];

void push(int x) {
  top++;
  S[top] = x;
}

int pop() {
  top--;
  return S[top + 1];
}

int main() {
  int a, b;
  top = 0;
  string s;

  while ( cin >> s) {
    if ( s[0] == '+' ) {
      a = pop();
      b = pop();
      push(a + b);
    } else if (s[0] == '-') {
      a = pop();
      b = pop();
      push(b - a);
    } else if (s[0] == '*') {
      a = pop();
      b = pop();
      push(a * b);
    } else {
      //  string→intへ変換して格納
      push(atoi(s.c_str()));
    }
  }

  cout << pop() << endl;
  return 0;
}