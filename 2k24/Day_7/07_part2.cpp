#include <bits/stdc++.h>
using namespace std;

void rec(int i, long long sum, long long target, vector<long long> &v,
         bool &ok) {
  if (i == (int)v.size()) {
    if (sum == target)
      ok = true;
    return;
  }
  rec(i + 1, sum + v[i], target, v, ok);
  rec(i + 1, sum * v[i], target, v, ok);
  rec(i + 1, stoll(to_string(sum) + to_string(v[i])), target, v, ok);
}

int main() {
  long long res;
  long long answer = 0;
  while (scanf("%lld: ", &res) != EOF) {
    vector<long long> v;
    while (true) {
      long long x;
      scanf("%lld", &x);
      v.push_back(x);
      char c;
      scanf("%c", &c);
      if (c == ' ') {
        continue;
      } else {
        break;
      }
    }
    bool ok = false;
    rec(1, v[0], res, v, ok);
    if (ok)
      answer += res;
  }

  printf("%lld", answer);
  return 0;
}
