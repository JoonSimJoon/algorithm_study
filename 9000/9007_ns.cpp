#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int T;
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> T;
	while (T--) {
		ll K, N, mem, flag = 0;
		ll arr[1010] = { 0, };
		cin >> K >> N;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < N; j++) {
				cin >> mem;
				arr[j] += mem;
			}
		}
		sort(arr, arr + N);
		for (int i = 1; i < N; i++){
			cout << arr[i] << "\n"; 
			if ((K - arr[i - 1]) * (K - arr[i - 1]) <= (K - arr[i]) * (K - arr[i])) {
				cout << arr[i-1] << "\n";
				flag = 1;
				break;
			}
		}
		if (flag == 0) cout << arr[N - 1] << "\n";
	}
	return 0;
}