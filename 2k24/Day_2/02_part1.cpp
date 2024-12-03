#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int main() {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    vector<int> a;
    while (true) {
      int x;
      scanf("%d", &x);
      a.push_back(x);
      char c;
      scanf("%c", &c);
      if (c == '\n')
        break;
    }
    bool ok = true;
    bool inc = true;
    bool dec = true;
    int n = (int)a.size();
    for (int i = 0; i < n - 1; i++) {
      int diff = (a[i] - a[i + 1]);
      if (diff > 0)
        inc = false;
      if (diff < 0)
        dec = false;
      if (1 > abs(diff) || abs(diff) > 3) {
        ok = false;
        break;
      } else
        continue;
    }

    if (ok && (inc || dec))
      cnt += 1;
  }
  cout << cnt << '\n';
  return 0;
}
