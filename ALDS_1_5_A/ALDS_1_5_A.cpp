#include <iostream>
using namespace std;

int n;
int A[50];

int solve(int i, int m) {
  //  ベースケース
  if (m == 0) {
    return 1;
  }
  if (i >= n) {
    return 0;
  }
  int result = solve(i + 1, m) || solve(i + 1, m - A[i]);
  return result;
}

int main() {
  int q;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  cin >> q;
  int m[q];
  for (int i = 0; i < q; i++) {
    cin >> m[i];
  }

  for (int i = 0; i < q; i++) {
    if (solve(0, m[i])) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }

  return 0;
}