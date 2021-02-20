#include <iostream>
using namespace std;

const int MAX = 50;

int main() {
  int n; cin >> n;
  int F[MAX];
  F[0] = F[1] = 1;
  for (int i = 2; i <= n; i++) F[i] = F[i - 2] + F[i - 1];

  cout << F[n] << endl;

  return 0;
}