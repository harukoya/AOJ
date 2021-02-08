#include <iostream>
using namespace std;

//  分割統治法（再帰関数）
int findMaxinum(int A[], int l, int r) {
  //  Divide
  int m = (l + r) / 2;
  if (l == r - 1) {
    return A[l];
  } else {
    //  前半の部分問題をsolve
    int u = findMaxinum(A, l, m);

    //  後半の部分問題をsolve
    int v = findMaxinum(A, m, r);

    //  統合して、元の問題を解く conquer
    int x = max(u, v);
    return x;
  }
}
int main() {
  int A[5] = {1, 2, 3, 4, 5};
  int size = sizeof(A) / sizeof(A[0]);
  int result = findMaxinum(A, 0, size);

  cout << "max = " << result << endl;
  return 0;
}