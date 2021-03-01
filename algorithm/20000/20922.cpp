#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
ll N, K, st, en, len = -1;
ll arr[200010], cnt[100011];

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> N >> K;
	for (ll i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cnt[arr[st]]++;
	en++;
	cnt[arr[en]]++;
	while (1) {					
		if (st >= N) break;
		else{	
			//cout << st << " " << en << "\n";
			if (cnt[arr[en]] > K) {
				//cout << "*" << st << " " << en << "\n";
				while (1) {
					if (cnt[arr[en]] <= K) break;
					cnt[arr[st]]--;
					st++;
				}
			}
			else {
				if (len < en - st + 1) {
					len = en - st + 1;
				}
				if (en < N - 1) {
					en++;
					cnt[arr[en]]++;
				}
				else st++;
			}
		}
	}
	cout << len << "\n";
	return 0;
}