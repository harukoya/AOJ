#include <iostream>
#include <map>
#include <string>
using namespace std;

void print(map<string, int> T) {
  map<string, int>::iterator itr;
  cout << T.size() << endl;
  for (itr = T.begin(); itr != T.end(); itr++) {
    pair<string, int> item = *itr;
    cout << item.first << " ---> " << item.second << endl;
  }
}
int main() {
  map<string, int> T;

  T["red"] = 32;
  T["blue"] = 688;
  T["yellow"] = 122;

  T["blue"] += 312;

  print(T);

  T.insert(make_pair("zebra", 101010));
  T.insert(make_pair("white", 0));
  T.erase("yellow");

  print(T);

  pair<string, int> target = *T.find("red");
  cout << target.first << " ---> " << target.second << endl;

  return 0;
}