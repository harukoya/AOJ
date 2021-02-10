#include <iostream>
using namespace std;

const int MAX = 100000;
int A[MAX];

int partition(int A[], int p, int r) {
  //  大小を比較する対象
  int x = A[r];
  //  xより小さい値の範囲を示す
  int i = p - 1;
  for (int j = p; j <= r - 1; j++) {
    if (A[j] <= x) {
      //  xより小さいグループ入り
      i++;
      int tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  //  最後の要素を正しい位置に交換
  A[r] = A[i + 1];
  A[i + 1] = x;

  return i + 1;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];

  int res_index = partition(A, 0, n - 1);
  for (int i = 0; i <= res_index - 1; i++) {
    if (i != 0) cout << " ";
    cout << A[i];
  }
  for (int i = res_index; i < n; i++) {
    if (i == res_index) {
      cout << " [";
      cout << A[i];
    } else if (i == res_index + 1) {
      cout << "] ";
      cout << A[i];
    } else {
      cout << " " << A[i];
    }
  }
  cout << endl;

  return 0;
}