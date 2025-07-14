// iiot 2024-2025 final round
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // ifstream cin{"38-bucuresti-steaua-bucuresti.in"};

  int N, K1, K2;
  cin >> N >> K1 >> K2;

  vector<int> a(N);

  for (auto &c : a)
    cin >> c;

  // dreapta la stanga
  vector<int> st;

  int mx = -1;
  vector<int> right(N, -1);

  for (int i = N - 1; i >= 0; i--) {
    while (!st.empty() && a[i] >= a[st.back()]) {
      st.pop_back();
    }

    st.push_back(i);
    if (st.size() >= K1) {
      right[st[st.size() - K1]] = i;
    }
  }

  // stanga la dreapta
  st.clear();

  vector<int> left(N, -1);
  for (int i = 0; i < N; i++) {
    while (!st.empty() && a[i] >= a[st.back()]) {
      st.pop_back();
    }

    st.push_back(i);
    if (st.size() >= K2) {
      left[st[st.size() - K2]] = i;
    }
  }

  st.clear();
  for (int i = 0; i < N; i++) {
    while (!st.empty() && a[i] > a[st.back()]) {
      st.pop_back();
    }

    if (!st.empty() && a[st.back()] == a[i]) {
      if (right[st.back()] != -1) {
        if (right[i] != -1) {
          right[i] = min(right[i], right[st.back()]);
        } else {
          right[i] = right[st.back()];
        }
      }

      st.pop_back();
    }

    if (left[i] != -1 && right[i] != -1) {
      mx = max(mx, left[i] - right[i] + 1);
    }

    st.push_back(i);
  }

  //   for (int i = 0; i < N; i++) {
  //     cout << left[i] << " ";
  //   }
  //   cout << '\n';

  //   for (int i = 0; i < N; i++) {
  //     cout << right[i] << " ";
  //   }
  //   cout << '\n';

  cout << mx << '\n';

  return 0;
}

/*
1 1 1 2 3 3 3 3 4 5 6 7 8
*/