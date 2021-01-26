#include <iostream>
using namespace std;

struct Card {
  char suit;
  int value;
};

//  バブルソート
void bubbleSort(struct Card C[], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j >= i + 1; j--) {
      if (C[j].value < C[j - 1].value) {
        Card tmp = C[j - 1];
        C[j - 1] = C[j];
        C[j] = tmp;
      }
    }
  }
}

//  選択ソート
void selectionSort(struct Card C[], int N) {
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (C[minj].value > C[j].value) {
        minj = j;
      }
    }
    if (minj != i) {
      Card tmp = C[i];
      C[i] = C[minj];
      C[minj] = tmp;
    }
  }
}

//  配列の表示
void print(struct Card C[], int N) {
  for (int i = 0; i < N; i++) {
    if (i != N - 1) {
      cout << C[i].suit << C[i].value << " ";
    } else {
      cout << C[i].suit << C[i].value << endl;
    }
  }
}

//  安定なソートだったかを判定
//  (バブルソートの結果と比較を行う)
bool isStable(struct Card C1[], struct Card C2[], int N) {
  for (int i = 0; i < N; i++) {
    if (C1[i].suit != C2[i].suit) {
      return false;
    }
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  Card C1[N], C2[N];

  for(int i = 0; i < N; i++) {
    cin >> C1[i].suit >> C1[i].value;
  }
  //  カードのコピー
  for (int i = 0; i < N; i++) {
    C2[i] = C1[i];
  }

  //  バブルソート
  bubbleSort(C1, N);
  print(C1, N);

  //  バブルソートは安定なソート
  cout << "Stable" << endl;

  //  選択ソート
  selectionSort(C2, N);
  print(C2, N);

  //  バブルソートと選択ソートの結果を比較
  if (isStable(C1, C2, N)) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }

  return 0;
}