#include <bits/stdc++.h>
using namespace std;

int changeCnt = 0;

vector<int> bubbleSort(vector<int> vec, int N) {
  bool changeFlg = true;
  while (changeFlg) {
    changeFlg = false;
    for (int i = N - 1; i >= 1; i--) {
      if (vec[i] < vec[i - 1]) {
        //  入れ替える
        int tmp = vec[i - 1];
        vec[i - 1] = vec[i];
        vec[i] = tmp;
        changeCnt++;
        changeFlg = true;
      }
    }

  }
  return vec;
}

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  //  バブルソートを呼び出し
  A = bubbleSort(A, N);
  //  ソートされた配列を表示
  for (int i = 0; i < N; i++) {
    if (i != N - 1) {
      cout << A[i] << " ";
    } else {
      cout << A[i] << endl;
    }
  }
  //  並び変えた回数を表示
  cout << changeCnt << endl;
  return 0;
}