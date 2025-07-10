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
  vector<int> st;

  for (int i = N; i >= 1; i--) {
    while (!st.empty() && v[i] <= st.back()) {
      st.pop_back();
    }

    st.push_back(v[i]);
    cnt += st.size();
  }

  if (t == 1) {
    cout << cnt << '\n';
    return 0;
  }

  st.clear();
  long long sumCoef = 0, sum = 0;
  long long res = 0;

  for (int i = N; i >= 1; i--) {
    while (!st.empty() && v[i] <= st.back()) {
      sumCoef = (sumCoef - sum + MOD) % MOD;
      sum = (sum - st.back() + MOD) % MOD;
      st.pop_back();
    }

    st.push_back(v[i]);
    cnt = cnt - st.size();
    sum = (1ll * sum + v[i]) % MOD;
    sumCoef = (sumCoef + sum) % MOD;

    res = ((res + (cnt * sum % MOD)) % MOD + sumCoef) % MOD;
  }

  cout << res << '\n';

  return 0;
}
