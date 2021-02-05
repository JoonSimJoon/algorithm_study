#include <stdio.h>
#include <iostream>
#define ll long long
using namespace std;
ll cnt[12];
ll tb[12][12];
int main() {
	ll T;
	for (ll i = 1; i < 10; i++) {
		tb[i][0] = i;
		for (ll j = 1; j < 10; j++) {
			tb[i][j] = tb[i][j - 1] * i;
			tb[i][j] %= 10;
			if (tb[i][j] == i) {
				cnt[i] = j;
				break;
			}
		}
		//cout << cnt[i] << "\n";
	}
	scanf("%lld", &T);
	//cin >> T;
	while (T--) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		//cin >> a >> b;
		a = a % 10;
		if (a == 0) {
			printf("10\n");
		}
		else if (cnt[a] <= 1) {
			printf("%lld\n", a);
			//cout << a << "\n";
		}
		else {
			b = b % cnt[a];
			if (b == 0) b = cnt[a];
			printf("%lld\n", tb[a][b - 1]);
			//cout << tb[a][b-1] << "\n";
		}

	}
	return 0;
}