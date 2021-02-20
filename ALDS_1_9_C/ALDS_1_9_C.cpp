#include <iostream>
#include <string>
using namespace std;

const int MAX = 2000000;
const int INFTY = 1 << 30;
int A[MAX + 1];
int H;                        //  ヒープサイズ

void maxHeapify(int i) {
  int largest;
  int l = i * 2;
  int r = i * 2 + 1;
  //  左の子、自分、右の子で値が最大のノードを選ぶ
  if (l <= H && A[l] > A[i]) {
    largest = l;
  } else {
    largest = i;
  }
  if (r <= H && A[r] > A[largest]) {
    largest = r;
  }

  if (largest != i) {
    //  値を入れ替えて、再帰呼び出し
    swap(A[i], A[largest]);
    maxHeapify(largest);
  }
}

//  ヒープ要素の最大の要素を取得し、削除
int heapExtractMax() {
  int maxv;
  if (H < 1) return -INFTY;
  maxv = A[1];
  A[1] = A[H--];
  maxHeapify(1);

  return maxv;
}

//  maxヒープが成立するように入れ替えを行う
void heapIncreaseKey(int i, int key) {
  if (key < A[i]) return;
  A[i] = key;
  //  親と値の大小を比較しながら
  while (i > 1 && A[i / 2] < A[i]) {
    swap(A[i], A[i / 2]);
    i = i / 2;
  }
}

void insert(int key) {
  H++;
  A[H] = -INFTY;
  heapIncreaseKey(H, key);
}

int main() {
  string command;
  int value;
  while (1) {
    cin >> command;
    if (command == "insert") {
      cin >> value;
      insert(value);
    } else if (command == "extract") {
      cout << heapExtractMax() << endl;
    } else {
      break;
    }
  }
}