#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Node {
  ll prefix, sum;
};

Node t[800004];

Node combine(Node a, Node b) {
  Node T;
  T.sum = a.sum + b.sum;
  T.prefix = max(a.prefix, a.sum + b.prefix);

  return T;
}

void update(int node, int l, int r, int pos, int val) {
  if (l == r) {
    t[node].prefix = val;
    t[node].sum = val;
    return;
  }

  int mid = (l + r) / 2;

  if (pos <= mid) {
    update(node * 2, l, mid, pos, val);
  } else {
    update(node * 2 + 1, mid + 1, r, pos, val);
  }

  t[node] = combine(t[node * 2], t[node * 2 + 1]);
}

Node query(int node, int l, int r, int a, int b) {
  if (a <= l && r <= b) {
    return t[node];
  }

  int mid = (l + r) / 2;
  Node sol = {0, 0};
  if (a <= mid) {
    sol = combine(query(node * 2, l, mid, a, b), sol);
  }

  if (b > mid) {
    sol = combine(sol, query(node * 2 + 1, mid + 1, r, a, b));
  }

  return sol;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, Q;
  cin >> N >> Q;

  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    update(1, 1, N, i, x);
  }

  while (Q--) {
    int p, a, b;
    cin >> p >> a >> b;

    if (p == 1) {
      update(1, 1, N, a, b);
    } else {
      cout << max(query(1, 1, N, a, b).prefix, 0LL) << '\n';
    }
  }

  return 0;
}