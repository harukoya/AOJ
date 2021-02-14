#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int> >;   //  グラフ

//  ノードvを探索し、vから1ステップで行くことのできるノードたちを再帰的に探索
//  トポロジカルソート
void rec(int v, const Graph &G, vector<bool> &seen, vector<int> &order) {
  seen[v] = true;
  for (auto next : G[v]) {
    if (seen[next]) continue;   //  既に訪問済みなら探索しない
    rec(next, G, seen, order);
  }
  order.push_back(v);
}


int main() {
  int N, M; cin >> N >> M;    //  頂点数と枝数
  Graph G(N);   //  頂点数Nのグラフ
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;    //  ノードaからノードbへと有向辺を張る
    G[a].push_back(b);
  }

  //  探索
  vector<bool> seen(N, 0);
  vector<int> order;    //  トポロジカルソート順
  for (int v = 0; v < N; ++v) {
    if (seen[v]) continue;
    rec(v, G, seen, order);
  }
  reverse(order.begin(), order.end());  //  逆順にする

  //  結果の出力
  for (auto v : order) cout << v << " -> ";
  cout << endl;
}