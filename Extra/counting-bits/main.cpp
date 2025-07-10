#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  long long N;
  cin >> N;

  long long i = 0;
  long long total = 0;
  while ((1LL << i) <= N) {
    long long full_cycle = (N + 1) / (1LL << (i + 1));
    long long remainder = (N + 1) % (1LL << (i + 1));
    long long extra = max(0LL, remainder - (1LL << i));
    total += full_cycle * (1LL << i) + extra;
    i++;
  }

  cout << total << '\n';

  return 0;
}