#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
ll N, M;
struct s {
	ll cnt = 0;
	ll key = 0;
};
s arr[100010];
ll find(ll x) {
	if (arr[x].key == x) {
		return x;
	}
	else {
		return find(arr[x].key);
	}
}
void unit(ll x, ll y) {
	x = find(x);
	y = find(y);
	arr[y].key = x;
	arr[x].cnt += arr[y].cnt;
}

int main() {
	scanf("%lld %lld", &N, &M);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &arr[i].cnt);
		arr[i].key = i;
	}
	for (ll i = 0; i < M; i++) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		a--;
		b--;
		ll x = find(a);
		ll y = find(b);
		if (x != y) {
			unit(a, b);
		}
		printf("%lld \n", arr[x].cnt);
	}
	return 0;
}