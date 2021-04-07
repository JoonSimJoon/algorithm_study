#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

int d[501];
int visited[501];
vector<int> a[501];
int N, M;

int dfs(int x) {
    int vl = a[x].size();
    for (int i = 0; i < vl; i++) {
        int y = a[x][i];
        if (visited[y]) continue;
        visited[y] = 1;
        if (d[y] == 0 || dfs(d[y])) {
            d[y] = x;
            return 1;
        }
    }
    return 0;
}

int main()
{
    cin >> N >> M;

    int x, y;
    for (int i = 1; i <= M; i++) {
        cin >> x >> y;
        a[x].push_back(y);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) ans++;

    }
    cout << ans;
    return 0;
}

