/*

Author: RaulFeier1
Time: 2024-07-29 22:38:33

*/

#ifndef __AHA__HEADER
#define __AHA__HEADER

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define g0 get<0>
#define g1 get<1>
#define g2 get<2>
#define ft first
#define sd second
#define sz(x) (i64) x.size()
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define all(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())
#define rvs(x) reverse(x.begin(), x.end())

#define pq priority_queue
#define fn function
#define endl '\n'

template <typename T> using vec = vector<T>;
template <typename T> using deq = deque<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename K, typename V> using gmap = gp_hash_table<K, V>;
template <typename K, typename V> using hmap = cc_hash_table<K, V>;

using str = string;
using vb = vec<bool>;

using byte = int8_t;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

using d64 = long double;

using p32 = pair<i32, i32>;
using vi32 = vec<i32>;
using vp32 = vec<p32>;

using p64 = pair<i64, i64>;
using vi64 = vec<i64>;
using vd64 = vec<d64>;
using vp64 = vec<p64>;
using vv = vec<vi64>;
using vs = vec<str>;

using dp64 = deq<p64>;
using di64 = deq<i64>;

using mi64 = map<i64, i64>;
using mp64 = map<p64, i64>;
using si64 = set<i64>;
using hi64 = hmap<i64, i64>;

using bs = bitset<64>;

using graph = vv;
using matrix = vv;

const d64 EPS = 1e-9;
const i64 INF = INT64_MAX / 4;
const i64 NINF = -INF;
const i64 ZERO = 0;
const i64 _0 = ZERO;
const i64 ONE = 1;
const i64 _1 = ONE;

template <typename T1, typename T2>
istream &operator>>(istream &stream, pair<T1, T2> &p) {
  stream >> p.ft;
  stream >> p.sd;
  return stream;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &stream, const pair<T1, T2> &p) {
  return stream << p.ft << " " << p.sd;
}

template <typename T> istream &operator>>(istream &stream, vec<T> &v) {
  if (v.empty()) {
    u64 len;
    stream >> len;
    v.assign(len, T());
  }
  for (auto i = 0; i < sz(v); i++) {
    stream >> v[i];
  }
  return stream;
}

template <typename T> ostream &operator<<(ostream &stream, const vec<T> &v) {
  if (!v.empty()) {
    stream << v[0];
  }
  for (auto i = 1; i < sz(v); i++) {
    stream << " " << v[i];
  }
  return stream;
}

#endif

struct shield {
  int l_b, u_b;
  double velocity;
};

double f(vector<shield> &v, double mid, int y) {
  int yy = 0;
  double x = 0.0;
  for (auto &c : v) {
    int aux = c.l_b - yy;
    x += aux * mid;
    yy = c.l_b;
    aux = c.u_b - yy;
    x += aux * (mid * c.velocity);
    yy = c.u_b;
  }

  int aux = y - yy;
  x += aux * mid;

  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};
#endif

  int x, y;
  cin >> x >> y;

  int N;
  cin >> N;

  vector<shield> v(N);

  for (int i = 0; i < N; i++) {
    cin >> v[i].l_b >> v[i].u_b >> v[i].velocity;
  }

  double l = -y, r = y;
  double mid;
  for (int i = 0; i < 50; i++) {
    mid = (r + l) / 2;
    double p = f(v, mid, y);

    if (p > double(x)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << fixed << setprecision(6) << r << '\n';

  return 0;
}

/*

*/
