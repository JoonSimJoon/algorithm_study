#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int arr[11];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll A, B, C;
	cin >> A >> B >> C;
	ll ans = A * B * C;
	while (ans > 0) {
		arr[ans % 10]++;
		ans /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}	