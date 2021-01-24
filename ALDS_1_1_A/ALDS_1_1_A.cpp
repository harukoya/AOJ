#include <bits/stdc++.h>
using namespace std;

void show(vector<int> vec) {
  int count = vec.size();
  for (int i = 0; i < count; i++) {
    if (i != count - 1) {
      cout << vec[i] << " ";
    } else {
      cout << vec[i] << endl;
    }
  }
}

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  //  初期配列の表示
  show(A);
  //  並び替え開始
  for (int i = 1; i < N; i++) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    show(A);
  }

  return 0;
}