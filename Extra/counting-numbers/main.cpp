#include <bits/stdc++.h>

using namespace std;

int comp(int a, int b) {
  if (a < b) {
    return 0;
  }

  if (a > b)
    return 1;

  return 2;
}

long long func(long long n) {
  long long _n = n;

  if (n < 10) {
    return n;
  }

  vector<int> cif;
  while (_n != 0) {
    cif.push_back(_n % 10);
    _n /= 10;
  }

  reverse(cif.begin(), cif.end());

  vector<vector<vector<long long>>> dp(
      20, vector<vector<long long>>(10, vector<long long>(3, 0)));

  for (int i = 1; i < 10; i++) {
    dp[1][i][comp(i, cif[0])] = 1;
  }

  for (int i = 1; i < cif.size(); i++) {
    for (int curr = 0; curr < 10; curr++) {
      for (int state = 0; state < 3; state++) {
        for (int nxt = 0; nxt < 10; nxt++) {
          if (curr == nxt)
            continue;

          if (state == 2) {
            dp[i + 1][nxt][comp(nxt, cif[i])] += dp[i][curr][state];
          } else {
            dp[i + 1][nxt][state] += dp[i][curr][state];
          }
        }
      }
    }
  }

  long long ans = 0;
  for (int i = 1; i <= cif.size(); i++) {
    for (int curr = 0; curr < 10; curr++) {
      for (int state = 0; state < 3; state++) {
        if (i < cif.size() || state != 1) {
          ans += dp[i][curr][state];
        }
      }
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  long long a, b;
  cin >> a >> b;

  cout << func(b) - func(a - 1) << '\n';

  return 0;
}