#include <iostream>
using namespace std;

const int VMAX = 10000;

int main() {
  int n;
  cin >> n;
  int A[n + 1];
  //  出力用
  int B[n];
  for (int i = 0; i < n; i++) cin >> A[i + 1];

  int C[VMAX];
  for (int i = 0; i <= VMAX; i++){
    C[i] = 0;
  }
  //  C[i]にiの出現回数を記録
  for (int i = 0; i < n; i++) {
    C[A[i + 1]]++;
  }
  //  C[i]にi以下の数の出現回数を記録
  for (int i = 1; i <= VMAX; i++) {
    C[i] = C[i] + C[i - 1];
  }

  for (int i = 1; i <= n; i++) {
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

  for (int i = 1; i <= n; i++) {
    if (i != 1) cout << " " << B[i];
    else cout << B[i];
  }
  cout << endl;
}