#include <iostream>
#include <string>
using namespace std;

const int N = 1000;

int lcs(string X, string Y) {
  int m = X.size();
  int n = Y.size();
  int c[m+1][n+1];
  int maxl = 0;

  X = " " + X;
  Y = " " + Y;
  for (int i = 0; i <= m; i++) c[i][0] = 0;
  for (int i = 1; i <= n; i++) c[0][i] = 0;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (X[i] == Y[j]) {
        c[i][j] = c[i-1][j-1] + 1;
      } else {
        c[i][j] = max(c[i-1][j], c[i][j-1]);
      }
      maxl = max(maxl, c[i][j]);
    }
  }
  return maxl;
}

int main() {
  int n; cin >> n;
  string X, Y;
  for (int i = 0; i < n; i++) {
    cin >> X >> Y;
    cout << lcs(X, Y) << endl;
  }
}