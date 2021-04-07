#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
ll gcd(ll a, ll b){
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}
vector<ll> v;
ll N,arr1[1000010], arr2[1000010];
ll a, b;
ll K=-1, ans=-1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		v.push_back(K);
	}
	sort(v.begin(), v.end());
	a = v[0];
	b = v[N - 1];
	for (int i = 0; i < N; i++) {
		a=gcd(v[i], a);
		b=gcd(b, v[N - 1 - i]);
		arr1[i] = a;
		arr2[N - 1 - i] = b;
	}
	a = 0, b = 0;
	for (int i = 0; i < N; i++) {
		int flag = 0;
		a = b = -1;
		if (i != 0) {
			if (arr1[i-1] > arr1[i])flag++;
		}
		else flag++;
		if (i != N - 1) {
			if (arr2[i] < arr2[i + 1])flag++;
		}
		else flag++;
		if (flag == 2) {
			if (i == 0) ans = arr2[1];
			else if (i == N - 1) ans = arr2[N - 2];
			else ans = min(arr1[i - 1], arr2[i + 1]);
			K = v[i];
		}
		//cout << arr1[i] << " " << arr2[i] << "\n";
	}
	if (ans == -1) cout << "-1\n";
	else cout << ans << " " << K << "\n";
	
	return 0;
}