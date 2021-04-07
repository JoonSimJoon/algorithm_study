#include <iostream>
using namespace std;
#define ll long long
ll N, M;
ll arr[1050][1050];
ll dp[1050][1050];
ll ax, ay, bx, by;


int N, M;
int arr[1050][1050];
int dp[1050][1050];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			cin >> arr[i][j];
			dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	/*for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (ll i = 0; i < M; i++) {
		cin >> ax >> ay >> bx >> by;
		ll ans = dp[bx][by] - dp[ax-1][by] - dp[bx][ay-1] + dp[ax-1][ay-1];
		
		cout << ans << "\n";

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";

	}
	return 0;
}