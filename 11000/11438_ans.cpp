#include <iostream>
#include <math.h>
#include <vector>
#define MAX 100001
#define MAX_LOG2 31
using namespace std;

int N, M, max_level, depth[MAX], ac[MAX][MAX_LOG2];
vector<int> v[MAX];

void make_tree(int here, int parent);
int LCA(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int a, b;
	cin >> N;
	max_level = (int)floor(log2(N));
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	depth[0] = -1;
	make_tree(1, 0);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
	return 0;
}

void make_tree(int here, int parent) {
	depth[here] = depth[parent] + 1;
	ac[here][0] = parent;
	for (int i = 1; i <= max_level; i++) {
		int temp = ac[here][i - 1];
		ac[here][i] = ac[temp][i - 1];
	}
	
	int len = v[here].size();
	for (int i = 0; i < len; i++) {
		int neighbor = v[here][i];
		if (neighbor != parent) {
			make_tree(neighbor, here);
		}
	}
}

int LCA(int a, int b) {
	int ret = -1;

	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) {
			int temp = a;
			a = b;
			b = temp;
		}
		for (int i = max_level; i >= 0; i--) {
			if (depth[ac[b][i]] >= depth[a]) {
				b = ac[b][i];
			}
		}
	}

	ret = a;
	if (a != b) {
		for (int i = max_level; i >= 0; i--) {
			if (ac[a][i] != ac[b][i]) {
				a = ac[a][i];
				b = ac[b][i];
			}
			ret = ac[a][i];
		}
	}

	return ret;
}