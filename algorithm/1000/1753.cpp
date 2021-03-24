#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321

using namespace std;

int dp[20001];

int main() {
	int V, E;
	cin >> V >> E;
	int K;
	cin >> K;
	vector<vector<pair<int, int>>> v(V + 1);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 1; i <= V; i++) dp[i] = INF;
	dp[K] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,K });
	while (!pq.empty()) {
		int node = pq.top().second;
		int val = -pq.top().first;
		pq.pop();
		for (auto x : v[node]) {
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