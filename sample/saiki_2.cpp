#include <iostream>
#include <vector>
using namespace std;

bool func(int i, int x, const vector<int> &a, vector<vector<int>> &dp) {
  if (i == 0) {
    if (x == 0) return true;
    else return false;
  }
  if (x < 0) return false;

  //  メモをチェック
  if (dp[i][x] != -1) return dp[i][x];

  //  a[i-1]を選ばないパターン
  if (func(i - 1, x, a, dp)) return dp[i][x] = 1; //  trueをメモしながらリターン

  //  a[i-1]を選ぶパターン
  if (func(i - 1, x - a[i - 1], a, dp)) return dp[i][x] = 1;  //  trueをメモしながらリターン

  return dp[i][x] = 0;  //  falseをメモしながらリターン
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int x; cin >> x;

  //  xの取りうる値は最大100000とすろ
  const int MAX = 100000;
  //  メモ用vector  未確定は-1で表す
  vector<vector<int>> dp(n+1, vector<int>(MAX+1, -1));
  if (func(n, x, a, dp)) cout << "Yes" << endl;
  else cout << "No" << endl;
}