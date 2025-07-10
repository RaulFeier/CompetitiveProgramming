#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    uint16_t a;
    cin >> a;

    for (uint16_t j = 0; j <= 255; j++) {
      uint16_t b = j ^ (j << 1);

      b &= 0b11111111;
      if (b == a) {
        cout << j << " ";
        break;
      }
    }
  }
  cout << '\n';

  return 0;
}