#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
vector<int> v[140];
int N, M,ans;
int visited[140];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int nl = v[now].size();
		for (int i = 0; i < nl; i++) {
			if (visited[v[now][i]] != 1) {
				ans++;
				q.push(v[now][i]);
				visited[v[now][i]] = 1;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}