#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

struct Point {double x, y;};

void koch(int n, Point a, Point b) {
  if (n == 0) return;

  Point s, t, u;
  double th = M_PI * 60.0 / 180.0;   //  度からラジアンへ変換

  s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
  s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
  t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
  t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
  u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
  u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

  koch(n-1, a, s);
  cout << fixed << setprecision(8) << s.x << " " << s.y << endl;
  koch(n-1, s, u);
  cout << fixed << setprecision(8) << u.x << " " << u.y << endl;
  koch(n-1, u, t);
  cout << fixed << setprecision(8) << t.x << " " << t.y << endl;
  koch(n-1, t, b);
}

int main() {
  Point a, b;
  int n;

  cin >> n;

  a.x = 0;
  a.y = 0;
  b.x = 100;
  b.y = 0;

  cout << fixed << setprecision(8) << a.x << " " << a.y << endl;
  koch(n, a, b);
  cout << fixed << setprecision(8) << b.x << " " << b.y << endl;

  return 0;
}