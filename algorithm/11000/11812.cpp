#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
ll N, K, Q, a, b, cnt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K >> Q;
	while (Q--) {
		cnt = 0;
		cin >> a >> b;
		if (K == 1) {
			cout << abs(a - b) << "\n";
			continue;
		}
		while (a != b) {
			if (a > b) {
				a = (a - 2) / K + 1;
			}
			else b = (b - 2) / K + 1;
			cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}