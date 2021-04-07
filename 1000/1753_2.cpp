#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321

using namespace std;

int dp[20001];
int V, E, K;
int a, b, c;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E >> K;
	vector<vector< pair<int, int>>> v(E+10);
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 1; i <= V; i++) dp[i] = INF;
	dp[K] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,K });
	while (!pq.empty()) {
		int nd = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		for (auto x : v[nd]) {
			int next = x.first;
			int nextVal = val + x.second;
			if (dp[next] > nextVal) {
				dp[next] = nextVal;
				pq.push({ -nextVal, next });
			}
		}
	}
		for (int i = 1; i <= V; i++) {
			if (dp[i] == INF) cout << "INF\n";
			else cout << dp[i] << "\n";
		}

	return 0;
}