#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edg {
    int u, v, w;
    bool operator <(edg a)const {
        return w < a.w;
    }
};
vector<edg> gph;
int n, m, mx = -1;
int par[111110];

int find(int u) {
    if (u == par[u]) return u;
    return par[u] = find(par[u]);
}

void merge(int u, int v) {
    u = find(u); v = find(v);
    if (u > v) swap(u, v);
    par[u] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        gph.push_back({ u, v, w });
    }

    sort(gph.begin(), gph.end());
    for (int i = 1; i <= n; i++) par[i] = i;

    int ans = 0;
    for (edg now : gph) {
        now.u = find(now.u); 
        now.v = find(now.v);
        if (now.u == now.v) continue;
        merge(now.u, now.v);
        ans += now.w;
        if (mx < now.w)mx = now.w;
    }
    cout << ans-mx << "\n";
    return 0;
}