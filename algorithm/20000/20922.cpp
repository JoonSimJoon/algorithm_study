#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct s {
	int key, val;
};
int N, K, a, ans = -1;
vector<int> v;
s arr[100010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
		arr[a].val++;
		if (arr[a].val == K) {
			
		}
	}

	return 0;
}