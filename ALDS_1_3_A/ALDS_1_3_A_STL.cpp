#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  stack<int> S;
  int a, b;
  string s;

  while (cin >> s) {
    if (S.empty()) {
      S.push(stoi(s));
    } else if (s[0] == '+') {
      a = S.top();
      S.pop();
      b = S.top();
      S.pop();
      S.push(a + b);
    } else if (s[0] == '-') {
      b = S.top();
      S.pop();
      a = S.top();
      S.pop();
      S.push(a - b);
    } else if (s[0] == '*') {
      a = S.top();
      S.pop();
      b = S.top();
      S.pop();
      S.push(a * b);
    } else {
      S.push(stoi(s));
    }
  }

  cout << S.top() << endl;

  return 0;
}