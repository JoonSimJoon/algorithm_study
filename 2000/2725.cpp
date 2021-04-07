#include <iostream>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
ll T, N, cnt;
ll dp[1010] = { 0,3, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> T;
	for (int i = 2; i <= 1000; i++) {
		cnt = 0;
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) == 1) cnt += 1;
		}
		dp[i] = dp[i - 1] + 2 * cnt;
	//	cout << dp[i] << " " << cnt << "\n";
	}
	while (T--) {
		cin >> N;
		cout << dp[N] << "\n";
	}
	return 0;
}