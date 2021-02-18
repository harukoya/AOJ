#include <iostream>
using namespace std;

const int MAX = 2000000;
int H, A[MAX + 1];

void maxHeapify(int i) {
  int largest;
  int l = i * 2;
  int r = i * 2 + 1;
  //  左の子、右の子、自分で値が最大のノード位置を選ぶ
  if (l <= H && A[l] > A[i]) {
    largest = l;
  } else {
    largest = i;
  }
  if (r <= H && A[r] > A[largest]) {
    largest = r;
  }

  if (largest != i) {
    swap(A[i], A[largest]);
    maxHeapify(largest);
  }
}

int main() {
  cin >> H;
  for (int i = 1; i <= H; i++) cin >> A[i];

  for (int i = H / 2; i >= 1; i--) maxHeapify(i);

  for (int i = 1; i <= H; i++) {
    cout << " " << A[i];
  }
  cout << endl;

  return 0;
}