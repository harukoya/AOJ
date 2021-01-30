#include <iostream>

bool search(int *A, int n, int key) {
  int i = 0;
  //  番兵の配置
  A[n] = key;
  while (A[i] != key) {
    i++;
  }
  if (i != n) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int n;
  std::cin >> n;
  int S[n];
  for (int i = 0; i < n; i++) {
    std::cin >> S[i];
  }

  int q;
  std::cin >> q;
  int T[q];
  for (int i = 0; i < q; i++) {
    std::cin >> T[i];
  }

  int sum = 0;
  for (int i = 0; i < q; i++) {
    if (search(S, n, T[i])) {
      sum++;
    }
  }

  std::cout << sum << std::endl;

  return 0;
}