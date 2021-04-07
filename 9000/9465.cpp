#include <iostream>
#include <string.h>
using namespace std;
int T,N;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int dp[100010][2];
int arr[100010][2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i][0];
		}
		for (int i = 0; i < N; i++) {
			cin >> arr[i][1];
		}	
		dp[1][0] = arr[0][0];
		dp[1][1] = arr[0][1];
		for (int i = 2; i <= N; i++) {
			dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + arr[i-1][0];
			dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + arr[i-1][1];
		}
		int ans = max(dp[N][0], dp[N][1]);
		cout << ans << "\n";
	}
	return 0;
}