#include <bits/stdc++.h>
#include <cassert>
#include <cctype>
using namespace std;

int main() {

  string s;
  map<int, vector<int>> edges;

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

      for (int i = 0; i < (int)v.size(); i++) {
        int x = v[i];
        for (auto y : edges[x]) {
          if (prev.count(y))
            ok = false;
        }
        prev.insert(x);
      }
      if (ok)
        answer += v[v.size() / 2];
    }
  }

  cout << answer << '\n';
  return 0;
}
