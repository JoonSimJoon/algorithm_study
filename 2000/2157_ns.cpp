#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N, M, K;
int arr[315][315];
int dp[315];
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}
	return 0;
}