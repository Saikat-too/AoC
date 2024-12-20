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

        int dx = r2 - r;
        int dy = c2 - c;
        int g = __gcd(dx, dy);

        dx /= g;
        dy /= g;

        for (int rep = 0; rep < 2; rep++) {
          for (int m = 0; true; m++) {
            int row = r + dx * m;
            int col = c + dy * m;

            if (0 <= row && row < H && 0 <= col && col < W) {
              if (make_pair(row, col) != make_pair(r2, c2)) {
                if (!yes[row][col]) {
                  yes[row][col] = true;
                  answer += 1;
                }
              }
            } else
              break;
          }
          dx *= -1;
          dy *= -1;
        }
      }
    }
  }
  cout << answer << '\n';
  return 0;
}
