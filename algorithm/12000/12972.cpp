#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
struct s {
	int val, key;
};
s a;
int cp(s x, s y) {
	return x.val > y.val;
}
vector<s> v;
vector<int> ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		cin >> a.val;
		a.key = 0;
		v.push_back(a);
	}
	if (N == 1) {
		cout << v[0].val << "\n";
	}
	else {
		sort(v.begin(), v.end(),cp);
		//reverse(v.begin(), v.end());
		int cp = v[0].val;
		v[0].key = 1;
		int cnt = 1;
		for (int i = 1; i < N * N; i++) {
			if (v[i].val == cp) cnt++;
			else {
				if (cnt % 2 == 1) {
					ans.push_back(cp);
					if (ans.size() == N) break;
				}
				cp = v[i].val;
				v[i].key = 1;
				cnt = 1;
			}
		}
		for (int i = 0; i < N * N; i++) {
			if (ans.empty()!=0 && ans.size() == N)break;
			if (v[i].key==0) ans.push_back(v[i].val);
		}
		for (int i = 0; i < N; i++) cout << ans[i] << " ";
	}
	return 0;
}