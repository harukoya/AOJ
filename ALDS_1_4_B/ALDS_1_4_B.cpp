#include <iostream>

bool binarySearch(int *A, int n, int key) {
  int left = 0;
  int right = n;
  while (left < right) {
    int mid = (left + right) / 2;
    if (A[mid] == key) {
      return true;
    } else if (A[mid] > key) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return false;
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
    if (binarySearch(S, n, T[i])) {
      sum++;
    }
  }

  std::cout << sum << std::endl;
  return 0;
}