#include <iostream>
#include <list>
#include <string>

int main() {
  int n, num;
  std::string s;
  std::list<int> L;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> s;
    if (s[0] == 'i') {
      //  insert  挿入
      std::cin >> num;
      L.push_front(num);
    } else if (s[6] == 'F') {
      //  deleteFirst 先頭を削除
      L.pop_front();
    } else if (s[6] == 'L') {
      //  deleteLast  最後尾を削除
      L.pop_back();
    } else if (s[0] == 'd') {
      //  delete  指定された数字の位置を探して削除
      std::cin >> num;
      for (std::list<int>::iterator itr = L.begin(); itr != L.end(); itr++) {
        if (*itr == num) {
          //  一致したのでイテレータが指す要素を削除
          L.erase(itr);
          break;
        }
      }
    }
  }

  //  Listの内容を表示
  bool firstFlg = true;
  for (std::list<int>::iterator itr = L.begin(); itr != L.end(); itr++) {
    if (firstFlg) {
      std::cout << *itr;
      firstFlg = false;
    } else {
      std::cout << " " << *itr;
    }
  }
  std::cout << std::endl;

  return 0;
}