#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define MX 1000000007
vector<pll > v;

ll cp(pll x, pll y) {
	return x.second > y.second;
}

ll f(ll kar) {
	if (kar == 1) return 2;
	else if (kar == 0) return 1;
	else {
		if (kar % 2 == 0) {
			ll k2 = f(kar / 2) % MX;
			return (k2 * k2) % MX;
		}
		else {
			ll k2 = f(kar / 2) % MX;
			return (2 * k2 * k2) % MX;
		}
	}
}
ll N, ans, s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (ll i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), cp);
	for (int i = 0; i < N; i++) {
		s =  ((v[i].first * v[i].second) % MX) * f(v[i].second - 1) % MX;
		ans = (ans + s) % MX;
		//cout << v[i].first<<" "<< v[i].second<<" "<< s << "\n";
	}
	cout << ans << "\n";
	return 0;
}