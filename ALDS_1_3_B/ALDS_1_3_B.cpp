#include <iostream>
#define LEN 100005

using namespace std;

struct process {
  char name[100];
  int t;
};

//  キュー
process Q[LEN];
//  キューの先頭
int head;
//  キューの末尾
int tail;

//  キューに要素を追加
void enqueue(struct process p) {
  Q[tail] = p;
  tail = (tail + 1) % LEN;
}

//  キューから取り出す
process dequeue() {
  process x = Q[head];
  head = (head + 1) % LEN;
  return x;
}

int main() {
  int n;
  int q;
  process u;
  int c;
  int result = 0;
  cin >> n >> q;

  //  すべてのプロセスをキューに追加する
  for (int i = 1; i <= n; i++) {
    cin >> Q[i].name >> Q[i].t;
  }
  head = 1;
  tail = n + 1;

  while (head != tail) {
    u = dequeue();
    c = min(q, u.t);
    u.t -= c;
    result += c;
    if (u.t > 0) {
      enqueue(u);
    } else {
      cout << u.name << " " << result << endl;
    }
  }

  return 0;
}