#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
int main() {
  int H = -1;
  int W = -1;

  vector<pair<int, int>> where[256];
  for (int row = 0; scanf("%s", a[row]) != EOF; row++) {
    H = row + 1;
    W = strlen(a[row]);
    for (int col = 0; col < W; col++) {
      if (a[row][col] != '.') {
        where[(int)a[row][col]].emplace_back(row, col);
      }
    }
  }

  int answer = 0;
  vector<vector<bool>> yes(H, vector<bool>(W));
  for (int z = 0; z < 256; z++) {
    const vector<pair<int, int>> &v = where[z];
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < v.size(); j++) {
        if (i == j)
          continue;
        int r = v[i].first;
        int c = v[i].second;
        int r2 = v[j].first;
        int c2 = v[j].second;

        int row = r2 + (r2 - r);
        int col = c2 + (c2 - c);
        if (0 <= row && row < H && 0 <= col && col < W) {
          if (!yes[row][col]) {
            yes[row][col] = true;
            answer += 1;
          }
        }
      }
    }
  }
  cout << answer << '\n';
  return 0;
}
