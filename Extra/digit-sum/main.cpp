#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int comp(int a, int b) {
  if (a < b) {
    return 0;
  }

  if (a > b) {
    return 1;
  }

  return 2;
}

int to_int(char c) { return int(c - '0'); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string K;
  cin >> K;

  int d;
  cin >> d;

  vector<vector<vector<int>>> dp(K.size() + 1,
                                 vector<vector<int>>(d + 1, vector<int>(3)));

  for (int i = 0; i < 10; i++) {
    dp[1][i][comp(i, to_int(K[0]))] = 1;
  }

  for (int i = 1; i < K.size(); i++) {
    for (int curr = 0; curr < 10; curr++) {
      for (int state = 0; state < 3; state++) {
        for (int j = d; j >= 0 && j >= curr; j--) {
          if (state == 2) {
            dp[i + 1][j][comp(curr, to_int(K[i]))] =
                (dp[i + 1][j][comp(curr, to_int(K[i]))] +
                 dp[i][j - curr][state]) %
                MOD;
          }
        }
      }
    }
  }

  return 0;
}