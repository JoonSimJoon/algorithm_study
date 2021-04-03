#include <cstdio>
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
int n, m;
int par[11111];

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
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        gph.push_back({ u, v, w });
    }

    sort(gph.begin(), gph.end());
    for (int i = 1; i <= n; i++) par[i] = i;

    int dap = 0;
    for (edg now : gph) {
        now.u = find(now.u); now.v = find(now.v);
        if (now.u == now.v) continue;
        merge(now.u, now.v);
        dap += now.w;
    }

    printf("%d\n", dap);

    return 0;
}