#include <iostream>
#include <queue>
#include <string>

struct process {
  std::string p_name;
  int time;
};

int main() {
  int n, maxtime;
  std::cin >> n >> maxtime;

  process p;
  std::queue<process> q;
  for (int i = 0; i < n; i++) {
    std::cin >> p.p_name >> p.time;
    q.push(p);
  }

  //  処理経過時間
  int proctime = 0;
  while(!(q.empty())) {
    process execprocess = q.front();
    if (execprocess.time <= maxtime) {
      //  処理完了する
      proctime += execprocess.time;
      std::cout << execprocess.p_name << " " << proctime << std::endl;
      q.pop();
    } else {
      //  処理可能時間分だけ処理して、キューに入れる
      q.pop();
      execprocess.time = execprocess.time - maxtime;
      proctime += maxtime;
      q.push(execprocess);
    }
  }

  return 0;
}