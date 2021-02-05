#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;
typedef pair<Pair, Pair> PPair;

vector<vector<int>> seg;
ll h = 1;
ll arr[4025][4025];

void update(ll x1, ll y1, ll d) {
	ll i = y1 + h - 1, j = x1 + h - 1;
	seg[i][j] = d;
	while (j > 1) {
		j /= 2;
		seg[i][j] = seg[i][j * 2] + seg[i][j * 2 + 1];
	}
	while (i > 1) {
		j = x1 + h - 1;
		i /= 2;
		seg[i][j] = seg[i * 2][j] + seg[i * 2 + 1][j];
		while (j > 1) {
			j /= 2;
			seg[i][j] = seg[i][j * 2] + seg[i][j * 2 + 1];
		}
	}
	return;
}

ll xquery(ll y, ll nodeL, ll nodeR, ll nodeNum, ll l, ll r) {
	if (nodeL <= l && r <= nodeR) return seg[y][nodeNum];
	else if (nodeR < l || r < nodeL) return 0;
	ll mid = (l + r) / 2;
	return xquery(y, nodeL, nodeR, nodeNum * 2, l, mid) + xquery(y, nodeL, nodeR, nodeNum * 2 + 1, mid + 1, r);
}
ll yquery(ll nodeL, ll nodeR, ll nodeNum, ll l, ll r, ll x1, ll x2) {
	if (nodeL <= l && r <= nodeR) return xquery(nodeNum, x1, x2, 1, 1, h);
	else if (nodeR < l || r < nodeL) return 0;
	ll mid = (l + r) / 2;
	return yquery(nodeL, nodeR, nodeNum * 2, l, mid, x1, x2) + yquery(nodeL, nodeR, nodeNum * 2 + 1, mid + 1, r, x1, x2);
}

int main() {
	ll n, m, val;
	scanf("%lld %lld", &n, &m);
	while (h < n) h <<= 1;
	seg.resize(h * 2);
	for (ll i = 0; i < h * 2; i++) seg[i].resize(h * 2);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			scanf("%lld", &val);
			arr[i][j] = val;
			update(j + 1, i + 1, val);
		}
	}

	for (ll i = 0; i < m; i++) {
		ll w, x1, x2, y1, y2;
		scanf("%lld", &w);
		if (w == 0) {
			ll c;
			scanf("%lld %lld %lld", &y1, &x1, &c);
			//c = arr[y1][x1];
			arr[y1][x1] = c;
			update(x1, y1, c);
			/*for (int k = 1; k <= n; k++) {
				for (int j = 1; j <= n; j++) {
					printf("%3d", arr[j][k]);
				}
				printf("\n");
			}*/
		}
		else {
			scanf("%lld %lld %lld %lld", &y1, &x1, &y2, &x2);
			printf("%lld\n", yquery(y1, y2, 1, 1, h, x1, x2));
		}
	}
	return 0;
}

