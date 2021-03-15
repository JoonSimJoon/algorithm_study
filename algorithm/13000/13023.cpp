#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> v[2010];
int visited[2010];
int N, M, a, b, ans;

void f(int now, int result) {
	if (result == 4) {
		ans = 1; 
		return;
	}
	visited[now] = 1;
	int vl = v[now].size();
	for (int i = 0; i < vl; i++) {
		if (visited[v[now][i]] == 0) {
			f(v[now][i], result + 1);
		}
		if (ans == 1) return;
	}
	visited[now] = 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		memset(visited, 0, sizeof(visited));
		f(i, 0);
		if (ans==1) break;
	}
	cout << ans << "\n";
	return 0;
}