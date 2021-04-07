#include <iostream>
#define ll long long
using namespace std;
ll N, M;
ll point1 = 0, point2 = 0, sum = 0, ans = 0;
ll arr[10010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> N >> M;
	for (ll i = 0; i < N; i++) {
		cin >> arr[i];
	}
	while (1) {
		if (sum >= M) {
			sum -= arr[point1++];
		}
		else if (point2 == N) {
			break;
		}
		else {
			sum += arr[point2++];
		}
		if (sum == M) ans++;
	}
	cout << ans << "\n";
	return 0;
}