#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

using ll = long long;
using p = pair<int, string>;
constexpr ll INF = 1e9 + 1;

p parse_1(string& s) {
	int idx = s.find(' ');
	return { stoi(s.substr(idx + 1, s.size())), s.substr(0, idx) };
}

pair<string, vector<p>> parse_2(string s) {
	int idx = s.find('=');
	string name = s.substr(0, idx);
	string t = s.substr(idx + 1, s.size());
	for (auto& i : t) if (i == '+') i = ' ';
	stringstream in(t); vector<p> v;
	while (in >> t) v.push_back({ t[0] & 15, t.substr(1, t.size()) });
	return { name, v };
}

int main() {
	fastio;
	//input
	int n, m; cin >> n >> m; cin.ignore();
	vector<string> _v(n), _w(m), I;
	for (int i = 0; i < n; i++) getline(cin, _v[i]);
	for (int i = 0; i < m; i++) cin >> _w[i];

	//parsing + indexing
	vector<p> v(n);
	vector<pair<string, vector<p>>> w(m);
	for (int i = 0; i < n; i++) {
		v[i] = parse_1(_v[i]);
		I.push_back(v[i].second);
	}
	for (int i = 0; i < m; i++) {
		auto [name, v] = w[i] = parse_2(_w[i]);
		I.push_back(name);
		for (auto& [cnt, s] : v) I.push_back(s);
	}
	sort(I.begin(), I.end()); I.erase(unique(I.begin(), I.end()), I.end());
	auto IDX = [&](string s) { return lower_bound(I.begin(), I.end(), s) - I.begin(); };

	//sol
	vector<ll> cost(I.size(), -1);
	for (auto& [t, s] : v) cost[IDX(s)] = t;
	while (1) {
		bool flag = 0;
		for (auto& [name, v] : w) {
			ll cur = 0;
			for (auto& [cnt, s] : v) {
				ll t = cost[IDX(s)];
				if (t == -1) { cur = -1; break; }
				cur += cnt * t;
				if (cur >= INF) cur = INF;
			}
			if (cur == -1) continue;
			if (cost[IDX(name)] != -1 && cost[IDX(name)] <= cur) continue;
			cost[IDX(name)] = cur; flag = 1;
		}
		if (!flag) break;
	}
	if (!binary_search(I.begin(), I.end(), "LOVE")) cout << -1 << '\n';
	else cout << cost[IDX("LOVE")] << '\n';
}