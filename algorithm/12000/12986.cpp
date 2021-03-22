#include <iostream>
#include <vector>
using namespace std;

struct s {
	int key, val;
};
vector<int> v;
s segtree[200010];
int N, Q, a, b;
s emptyx = { 123456, -1 };
s init(int l, int r, int n) {
	if (l == r) {
		segtree[n].key = v[l];
		segtree[n].val = 1;
		return segtree[n];
	}
	else {
		int mid = (l + r) / 2;
		s ax = init(l, mid, n * 2);
		s bx = init(mid + 1, r, n * 2 + 1);
		if (ax.key == bx.key) {
			segtree[n].key = ax.key;
			segtree[n].val = ax.val + bx.val;
			return segtree[n];
		}
		else {
			if (ax.val > bx.val) {
				segtree[n].key = ax.key;
				segtree[n].val = ax.val;
				return segtree[n];
			}
			else {
				segtree[n].key = bx.key;
				segtree[n].val = bx.val;
				return segtree[n];
			}
		}
	}
}
s Query(int l, int r, int st, int en, int n) {
	if (l > en || r < st) return emptyx;
	else if (l == r) return segtree[n];
	else {
		int mid = (l + r) / 2;
		s ax = Query(l, mid, st, en, n * 2);
		s bx = Query(mid + 1, r, st, en, n * 2);
		if (ax.val == -1) {
			return bx;
		}
		else if (bx.val == -1) {
			return ax;
		}
		else {
			if (ax.key == bx.key) {
				s neww = { ax.key, ax.val + bx.val };
				return neww;
			}
			else if (ax.val > bx.val) {
				return ax;
			}
			else return bx;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> Q;
	v.push_back(-1);
	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}
	init(1, N, 1);
	int tt = 1, S = tt;
	/*for (int i = 1; i < 3 * N; i++) {
		cout << "{ " << i << ", " << segtree[i].key << ", " << segtree[i].val << " } ";
		if (i % S == 0) {
			cout << "\n";
			tt *= 2;
			S += tt;
		}
	}*/

	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		s ans = Query(1, N, a, b, 1);
		cout << ans.val << "\n";
	}
	return 0;
}