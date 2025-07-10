#include <bits/stdc++.h>

using namespace std;

const int MOD = 666013;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ifstream cin{"changemin.in"};
  ofstream cout{"changemin.out"};

  int t, N;
  cin >> t >> N;

  vector<int> v(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> v[i];
  }

  long long cnt = 0;

  for (int i = 1; i <= N; i++) {
    int mn = 1e9;

    for (int j = i; j <= N; j++) {
      if (v[j] < mn) {
        mn = v[j];
        cnt++;
        cout << cnt << " " << mn << '\n';
      }
    }
  }

  if (t == 1)
    cout << cnt << '\n';

  return 0;
}
