#include<bits/stdc++.h>
using namespace std;
const int N = 35003;
int a[N], cnt[N], dp[N], pd[N], val, L, R;
void add(int x) {
    cnt[x]++;
    if (cnt[x] == 1) val++;
}
void del(int x) {
    cnt[x]--;
    if (cnt[x] == 0) val--;
}
int calc(int l, int r) {
    while (L > l) add(a[--L]);
    while (L < l) del(a[L++]);
    while (R > r) del(a[R--]);
    while (R < r) add(a[++R]);
    return val;
}
void dnc(int i, int j, int l, int r) {
    if (i > j) return;
    int m = (i + j) / 2;
    pair<int, int> cur = {-1, -1};
    for (int k = l; k <= min(m, r); k++) {
        cur = max(cur, make_pair(pd[k - 1] + calc(k, m), k));
    }
    dp[m] = cur.first;
    dnc(i, m - 1, l, cur.second);
    dnc(m + 1, j, cur.second, r);
}
void solve(int tcase) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (!cnt[a[i]]) dp[i]++, cnt[a[i]] = 1;
    }
    L = -1, R = -1;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 2; i <= k; i++) {
        swap(pd, dp);
        dnc(1, n, 1, n);
    }
    cout << dp[n] << '\n';
    // for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
}
