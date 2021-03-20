#include <iostream>
#include <vector>
using namespace std;
int N, K, a, b;
vector<int>  v;

int dp[210][210];


int f(int l, int r) {
	if (l >= r)return 0;
	int& ret = dp[l][r];
	if (ret) return ret;
	ret = 1e9;
	for (int i = l; i < r; i++) {
		int p = v[l] == v[i + 1] ? 0 : 1;
		ret = min(ret, f(l, i) + f(i + 1, r) + p);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (i != 0) {
			if (b != a) v.push_back(b);
		}
		b = a;
	}
	v.push_back(a);
	int vl = v.size();
	cout << f(0, vl - 1) << " ";
	return 0;
}