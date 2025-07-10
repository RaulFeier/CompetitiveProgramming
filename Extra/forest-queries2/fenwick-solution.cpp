#include <bits/stdc++.h>

using namespace std;

int fen[1003][1003];
int N;

void update(int x, int y, int val) {
  for (int i = x; i <= N; i += (i & (-i))) {
    for (int j = y; j <= N; j += (j & (-j))) {
      fen[i][j] += val;
    }
  }
}

int query(int x, int y) {
  int sum = 0;

  for (int i = x; i > 0; i -= (i & (-i))) {
    for (int j = y; j > 0; j -= (j & (-j))) {
      sum += fen[i][j];
    }
  }

  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Q;
  cin >> N >> Q;

  char c[N + 1][N + 1];

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> c[i][j];

      if (c[i][j] == '*') {
        update(i, j, 1);
      }
    }
  }

  for (int i = 0; i < Q; i++) {
    int p;
    cin >> p;

    if (p == 1) {
      int a, b;
      cin >> a >> b;

      if (c[a][b] == '*') {
        c[a][b] = '.';
        update(a, b, -1);
      } else {
        c[a][b] = '*';
        update(a, b, 1);
      }
    } else {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;

      cout << query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) +
                  query(x1 - 1, y1 - 1)
           << '\n';
    }
  }

  return 0;
}