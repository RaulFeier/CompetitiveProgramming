// Feier Raul the summer before college seg tree solution, but tle, needs aib

#include <bits/stdc++.h>

using namespace std;

int t[4005][4005];
int N;

int val(int a) {
  if (a == 0)
    return 1;

  return 0;
}

void update_Y(int nodeX, int l_x, int r_x, int nodeY, int l_y, int r_y, int a,
              int b) {
  if (l_y == r_y) {
    if (l_x == r_x) {
      t[nodeX][nodeY] = val(t[nodeX][nodeY]);
    } else {
      t[nodeX][nodeY] = t[nodeX * 2][nodeY] + t[nodeX * 2 + 1][nodeY];
    }

    return;
  }

  int midY = (l_y + r_y) / 2;
  if (b <= midY) {
    update_Y(nodeX, l_x, r_x, nodeY * 2, l_y, midY, a, b);
  } else {
    update_Y(nodeX, l_x, r_x, nodeY * 2 + 1, midY + 1, r_y, a, b);
  }

  t[nodeX][nodeY] = t[nodeX][nodeY * 2] + t[nodeX][nodeY * 2 + 1];
}

void update_X(int nodeX, int l_x, int r_x, int a, int b) {
  if (l_x != r_x) {
    int midX = (l_x + r_x) / 2;
    if (a <= midX) {
      update_X(nodeX * 2, l_x, midX, a, b);
    } else {
      update_X(nodeX * 2 + 1, midX + 1, r_x, a, b);
    }
  }

  update_Y(nodeX, l_x, r_x, 1, 1, N, a, b);
}

int sum_Y(int nodeX, int nodeY, int l_y, int r_y, int y1, int y2) {
  if (y1 <= l_y && r_y <= y2) {
    return t[nodeX][nodeY];
  }

  int mid = (l_y + r_y) / 2;
  int sol = 0;

  if (y1 <= mid) {
    sol += sum_Y(nodeX, nodeY * 2, l_y, mid, y1, y2);
  }

  if (mid < y2) {
    sol += sum_Y(nodeX, nodeY * 2 + 1, mid + 1, r_y, y1, y2);
  }

  return sol;
}

int sum_X(int nodeX, int l_x, int r_x, int x1, int x2, int y1, int y2) {
  if (x1 <= l_x && r_x <= x2) {
    return sum_Y(nodeX, 1, 1, N, y1, y2);
  }

  int mid = (l_x + r_x) / 2;
  int sol = 0;

  if (x1 <= mid) {
    sol += sum_X(nodeX * 2, l_x, mid, x1, x2, y1, y2);
  }

  if (x2 > mid) {
    sol += sum_X(nodeX * 2 + 1, mid + 1, r_x, x1, x2, y1, y2);
  }

  return sol;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};

  int Q;
  cin >> N >> Q;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      char c;
      cin >> c;

      if (c == '*') {
        update_X(1, 1, N, i, j);
      }
    }
  }

  for (int i = 1; i <= Q; i++) {
    int c;
    cin >> c;

    if (c == 1) {
      int a, b;
      cin >> a >> b;

      update_X(1, 1, N, a, b);
    } else {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;

      cout << sum_X(1, 1, N, x1, x2, y1, y2) << '\n';
    }
  }

  return 0;
}