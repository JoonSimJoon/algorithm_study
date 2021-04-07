#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
ll m, n, k;
ll arr[4000010];
ll sum[4000010];
ll init(ll now,ll le,ll ri) {
	if (le == ri) {
		return sum[now] = arr[le];
	}
	return sum[now] = init(now * 2, le, (le + ri) / 2) + init(now * 2 + 1, (le + ri) / 2 + 1, ri);
}
void update(ll now, ll idx, ll le, ll ri, ll dif) {
	if (idx<le || idx>ri) return;
	sum[now] += dif;
	if (le != ri) {
		update(now * 2, idx, le, (le + ri) / 2, dif);
		update(now * 2 + 1, idx, (le + ri) / 2 + 1, ri, dif);
	}
}
ll ans(ll now, ll st, ll en, ll le, ll ri) {
	if (ri < st || en < le) return 0;
	if (st <= le && ri <= en) return sum[now];
	return ans(now * 2, st, en, le, (le + ri) / 2) + ans(now * 2 + 1, st, en, (le + ri) / 2 + 1, ri);
}
int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(0);
	scanf("%lld %lld %lld", &n, &m, &k);
	//cin >> n >> m >> k;
	for (ll i = 1; i <= n; i++) scanf("%lld",&arr[i]);

	init(1, 1, n);

	for (ll i = 0; i < m + k; i++) {
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		//cin >> a >> b >> c;
		if (a == 1) update(1, b, 1, n, c - arr[b]), arr[b] = c;
		else {
			ll res = ans(1, b, c, 1, n);
			printf("%lld\n", res);
		}
	}
	return 0;
}