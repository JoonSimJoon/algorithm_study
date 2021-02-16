#include <stdio.h>
#include <iostream>
using namespace std;
#define ll long long
ll L, P, V, ans, tc;
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	while (1) {
		tc++;
		ll T;
		ans = 0;
		cin >> L >> P >> V;
		if (L == 0) break;
		else {
			T = V / P;
			ans += T * L;
			ans += min(V % P, L);
			cout << "Case " << tc << ": " << ans << "\n";
		}
	}
	return 0;
}