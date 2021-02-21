#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100;

int main() {
  int n; cin >> n;
  int p[N + 1];
  for (int i = 1; i <= n; i++) cin >> p[i - 1] >> p[i];

  //  DPテーブル
  int m[N + 1][N + 1];
  for (int i = 1; i <= n; i++) m[i][i] = 0;
  //  lは考える行列の数
  for (int l = 2; l <= n; l++) {
    //  iはDPテーブルの行番号
    for (int i = 1; i <= n - l + 1; i++) {
      //  jはDPテーブルの列番号
      int j = i + l - 1;
      //  最小値を知りたいので大きい値で初期化
      m[i][j] = (1 << 21);
      //  区切りをどこに入れるかでループ
      for (int k = i; k <= j - 1; k++) {
        m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
      }
    }
  }

  cout << m[1][n] << endl;

  return 0;
}