#include <iostream>
#define ll long long 
using namespace std;
ll T;
ll combination(ll N, ll M) {
	ll A = 1, B = 1;
	if (M * 2 > N) {
		M = N - M;
	}
	for (ll i = N; i > N - M; i--) {
		A *= i;
	}
	for (ll i = 1; i <= M; i++) {
		B *= i;
	}
	return (ll)(A / B);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> T;
	while (T--) {
		ll N, M;
		cin >> N >> M;
		cout << combination(M, N) << "\n";
	}
	return 0;
}