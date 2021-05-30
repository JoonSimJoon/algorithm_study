#include <iostream>
using namespace std;
long long int cache[100][100];
long long int arr[100][100];
long long int dp(int y, int x, int n) {
	if (y == n - 1 && x == n - 1)
		return 1;
	if (!(x < n && y < n) || arr[y][x] == 0)
		return 0;
	auto & ref = cache[y][x];
	if (ref)
		return ref;
	ref = dp(y + arr[y][x], x, n) + dp(y, x + arr[y][x], n);
	return ref;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cout << dp(0, 0, n);
	return 0;
}


