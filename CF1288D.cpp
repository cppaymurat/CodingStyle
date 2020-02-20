#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = (int)3e5 + 123;

int a[MAXN][10];
int n, m, x, y;

bool check(int k) {
    vector <int> cnt((1 << m) + 1);

    for(int i = 0; i < (1 << m); i++) {
        cnt[i] = 0;
    }

    for(int i = 1; i <= n; i++) {
        int h = 0;
        for(int j = 0; j < m; j++) {
            if (a[i][j] >= k) {
                h += (1 << j);
            }
        }
        cnt[h] = i;
    }

    for(int i = 0; i < (1 << m); i++) {
        for(int j = 0; j < (1 << m); j++) {
            if (cnt[i] && cnt[j] && (i | j) == (1 << m) - 1) {
                x = cnt[i];
                y = cnt[j];
                return 1;
            }
        }
    }

    return 0;
}

void solve() {

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int l = 0, r = 1e9;
    while(r - l > 1) {
        int k = (l + r) >> 1;
        if (check(k)) {
            l = k;
        } else {
            r = k;
        }
    }

    check(l + 1);

    x = max(x, 1);
    y = max(y, 1);

    cout << x << ' ' << y << endl;
}

int main() {
    solve();
    return 0;
}
