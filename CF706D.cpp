#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define eb emplace_back
#define ll long long

struct trie_node {
  int cnt;
  int next[2];
  trie_node () {
    cnt = 0;
    for(int i = 0; i < 2; i++) next[i] = -1;
  }
};

const int N = 4e6 + 5;

trie_node trie[N];

int sz = 1;

void trie_add(int x) {
  int v = 0;
  for(int i = 30; i >= 0; i--) {
    int bit = ((x >> i) & 1) > 0;
    if (trie[v].next[bit] == -1) {
      trie[v].next[bit] = sz++;
    }
    v = trie[v].next[bit];
    trie[v].cnt += 1;
  }
}

void trie_del(int x) {
  int v = 0;
  for(int i = 30; i >= 0; i--) {
    int bit = ((x >> i) & 1) > 0;
    if (trie[v].next[bit] != -1) {
      v = trie[v].next[bit];
      trie[v].cnt -= 1;
    }
  }
}

int trie_xor(int x) {
  int v = 0;
  int res = 0;
  for(int i = 30; i >= 0; i--) {
    int bit = ((x >> i) & 1) > 0;
    if (trie[v].next[bit ^ 1] != -1 && trie[trie[v].next[bit ^ 1]].cnt) {
      res += (1 << i);
      v = trie[v].next[bit ^ 1];
    } else {
      v = trie[v].next[bit];
    }
  }
  return max(x, res);
}

void solve() {
  int Q;
  cin >> Q;
  int x;
  while(Q--) {
    char op;
    cin >> op >> x;
    if (op == '+') {
      trie_add(x);
    } else
    if (op == '-') {
      trie_del(x);
    } else {
      cout << trie_xor(x) << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
//  freopen("taskA.in", "r", stdin);
//  freopen("taskA.out", "w", stdout);
  int t = 1;
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
