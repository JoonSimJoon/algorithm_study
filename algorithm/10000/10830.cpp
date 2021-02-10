#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
ll dp[10][10];
ll arr[10][10];
ll N, B;
int main() {
	ios::sync_with_stdio();
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> B;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			cin >> dp[i][j];
			arr[i][j] = dp[i][j];
		}
	}
	B--; //덮어쓰기에서 한번했음
	while (B--) {
		for (ll i = 0; i < N; i++) {
			for (ll k = 0; k < N; k++) { //dp[i][k] 구하기 dp[i][k]=dp[i]행
				ll cnt = 0;
				for (ll j = 0; j < N; j++) {
					cnt += dp[i][j] * arr[j][k];
				}
			}
		}
		
	}
}