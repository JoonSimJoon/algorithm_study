#include <string.h>
#include <iostream>
using namespace std;
const int MOD = 100999;

int dp[2001][2001];

int cnt(int n, int m) {
	if (dp[n][m] != -1) return dp[n][m];
	if (n < m) return dp[n][m] = 0;
	if (n == m) return dp[n][m] = 1;
	if (n == 0) return dp[n][m] = 1;
	return dp[n][m] = (cnt(n - m, m + 1) + cnt(n, m + 1)) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int T;
	cin >> T;
	memset(dp, -1, sizeof(dp));
	while(T--) {
		int N;
		cin >> N;
		cout << cnt(N, 1) << "\n";
	}
}