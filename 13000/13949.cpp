#include <iostream>
#include <stdio.h>
using namespace std;
#define ll long long
struct tn {
	ll a, b, c;
};
ll K, N;
tn ans,tmp;
int main() {
	cin >> K >> N;
	for (ll i = 1; i <= 100; i++) {
		for (ll j = 1; j <= 100; j++) {
			if (i == j) continue;
			for (ll k = 1; k <= 100; k++) {
				if (j == k || k == i) continue;
				if (i * i + j * j + k * k == K * (i * j + j * k + k * i) + 1) {
					ans.a = i;
					ans.b = j;
					ans.c = k;
					cout << ans.a << " " << ans.b << " " << ans.c << "\n";
					break;
				}
			}
			//if (ans.a != 0) break;
		}
		//if (ans.a != 0) break;
	}
	N--;
	while (N--) {
		tmp.a = ans.b * K + ans.a * K - ans.c;
		tmp.b = ans.a;
		tmp.c = ans.b;
		if(tmp.a>tmp.b && tmp.a>tmp.c)
		ans.a = tmp.a;
		ans.b = tmp.b; 
		ans.c = tmp.c;
	}

	return 0;
}

//(a,b,c) 성립이면 (kb+kc-a,b,c) 성립. 근데 100자리 넘어가서 파이썬이나 빅int 구현해야하는데 싫음 ㅋ.ㅋ