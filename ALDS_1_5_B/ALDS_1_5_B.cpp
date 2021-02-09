/*
  マージソート
  指定されたn個の要素を含む部分配列をn/2個の要素を含む
  部分配列に分割(Divide)
  それぞれをmergeSortでソート(Solve)
  得られた2つのソート済み部分配列をmergeで統合(Conquer)
*/
#include <iostream>
using namespace std;

const int SENTINEL = 2000000000;

int cnt = 0;

void merge(int A[], int n, int left, int mid, int right) {
  //  左側部分配列
  int n1 = mid - left;
  int L[n1];
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  //  右側部分配列
  int n2 = right - mid;
  int R[n2];
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }

  //  番兵
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;

  //  左側配列のカウンタ
  int i = 0;
  //  右側配列のカウンタ
  int j = 0;
  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
      cnt++;
    } else {
      A[k] = R[j];
      j++;
      cnt++;
    }
  }
}

void mergeSort(int A[], int n, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;

  int S[n];
  for (int i = 0; i < n; i++) cin >> S[i];

  mergeSort(S, n, 0, n);

  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << S[i];
  }
  cout << endl;

  cout << cnt << endl;

  return 0;
}