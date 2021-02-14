#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using Field = vector<vector<int> >;   //  盤面を二次元配列で表す

//  答えはresに格納。ただし、答えが一つとは限らないので、resをvector<Field>とする
void rec(Field &field, vector<Field> &res) {
  //  空きマスを探す
  int emptyi = -1, emptyj = -1;
  for (int i = 0; i < 9 && emptyi == -1; ++i) {
    for (int j = 0; j < 9 && emptyj == -1; ++j) {
      if (field[i][j] == -1) {
        emptyi = i, emptyj = j;
        break;
      }
    }
  }

  //  ベースケース(すべて埋めて空きマスがない)
  if (emptyi == -1 || emptyj == -1) {
    res.push_back(field);
    return;
  }

  //  空きマスに入れられる数字を求める
  vector<bool> canuse(10, 1);   //  canuse[v] :=  空きマスにvを入れられるかどうか
  for (int i = 0; i < 9; ++i) {
    //  同じ列に同じ数字はダメ(列方向に進んで、値が入っていたら、falseをメモ)
    if (field[emptyi][i] != -1) canuse[field[emptyi][i]] = false;
    //  同じ行に同じ数字はダメ
    if (field[i][emptyj] != -1) canuse[field[i][emptyj]] = false;

    //  同じブロックに同じ数字はダメ
    int bi = emptyi / 3 * 3 + 1, bj = emptyj / 3 * 3 + 1;  //  同じブロックの中央
    for (int di = bi -1; di <= bi+1; ++di) {
      for (int dj = bj -1; dj <= bj+1; ++dj) {
        if (field[di][dj] != -1) {
          canuse[field[di][dj]] = false;
        }
      }
    }
  }

  //  再起探索
  for (int v = 1; v <= 9; ++v) {
    if (!canuse[v]) continue;
    field[emptyi][emptyj] = v;
    rec(field, res);
  }

  //  数値を置いていた空きマスを元の空きマスに戻す
  field[emptyi][emptyj] = -1;
}


int main() {
  //  fieldは9*9マス（初期値は-1））
  Field field(9, vector<int>(9, -1));
  //  入力
  for (int i = 0; i < 9; ++i) {
    string line; cin >> line;
    for (int j = 0; j < 9; ++j) {
      if (line[j] == '*') continue;

      //  line[j]をintに直す
      int num = line[j] - '0';
      field[i][j] = num;
    }
  }

  //  再帰的に解く
  vector<Field> res;
  rec(field, res);

  //  答えを出力
  if (res.size() == 0) cout << "no solutions." << endl;
  else if (res.size() > 1) cout << "more than one solutions." << endl;
  else {
    Field ans = res[0];
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        cout << ans[i][j] << " ";
      }
      cout << endl;
    }
  }
}