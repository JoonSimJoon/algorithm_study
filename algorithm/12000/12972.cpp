#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, a;
vector<int> v,ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		cin >> a;
		v.push_back(a);
	}
	if (N == 1) {
		cout << v[0] << "\n";
	}
	else {
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int cp = v[0];
		int cnt = 1;
		for (int i = 1; i < N * N; i++) {
			if (v[i] == cp) cnt++;
			else {
				if (cnt % 2 == 1) {
					ans.push_back(cp);
					if (ans.size() == N) break;
				}
				cp = v[i];
				cnt = 1;
			}
		}
		for (int i = 0; i < N; i++) cout << ans[i] << " ";
	}
	return 0;
}