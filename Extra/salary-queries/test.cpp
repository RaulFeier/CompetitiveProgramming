#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<int> v = {1, 1, 1, 2, 2, 2, 3, 3, 5, 6, 7, 8, 10, 6};

  v.erase(unique(v.begin(), v.end()), v.end());

  auto it = lower_bound(v.begin(), v.end(), 4) - v.begin();

  cout << INT32_MAX << '\n';

  cout << it << '\n';

  return 0;
}