#include <bits/stdc++.h>
using namespace std;

int main() {
  int H = 140;
  vector<string> s(H);
  for (string &row : s)
    cin >> row;
  const string tmp = "XMAS";
  int W = (int)s[0].length();
  int answer = 0;
  auto inside = [&](int row, int col) {
    return 0 <= row && row < H && 0 <= col && col < W;
  };
  for (int row = 0; row < H; row += 1) {
    for (int col = 0; col < W; col += 1) {
      if (s[row][col] == 'X') {
        for (int drow = -1; drow <= 1; drow += 1) {
          for (int dcol = -1; dcol <= 1; dcol += 1) {
            bool ok = true;
            if (drow == 0 && dcol == 0) {
              continue;
            }
            for (int i = 0; i < 4; i++) {
              int r2 = row + drow * i;
              int c2 = col + dcol * i;
              if (inside(r2, c2) && s[r2][c2] == tmp[i])
                ok = true;
              else {
                ok = false;
                break;
              }
            }
            answer += ok;
          }
        }
      }
    }
  }

  cout << answer << '\n';
  return 0;
}
