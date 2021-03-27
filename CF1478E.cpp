#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

const int N = 2e5 + 5;

int t[4 * N];
int z[4 * N];
string s, f;
int n, q;

void build(int v, int tl, int tr) {
  z[v] = -1;
  if (tl == tr) {
    t[v] = (f[tl] - '0');
  } else {
    int tm = (tl + tr) >> 1;
    build(v + v + 1, tl, tm);
    build(v + v + 2, tm + 1, tr);
    t[v] = t[v + v + 1] + t[v + v + 2];
  }
}


void push(int tl, int tr, int v) {
  if (z[v] != -1) {
    t[v] = (tr - tl + 1) * z[v];
    if (tl != tr) {
      z[v + v + 1] = z[v];
      z[v + v + 2] = z[v];
    }
    z[v] = -1;
  }
}

void update(int ql, int qr, int val, int v = 0, int tl = 0, int tr = n - 1) {
  push(tl, tr, v);
  if (ql > tr || qr < tl) {
    return;
  }
  if (ql <= tl && tr <= qr) {
    z[v] = val;
    push(tl, tr, v);
  } else {
    int tm = (tl + tr) >> 1;
    update(ql, qr, val, v + v + 1, tl, tm);
    update(ql, qr, val, v + v + 2, tm + 1, tr);
    t[v] = t[v + v + 1] + t[v + v + 2];
  }
}

ll query(int ql, int qr, int v = 0, int tl = 0, int tr = n - 1) {
  push(tl, tr, v);
  if (ql > tr || qr < tl) {
    return 0ll;
  }
  if (ql <= tl && tr <= qr) {
    return t[v];
  }
  int tm = (tl + tr) >> 1;
  return query(ql, qr, v + v + 1, tl, tm) + query(ql, qr, v + v + 2, tm + 1, tr);
}

void solve() {
  cin >> n >> q;
  cin >> s >> f;
  vector<int> l(q), r(q);
  for(int i = 0; i < q; i++) {
    cin >> l[i] >> r[i];
    l[i]--, r[i]--;
  }
  build(0, 0, n - 1);
  bool ok = 1;
  for(int i = q - 1; i >= 0; i--) {
    int cnt_one = query(l[i], r[i]);
    int cnt_all = r[i] - l[i] + 1;
    int cnt_zero = cnt_all - cnt_one;
    if (cnt_one < (cnt_all + 1) / 2) {
      update(l[i], r[i], 0);
    } else
    if (cnt_zero < (cnt_all + 1) / 2) {
      update(l[i], r[i], 1);
    } else {
      ok = 0;
      break;
    }
  }
  if (ok) {
    for(int i = 0; i < n; i++) {
      if (query(i, i) != s[i] - '0') {
        ok = 0;
        break;
      }
    }
  }
  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
