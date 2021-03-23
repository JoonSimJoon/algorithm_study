#include <iostream>
#include <vector>
using namespace std;
#define ll long long
vector<ll> v;
ll N, Q, a, b, sum, tmp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> Q;
	v.push_back(0);
	for (ll i = 0; i < N; i++) {
		cin >> tmp;
		sum += tmp;
		v.push_back(sum);
	}
	for (ll i = 0; i < Q; i++) {
		cin >> a >> b;
		a--;
		cout << v[b] - v[a] << "\n";
	}
	return 0;
}