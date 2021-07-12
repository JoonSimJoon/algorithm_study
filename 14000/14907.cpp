#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
int d[30],cost[30],ind[30],ans;
vector<int> Graph[30];
int main() {

	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		char a; int b,to; string c;
		ss >> a >> b;
		to = a - 'A';
		cost[to] = b;
		if (ss >> c) for (int i = 0; i < c[i]; i++) {
			Graph[c[i] - 'A'].push_back(to);
			ind[to]++;
		}
	}
	queue<int> q;
	for (int i = 0; i < 26; i++) {
		if (ind[i] == 0) {
			q.push(i);
			d[i] = cost[i];
		}
	}
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < Graph[here].size(); i++) {
			int next = Graph[here][i];
			d[next] = max(d[next], d[here] + cost[next]);
			ind[next]--;
			if (ind[next] == 0) q.push(next);
		}
		ans = max(ans, d[here]);
	}
	printf("%d\n", ans);
}
