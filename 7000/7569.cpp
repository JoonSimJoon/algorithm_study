#include <cstdio>
#include <queue>
using namespace std;

struct tomato {
    int x, y, z;
};

int m, n, h, ans;
int a[101][101][101];
const int dx[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dz[] = {0, 0, 0, 0, -1, 1};
queue<tomato> q;

void bfs() {
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, z = q.front().z;
        q.pop();
        for (int i=0; i<6; i++) {
            int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
            if (a[nx][ny][nz]) continue;    // Ripened(1 or above), empty(-1)
            a[nx][ny][nz] = a[x][y][z] + 1; // Day count
            q.push({nx, ny, nz});
        }
    }
}

int main() {
    scanf("%d %d %d", &m, &n, &h);
    for (int i=0; i<h; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) {
                scanf("%d", &a[i][j][k]);
                if (a[i][j][k] == 1) {
                    // Ripened(1), Not ripened(0), Empty(-1)
                    // Push {i,j,k} to queue, if 1.
                    q.push({i, j, k});
                }
            }
        }
    }
    bfs();
    for (int i=0; i<h; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) {
                // Not all tomato ripened.
                if (a[i][j][k] == 0) {
                    printf("-1\n");
                    return 0;
                }
                // Max value is answer.
                if (ans < a[i][j][k]) ans = a[i][j][k];
            }
        }
    }
    printf("%d\n", ans-1);
    return 0;
}

