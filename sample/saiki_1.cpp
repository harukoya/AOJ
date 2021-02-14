#include <iostream>
#include <vector>
using namespace std;

bool func(int i, int x, const vector<int> &a) {
  if (i == 0) {
    if (x == 0) return true;
    else return false;
  }

  if (func(i-1, x, a)) return true;

  if (func(i-1, x-a[i-1], a)) return true;

  return false;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i =0; i < n; i++) cin >> a[i];
  int x; cin >> x;

  if (func(n, x, a)) cout << "Yes" << endl;
  else cout << "No" << endl;
}