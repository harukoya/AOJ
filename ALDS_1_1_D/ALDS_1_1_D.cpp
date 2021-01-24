#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> R(n);
  for (int i = 0; i < n; i++) {
    cin >> R[i];
  }

  bool first_flg = true;
  int diff_price = 0;
  int min_price = R[0];
  for (int i = 1; i < n; i++) {
    if (first_flg) {
      diff_price = R[1] - min_price;
      min_price = min(min_price, R[i]);
      first_flg = false;
    } else {
      diff_price = max(diff_price, R[i] - min_price);
      min_price = min(min_price, R[i]);
    }
  }

  cout << diff_price << endl;
  return 0;
}