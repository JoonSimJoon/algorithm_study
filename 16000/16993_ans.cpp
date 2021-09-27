#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e15;

int n, q;
ll a[222222], cum[222222];
struct abc { ll mmax, lmax, rmax; } tree[333333];

void init(int now, int s, int e) {
    if (s == e) {
        tree[now] = { a[s],a[s],a[s] };
        return;
    }
    ll lsum = 0, rsum = 0, m = (s+e)/2;
    auto &lt = tree[now*2], &rt = tree[now*2+1], &nt = tree[now];
    nt = { -inf,-inf,-inf };
    for (int i = e; i >= s; i--) {
        lsum += a[i];
        nt.lmax = max(nt.lmax, lsum);
    }
    for (int i = s; i <= e; i++) {
        rsum += a[i];
        nt.rmax = max(nt.rmax, rsum);
    }
    init(now*2, s, m); init(now*2+1, m+1, e);
    nt.mmax = max({ lt.mmax, rt.mmax, lt.lmax+rt.rmax });
}

abc query(int now, int s, int e, int x, int y) {
    if (e < x || y < s) return { -inf,-inf,-inf };
    if (x <= s && e <= y) return tree[now];
    
    int m = (s+e)/2;
    abc r1 = query(now*2, s, m, x, y), r2 = query(now*2+1, m+1, e, x, y), ret;
    ret.lmax = max(r1.lmax+cum[e]-cum[m], r2.lmax);
    ret.rmax = max(r1.rmax, cum[m]-cum[s-1]+r2.rmax);
    ret.mmax = max({ r1.mmax, r2.mmax, r1.lmax+r2.rmax });

    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        cum[i] = cum[i-1]+a[i];
    }
    init(1, 1, n);
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", query(1, 1, n, l, r).mmax);
    }

    return 0;
}