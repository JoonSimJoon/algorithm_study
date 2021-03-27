#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int a;
vector<int> v;


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int ttt = 1; ttt <= T;ttt++) {
		v.clear();
		int N, ans = 0, k = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> a;
			v.push_back(a);
		}
		for (int i = 0; i < N-1; i++) {
			for (int j = 0; j < N; j++) {
				if (i + 1 == v[j]) {
					k = j;
					break;
				}
			}
			reverse(v.begin() + i, v.begin() + k + 1);
			//for (int kkk = 0; kkk < N; kkk++) cout << "* " << v[kkk];
			ans += k - i + 1;
			//cout << "\n";
		}
		cout << "Case #" << ttt << ": " << ans << "\n";
	}
	return 0;
}