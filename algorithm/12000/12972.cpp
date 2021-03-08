#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, a;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		cin >> a;
		v.push_back(a);
	}

	return 0;
}