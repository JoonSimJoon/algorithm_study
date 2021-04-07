#include <iostream>
#include <vector>
using namespace std;
struct s {
	int cost, val;
};
s a;
vector<s> v;
int N, cp = -1;
int dp[30];
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a.cost >> a.val;
		v.push_back(a);
	}
	for (int i = 0; i < N+1; i++) {
		for (int j = 1; j <= 5; j++) {
			if (i - j < 0) break;
			else {
				if (v[i - j].cost <= j) {
					dp[i] = max(dp[i], dp[i - j] + v[i - j].val);
				}
				else {
					dp[i] = max(dp[i], dp[i - j]);
				}
			}
		}
	}
	cout << dp[N] << "\n";
	return 0;
}