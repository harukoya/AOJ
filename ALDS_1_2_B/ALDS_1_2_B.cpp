#include <iostream>
#include <vector>
using namespace std;

int changeCnt = 0;
//  選択ソート
vector<int> selectionSort(vector<int> vec, int N) {
  for (int i = 0; i < N - 1; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (vec[j] < vec[minj]) {
        minj = j;
      }
    }
    //  入れ替えが発生するか
    if (minj != i) {
      changeCnt++;
      int tmp = vec[i];
      vec[i] = vec[minj];
      vec[minj] = tmp;
    }
  }

  return vec;
}

//  配列の要素を表示
void showVec(vector<int> vec) {
  int cnt = vec.size();
  for (int i = 0; i < cnt; i++) {
    if (i != cnt -1) {
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

  //  選択ソートの呼び出し
  A = selectionSort(A, N);
  //  ソート後の配列を表示
  showVec(A);
  cout << changeCnt << endl;

  return 0;
}