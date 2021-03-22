#include <iostream>
#include <vector>
using namespace std;

struct s {
	int r;
	char c;
};
int N, Q, K;
s a;
vector<s> v;
int check[30];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K >> Q;
	for (int i = 0; i < K; i++) {
		cin >> a.r >> a.c;
		v.push_back(a);
	}
	if (v[Q - 1].r == 0) {
		cout << "-1\n";
	}
	else {
		for (int i = 0; i < K; i++) {
			if (v[Q - 1].r <= v[i].r) {
				int idx = v[i].c - 'A';
				check[idx] = 1;
			}
		}for (int i = 1; i < N; i++) {
			if (!check[i]) cout << char(i + 'A') << " ";
		}
	}
	return 0;
}