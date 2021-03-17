#include <iostream>
#include <math.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

ll x, y, cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> x >> y;
	ll Gcd = gcd(x, y);
	cnt = x + y - Gcd;
	cout << cnt;
	return 0;
}