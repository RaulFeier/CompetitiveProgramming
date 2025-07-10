#include <bits/stdc++.h>

using namespace std;

template <class T> class aint {
private:
  T t[800004];
  T combine(T a, T b) { return min(a, b); }

public:
  void update(int node, int l, int r, int pos, int val, int sign) {
    if (l == r) {
      t[node] = val + sign * pos;
      return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid) {
      update(node * 2, l, mid, pos, val, sign);
    } else {
      update(node * 2 + 1, mid + 1, r, pos, val, sign);
    }

    t[node] = combine(t[node * 2], t[node * 2 + 1]);
  }

  T query(int node, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
      return t[node];
    }

    int mid = (l + r) / 2;
    int sol = 1e9;
    if (a <= mid) {
      sol = combine(sol, query(node * 2, l, mid, a, b));
    }

    if (b > mid) {
      sol = combine(sol, query(node * 2 + 1, mid + 1, r, a, b));
    }

    return sol;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, Q;
  cin >> N >> Q;

  aint<int> down;
  aint<int> up;

  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;

    down.update(1, 1, N, i, x, -1);
    up.update(1, 1, N, i, x, 1);
  }

  while (Q--) {
    int p;
    cin >> p;

    if (p == 1) {
      int a, b;
      cin >> a >> b;

      down.update(1, 1, N, a, b, -1);
      up.update(1, 1, N, a, b, 1);
    } else {
      int a;
      cin >> a;

      int D = down.query(1, 1, N, 1, a) + a;
      int U = up.query(1, 1, N, a, N) - a;

      cout << min(D, U) << '\n';
    }
  }

  return 0;
}

/*
    j   i

p[j] + i - j

    i   j

p[j] + j - i
*/