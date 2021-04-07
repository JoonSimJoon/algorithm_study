#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N = 5e3, MAX_L = 2e4;
struct st {
    int x, d, u, t;
    bool operator<(st i) const {
        return x < i.x || x == i.x&&t > i.t;
    }
}l[MAX_N * 2];
int n, res, p[MAX_N][4], t[MAX_L * 4], cnt[MAX_L * 4];
void query(int h, int l, int r, int gl, int gr, int k) {
    if (r<gl || gr<l) return;
    if (gl <= l && r <= gr) cnt[h] += k;
    else query(h * 2 + 1, l, (l + r) / 2, gl, gr, k),
        query(h * 2 + 2, (l + r) / 2 + 1, r, gl, gr, k);
    if (cnt[h]) t[h] = r - l + 1;
    else t[h] = l == r ? 0 : t[h * 2 + 1] + t[h * 2 + 2];
}
void sw() {
    for (int i = 0; i < n; i++) {
        l[i] = { p[i][0],p[i][1],p[i][3],1 };
        l[i + n] = { p[i][2],p[i][1],p[i][3],-1 };
    }
    sort(l, l + 2 * n);
    for (int i = 0, tmp = 0; i < 2 * n; i++) {
        query(0, 0, MAX_L - 1, l[i].d, l[i].u - 1, l[i].t);
        res += abs(t[0] - tmp);
        tmp = t[0];
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) scanf("%d", &p[i][j]), p[i][j] += 1e4;
        if (p[i][0]>p[i][2]) swap(p[i][0], p[i][2]);
        if (p[i][1]>p[i][3]) swap(p[i][1], p[i][3]);
    }
    sw();
    for (int i = 0; i < n; i++) swap(p[i][0], p[i][1]), swap(p[i][2], p[i][3]);
    sw();
    printf("%d", res);
    return 0;
}
