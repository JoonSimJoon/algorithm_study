#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

vector<pair<int, int>> node[10002];

int N;
int visited[10002];
int ans = 0, start = 0; 

void dfs(int point, int length) {
    if (visited[point]) return;
    visited[point] = 1;
    if (ans < length) {
        ans = length;
        start = point;
    }
    for (int i = 0; i < node[point].size(); i++) {
        dfs(node[point][i].first, length + node[point][i].second);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin >> N;
    int parent, child, length;
    for (int i = 0; i < N - 1; i++) {
        cin >> parent >> child >> length;
        node[parent].push_back({ child, length });
        node[child].push_back({ parent, length });
    }
    dfs(1, 0);
    ans = 0;
    memset(visited, 0, sizeof(visited));
    dfs(start, 0);
    cout << ans << endl;
    return 0;
}
