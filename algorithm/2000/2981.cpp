#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define MAX_SIZE 1e9

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

ll N, a, Gcd;
vector <ll> v, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	Gcd = v[1] - v[0];
	for (int i = 0; i < N-1; i++) {
		Gcd = gcd(Gcd, v[i + 1] - v[i]);
	}
	for (int i = 2; i*i <= Gcd; i++) {
		if (i * i == Gcd) ans.push_back(i);
		else if (Gcd % i == 0) {
			ans.push_back(i);
			ans.push_back(Gcd / i);
		}
	}
	sort(ans.begin(), ans.end());
	ans.push_back(Gcd);
	ll sl = ans.size();
	for (int i = 0; i < sl; i++) cout << ans[i] << " ";
	return 0;
}