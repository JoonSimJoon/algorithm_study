#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string.h>
#include <queue>
using namespace std;
typedef pair<double,pair<int, int> > P;


int n,p[101],cnt;
double res;
bool visit[101];
vector<pair<double,double> > adj;
priority_queue<P, vector<P>, greater<P> > pq;

int find(int x) {
	if (p[x] < 0) return x;

	return p[x] = find(p[x]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;

	p[a] = b;
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	memset(p, -1, sizeof(p));
	for (int i = 0; i < n; i++) {
		double q, w;
		cin >> q >> w;
		adj.push_back({ q,w });
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			pq.push({ sqrt(pow(adj[i].first - adj[j].first,2)+pow(adj[i].second - adj[j].second,2)),{i,j} });
		}
	}
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		double c = pq.top().first;
		pq.pop();

		if (merge(x, y)) {
			res += c;
			cnt++;
			if (cnt == n - 1) break;
		}
	}
	cout << fixed << setprecision(2) << res << '\n';
}
