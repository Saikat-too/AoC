#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> dirs = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
int main() {
  int H = 140;
  vector<string> s(H);
  for (string &row : s)
    cin >> row;
  int W = (int)s[0].length();
  int answer = 0;
  for (int row = 1; row < H - 1; row += 1) {
    for (int col = 1; col < W - 1; col += 1) {
      if (s[row][col] == 'A') {
        string a;
        for (pair<int, int> dir : dirs) {
          a += s[row + dir.first][col + dir.second];
        }

        if (a == "SSMM" || a == "MMSS" || a == "SMMS" || a == "MSSM")
          answer++;
      }
    }
  }

  cout << answer << '\n';
  return 0;
}
