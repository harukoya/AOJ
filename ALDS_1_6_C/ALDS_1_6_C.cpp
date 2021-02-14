#include <iostream>
using namespace std;

struct Card {
  char suit;
  int value;
};

const int SENTINEL = 2000000000;
const int MAX= 100000;

Card L[MAX / 2 + 2];
Card R[MAX / 2 + 2];

int mergeCnt = 0;
void merge(Card A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i <= n1 - 1; i++) L[i] = A[left + i];
  for (int i = 0; i <= n2 - 1; i++) R[i] = A[mid + i];
  L[n1].value = SENTINEL;
  R[n2].value = SENTINEL;
  int i = 0;
  int j = 0;
  for (int k = left; k <= right - 1; k++) {
    if (L[i].value <= R[j].value) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(Card A[], int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int partition(Card A[], int p, int r) {
  int x = A[r].value;
  int i = p - 1;
  for (int j = p; j <= r - 1; j++) {
    if (A[j].value <= x) {
      i++;
      Card tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  Card tmp2 = A[i + 1];
  A[i + 1] = A[r];
  A[r] = tmp2;

  return i + 1;
}

void quickSort(Card A[], int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

int main() {
  Card A[MAX];
  Card B[MAX];
  int n;
  bool stable = true;

  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> A[i].suit >> A[i].value;
  }

  //  配列のコピー
  for (int i = 0; i < n; i++) {
    B[i] = A[i];
  }

  mergeSort(A, 0, n);
  quickSort(B, 0, n - 1);

  for (int i = 0; i < n; i++) {
    if (A[i].suit != B[i].suit) stable = false;
  }

  if (stable) cout << "Stable" << endl;
  else cout << "Not stable" << endl;
  for (int i = 0; i < n; i++) {
    cout << B[i].suit << " " << B[i].value << endl;
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    cout << A[i].suit << " " << A[i].value << endl;
  }
  return 0;
}