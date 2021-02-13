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
	// ��Ʈ ���� �θ� ��� ��ȣ�� �ڱ� �ڽ��� ������.
	if (arr[x].key == x) {
		return x;
	}
	else {
		// �� ����� �θ� ��带 ã�� �ö󰣴�.
		return find(arr[x].key);
	}
}
void unit(ll x, ll y) {
	x = find(x);
	y = find(y);
	ll tmp = arr[x].cnt + arr[y].cnt;
	arr[y].key = x;
	arr[x].cnt = tmp;
	arr[y].cnt = tmp;
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
		unit(a, b);
		printf("%lld %lld\n", arr[a].cnt, arr[b].cnt);
	}
	return 0;
}