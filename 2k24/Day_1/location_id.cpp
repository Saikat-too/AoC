#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int main() {
  vector<int> a, b;
  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back(x);
    b.push_back(y);
    mp[y] += 1;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int sum = 0, cnt = 0;
  for (int i = 0; i < N; i++) {
    // Part 1
    sum += abs(a[i] - b[i]);
    // Part 2
    cnt += a[i] * mp[a[i]];
  }

  cout << sum << ' ' << cnt << '\n';

  return 0;
}
