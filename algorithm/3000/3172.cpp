#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int N;
ll ans;
vector<string> arr1;
vector<string> arr2;
string a;

int find(int l, int r, string now) {
	if (l == r) return 1;
	else {
		int m = (l + r) / 2;
		int k = now.compare(arr2[m]);
		if (k < 0) {
			return find(l, m, now);
		}
		else if (k == 0) {
			return m;
		}
		else {
			return find(m + 1, r, now);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		arr1.push_back(a);
		reverse(a.begin(), a.end());
		arr2.push_back(a);
	}
	
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	/*for (int i = 0; i < N; i++) {
		cout << arr1[i] << " " << arr2[i] << "\n";
	}*/
	for (int i = 0; i < N; i++) {
		a = arr1[i];
		reverse(a.begin(), a.end());
		int cntt = find(0, N - i, a);
		arr2.erase(arr2.begin() + cntt);
		ans += cntt;
	}
	cout << ans << "\n";
	return 0;
}