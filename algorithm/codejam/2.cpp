#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define ll long long

ll T, a, b, ans, sl, mx;
string s;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> T;
	for (int ttt = 1; ttt <= T; ttt++) {
		s.clear();
		ans = 0;
		cin >> a >> b;
		cin >> s;
		mx = max(a, b);
		sl = s.size();
		char before = 'X';
		for (ll i = 0; i < sl; i++) {
			if (s[i] == 'C') {
				if (before == 'J') ans += b;
				before = 'C';
			}
			else if (s[i] == 'J') {
				if (before == 'C') ans += a;
				before = 'J';
			}
		}
		
		cout << "Case #" << ttt << ": " << ans << "\n";
	}
	return 0;
}