#include <iostream>
#include <string>


using namespace std;

const int HASH_TABLE_SIZE = 1046527;
string Hash_table[HASH_TABLE_SIZE];

int getChar(char ch) {
  if (ch == 'A') return 1;
  else if (ch == 'C') return 2;
  else if (ch == 'G') return 3;
  else if (ch == 'T') return 4;
  else return 0;
}

long long getKey(string str) {
  long long sum = 0, p = 1, i;
  for (i = 0; i < str.length(); i++) {
    sum += p * getChar(str[i]);
    p *= 5;
  }
  return sum;
}

int hash_func1(int key) {
  return key % HASH_TABLE_SIZE;
}

int hash_func2(int key) {
  return (1 + (key % (HASH_TABLE_SIZE - 1)));
}

int hash_func(int key, int i) {
  return ((hash_func1(key) + i * hash_func2(key)) % HASH_TABLE_SIZE);
}

int find(string str) {
  long long key, i, h;
  //  文字列を数字に変換
  key = getKey(str);
  for (i = 0; ; i++) {
    h = hash_func(key, i);
    if (Hash_table[h] == str) return 1;
    else if (Hash_table[h].length() == 0) return 0;
  }
  return 0;
}

int insert (string str) {
  long long key, i, h;
  key = getKey(str);
  for (int i = 0; ; i++){
    h = hash_func(key, i);
    if (Hash_table[h] == str) return 1;
    else if (Hash_table[h].length() == 0) {
      Hash_table[h] = str;
      return 0;
    }
  }
  return 0;
}

int main() {
  int n, h;
  cin >> n;
  string str[n], com[n];
  for (int i = 0; i < n; i++) {
    cin >> com[i] >> str[i];
  }

  for (int i = 0; i < n; i++) {
    if (com[i][0] == 'i') {
      insert(str[i]);
    } else {
      if (find(str[i])) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
  return 0;
}