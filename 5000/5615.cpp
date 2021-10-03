#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ull unsigned long long

ull power(ull x, ull y, ull mod) {
	ull temp = 1;
	x %= mod;
	while (y) {
		if (y & 1) temp = (temp * x) % mod;
		y /= 2;
		x = (x * x) % mod;
	}
	return temp;
}

bool miller(ull n, ull a) {
	//n <= 2인 경우 따로 처리.
	if (n <= 1) return false;
	if (n == 2) return true;

	//a % n == 0인 경우는 페르마의 소정리를 사용할 수 없으므로 따로 처리.
	if (n == a) return true;

	//a % n != 0인 경우.
	ull k = n - 1;
	while (1) {
		ull temp = power(a, k, n);
		if (temp == n - 1) return true;
		if (k & 1) return temp == 1 || temp == n - 1;
		k /= 2;
	}
}

bool isprime(ull n) {
	vector<ull> base = { 2, 7, 61 };
	for (auto a : base) {
		if (!miller(n, a)) return false;
	}
	return true;
}

int main() {
	fastio;
	int N, cnt = 0; cin >> N;
	for (int i = 0; i < N; i++) {
		ull n; cin >> n;
		n = 2 * n + 1;
		if (isprime(n)) cnt++;
	}
	cout << cnt << '\n';
}