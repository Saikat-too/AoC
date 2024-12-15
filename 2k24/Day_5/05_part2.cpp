#include <bits/stdc++.h>
#include <cassert>
#include <cctype>
using namespace std;
map<int, vector<int>> edges;
void topo(int a, vector<int> &order, map<int, int> &in,
          const set<int> present) {
  order.push_back(a);
  for (int b : edges[a]) {
    if (present.count(b)) {
      if (--in[b] == 0) {
        topo(b, order, in, present);
      }
    }
  }
}

int main() {

  string s;
  long long answer = 0;
  while (getline(cin, s)) {
    if (s.empty() || !isdigit(s[0]))
      continue;
    int len = (int)s.length();
    vector<int> v;
    bool was_pipe = false;
    for (int i = 0; i < len; i++) {
      if (isdigit(s[i])) {
        int x = 0;
        while (isdigit(s[i])) {
          x = 10 * x + (s[i] - '0');
          i++;
        }
        v.push_back(x);

        assert(s[i] == ',' || s[i] == '|' || s[i] == '\n' || s[i] == 0);
      }

      if (s[i] == '|')
        was_pipe = true;
    }

    if (was_pipe)
      edges[v[0]].push_back(v[1]);

    else {
      bool ok = true;
      set<int> prev;
      set<int> present;
      for (auto x : v)
        present.insert(x);
      map<int, int> in;

      for (int i = 0; i < (int)v.size(); i++) {
        int x = v[i];
        for (auto y : edges[x]) {
          if (present.count(y))
            ++in[y];
          if (prev.count(y))
            ok = false;
        }
        prev.insert(x);
      }
      if (ok)
        continue;
      // answer += v[v.size() / 2];
      else {
        vector<int> order;
        vector<int> starting;
        for (int x : v) {
          if (in[x] == 0)
            starting.push_back(x);
        }
        for (int x : starting) {
          topo(x, order, in, present);
        }

        for (auto u : order)
          cout << u << ' ';
        cout << '\n';

        answer += order[order.size() / 2];
      }
    }
  }

  cout << answer << '\n';
  return 0;
}
