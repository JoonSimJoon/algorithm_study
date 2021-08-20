#include <cstdio>

int n, m, k, ans;
int a[100][100];
bool check[100][100];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int dfs(int x, int y) {
    int ret = 1;
    check[x][y] = true;
    for (int i=0; i<4; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (!check[nx][ny] && a[nx][ny]) ret += dfs(nx, ny);
    }
    return ret;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    while (k--) {
        int r, c;
        scanf("%d %d", &r, &c);
        a[r-1][c-1] = 1;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!check[i][j] && a[i][j]) {
                int k = dfs(i, j);
                if (ans < k) ans = k;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
