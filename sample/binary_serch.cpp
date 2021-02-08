#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n, q;
  cin >> n;

  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  cin >> q;
  vector<int> T(q);
  for (int i = 0; i < q; i++) {
    cin >> T[i];
  }

  int resultCnt = 0;
  vector<int>::iterator pos;
  for (int i = 0; i < q; i++) {
    pos = lower_bound(A.begin(), A.end(), T[i]);
    if (*pos == T[i]) resultCnt++;
    //if (*lower_bound(A.begin(), A.end(), T[i]) == T[i]) resultCnt++;
  }

  cout << resultCnt << endl;

  return 0;
}