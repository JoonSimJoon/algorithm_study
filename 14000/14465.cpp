#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, b;
	cin >> n >> k >> b;
	vector<int> a(n + 1, 1);
	while (b--) {
		int x;
		cin >> x;
		a[x] = 0;
	}
    	// 1의 개수를 세어주는 prefix sum 배열을 만들어 줍니다.
	for(int i =1; i<=n; ++i)
		a[i] += a[i - 1];
        
        // 길이가 K인 모든 구간을 확인하고 0의 개수가 최소인 것을 찾습니다.
	int ans = 1e9;
	for(int i =k; i<=n; ++i)
		ans = min(ans, k - (a[i] - a[i - k]));
	cout << ans;
}