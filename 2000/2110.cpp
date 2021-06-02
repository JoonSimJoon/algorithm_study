#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


typedef long long int ll;
ll arr[200005];
ll n, c;

ll binarysearch(ll l, ll r) {
	ll L = l;
	ll R = r;
	ll ans = 0;
	while (L <= R) {

		ll mid = (L + R) / 2;
		ll cc = 1;
		ll wifi = arr[0];

		for (int i = 1; i < n; i++) {
			if (arr[i] - wifi >= mid) {
				cc++; 
				wifi = arr[i]; 
			}
		}

		if (cc < c) { 
			R = mid - 1;
		}
		else {
			if (mid > ans)ans =mid;
			L = mid + 1;
		}
	}

	return ans;
}
int main() {

	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++)scanf("%lld", &arr[i]);

	sort(arr, arr + n);
	ll Max = arr[n - 1] - arr[0];
	ll ans = binarysearch(0, Max);

	printf("%lld\n", ans);
}

