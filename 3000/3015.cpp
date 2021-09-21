#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define pii pair <int,int>
#define fs first
#define sd second
#define ep emplace
#define ll long long
using namespace std;

int main() {
	FIO;
	int n; cin >> n;
	stack <pii> s;
	ll ans = 0;
	FOR(i, 1, n) {
		int x; cin >> x;
		while (s.size() && s.top().fs < x) {
			ans += s.top().sd;
			s.pop();
		}
		int val = 1;
		if (s.size() && s.top().fs == x) {
			val += s.top().sd; 
			ans += s.top().sd; 
			s.pop();
		}
		if(s.size()) ans++;
		s.ep(x, val);
	}
	cout << ans << '\n';
	return 0;
}