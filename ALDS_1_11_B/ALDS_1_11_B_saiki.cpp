#include <iostream>
using namespace std;

static const int N = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[N][N];
int color[N], d[N], f[N], tt;

//  再帰による深さ優先探索
void dfs_visit(int u) {
  int v;
  color[u] = GRAY;
  d[u] = ++tt;
  for (v = 0; v < n; v++) {
    if (M[u][v] == 0) continue;
    if (color[v] == WHITE) {
      dfs_visit(v);
    }
  }
  f[u] = ++tt;
  color[u] = BLACK;
}

void dfs() {
  int u;
  //  初期化
  for (u = 0; u < n; u++) color[u] = WHITE;
  tt = 0;

  for (int u = 0; u < n; u++) {
    //  未訪問のuを始点として深さ優先探索
    if (color[u] == WHITE) dfs_visit(u);
  }
  for (int u = 0; u < n; u++) {
    cout << u + 1 << " " << d[u] << " " << f[u] << endl;
  }
}

int main() {
  int u, k, v;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      M[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    u--;
    for (int j = 0; j < k; j++) {
      cin >> v;
      v--;
      M[u][v] = 1;
    }
  }

  dfs();

  return 0;
}