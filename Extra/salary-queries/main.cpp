#include <bits/stdc++.h>

using namespace std;

int N;
const int NMAX = 4e5 + 3;
long long fen[NMAX];

using ll = long long;

void update(int node, int val) {
  for (int i = node; i <= NMAX; i += (i & (-i))) {
    fen[i] += val;
  }
}

int query(int node) {
  int sum = 0;

  for (int i = node; i > 0; i -= (i & (-i))) {
    sum += fen[i];
  }

  return sum;
}

int sum_range(int a, int b) { return query(b) - query(a - 1); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Q;
  cin >> N >> Q;

  vector<vector<int>> operations;

  vector<int> arr(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  vector<int> numbers = arr;

  for (int i = 0; i < Q; i++) {
    char c;
    int a, b;
    cin >> c >> a >> b;

    operations.push_back({c == '!', a, b});

    if (c == '!')
      numbers.push_back(b);
  }

  sort(numbers.begin(), numbers.end());

  numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

  for (int i = 0; i < N; i++) {
    auto it = lower_bound(numbers.begin(), numbers.end(), arr[i]) -
              numbers.begin() + 1;
    update(it, 1);
  }

  for (auto &c : operations) {
    auto op = c[0], a = c[1], b = c[2];

    if (op == 0) {
      auto x =
          lower_bound(numbers.begin(), numbers.end(), a) - numbers.begin() + 1;
      auto y = upper_bound(numbers.begin(), numbers.end(), b) - numbers.begin();

      cout << sum_range(x, y) << '\n';
    } else {
      auto it = lower_bound(numbers.begin(), numbers.end(), arr[a - 1]) -
                numbers.begin() + 1;
      update(it, -1);
      arr[a - 1] = b;

      it = lower_bound(numbers.begin(), numbers.end(), b) - numbers.begin() + 1;
      update(it, 1);
    }
  }

  return 0;
}