#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define MX 1000000007

ll M, N;
vector<ll> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	while (N > 1) {
		for (ll i = 2; i <= N; i++) {
			if (N % i == 0) {
				v.push_back(i);
				N = N/i;
				break;
			}
		}
	}
	cout << "adadads";
	ll vl = v.size();
	for (ll i = 0; i < vl; i++) {
		cout << v[i] << " ";
	}
	return 0;
}

//sudo apt-get install g++-multilib
