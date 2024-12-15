#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int main() {

  int H = 130;
  vector<string> a(H);
  for (int i = 0; i < H; i++) {

    cin >> a[i];
  }

  int W = (int)a[0].length();
  pair<int, int> start_me{-1, -1};
  for (int row = 0; row < H; row++) {
    for (int col = 0; col < W; col++) {
      if (a[row][col] == '^') {
        start_me = {row, col};
        a[row][col] = '.';
      }
    }
  }

  auto solveCycle = [&]() {
    int dir = 0;
    pair<int, int> me = start_me;
    vector<bool> vis(H * W * 4 + 1);
    bool ok = true;
    while (true) {
      int hash = (me.first * W + me.second) * 4 + dir;

      if (vis[hash]) {
        return true;
      }

      vis[hash] = true;

      int r2 = me.first + dirs[dir].first;
      int c2 = me.second + dirs[dir].second;

      if (0 > r2 || r2 >= H || 0 > c2 || c2 >= W) {
        return false;
      }

      if (a[r2][c2] == '.')
        me = {r2, c2};
      else
        dir = (dir + 1) % 4;
    }
  };

  int answer = 0;

  for (int row = 0; row < H; row++) {
    for (int col = 0; col < W; col++) {
      if (a[row][col] == '.' && start_me != make_pair(row, col)) {
        a[row][col] = '#';
        if (solveCycle()) {
          answer++;
        }
        a[row][col] = '.';
      }
    }
  }
  cout << answer << '\n';
  return 0;
}
