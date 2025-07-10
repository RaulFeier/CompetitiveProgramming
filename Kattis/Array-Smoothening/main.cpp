#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, K;
  cin >> N >> K;

  unordered_map<int, int> m;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    m[x]++;
  }

  vector<int> arr(m.size());

  for (auto &c : m) {
    arr.push_back(c.second);
  }

  sort(arr.rbegin(), arr.rend());

  int l = 0, r = 0;

  int ans = arr[0];
  while (K) {
    while (r < m.size() - 1 && arr[l] == arr[r + 1]) {
      r++;
    }

    if (r - l + 1 <= K) {
      arr[l]--;
      K -= (r - l + 1);
    } else {
      K = 0;
    }

    ans = min(ans, arr[l]);
  }

  cout << ans << '\n';

  return 0;
}
