#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
#define ll long long
int T;
int arr[10010];
int cp[10010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> T;
	while (T--) {
		memset(arr, 0, sizeof(arr));
		memset(cp, 0, sizeof(cp));
		int N, a, ans=0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + N);
		for (int i = 0; i < N; i += 2) {
			cp[i / 2] = arr[i];
			cp[N - i/2 - 1] = arr[i + 1];
		}
		if (N % 2 == 1) cp[N / 2] = arr[N - 1];
		for (int i = 0; i < N-1; i++) {
			//cout << ans << " " << cp[i] << "\n";
			ans = max(ans, abs(cp[i + 1] - cp[i]));
		}
		ans = max(ans, abs(cp[N - 1] - cp[0]));
		cout << ans << "\n";
	}
	return 0;
}