#include <bits/stdc++.h>

using namespace std;

int t[800008];

void build(int node, int l, int r, vector<int> &v) {
  if (l == r) {
    t[node] = v[l];
    return;
  }

  int mid = (l + r) / 2;
  build(node * 2, l, mid, v);
  build(node * 2 + 1, mid + 1, r, v);

  t[node] = max(t[node * 2], t[node * 2 + 1]);
}

void querie(int node, int l, int r, int nr, int &sol) {
  if (l == r) {
    sol = l;
    t[node] -= nr;
    return;
  }

  int mid = (l + r) / 2;
  if (t[node * 2] >= nr) {
    querie(node * 2, l, mid, nr, sol);
  } else {
    querie(node * 2 + 1, mid + 1, r, nr, sol);
  }

  t[node] = max(t[node * 2], t[node * 2 + 1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<int> a(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  build(1, 1, N, a);

  for (int i = 0; i < M; i++) {
    int x;
    cin >> x;

    if (t[1] < x) {
      cout << 0 << " ";
      continue;
    }

    int sol = 0;
    querie(1, 1, N, x, sol);
    cout << sol << " ";
  }
  cout << '\n';

  return 0;
}