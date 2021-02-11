#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, ans;
vector<int> v;
int numc[200000100];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		v.push_back(K);
		for (int i = 1; i*2 <= K; i++) {
			if (K % i == 0) {
				numc[i]++;		
			}
		}	
		numc[K]++;
	}
	sort(v.begin(), v.end());
	for (int i = v[N - 1]; i >= 1; i--) {
		if (numc[i] == N) {
			ans = -1;
			break;
		}
		else if (numc[i] == N - 1) {
			ans = i;
			break;
		}
	}
	cout << ans << " ";
	if (ans == -1) return 0;
	for (int i = 0; i < N; i++) {
		if (v[i] % ans != 0) cout << v[i];
	}
	return 0;
}