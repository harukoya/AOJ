#include <iostream>
using namespace std;

const int n = 100;

int main() {
  int M[n][n];
  int num; cin >> num;
  //  番号
  int u;
  //  次数
  int k;
  //  向かう先
  int v;

  //  初期化
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < num; j++) M[i][j] = 0;
  }

  for (int i = 0; i < num; i++) {
    cin >> u >> k;
    u--;                //  0オリジンにするため
    for (int j = 0; j < k; j++) {
      cin >> v;
      v--;              //  0オリジンにする
      M[u][v] = 1;      //  u と v の間に辺を張る
    }
  }

  for (int i = 0; i < num; i++) {
    for (int j = 0; j < num; j++) {
      if (j) cout << " ";
      cout << M[i][j];
    }
    cout << endl;
  }

  return 0;
}