#include <iostream>
#include <deque>
#include <vector>
using namespace std;
#define ll long long
ll N, L;
ll arr[5000010];
deque<pair<ll,ll> > dq; //val, key
vector<ll> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> L;
	for (ll i = 0; i < N; i++) {
		while (!dq.empty() && dq.front().second <= i - L ) {
			dq.pop_front();
		}
		cin >> arr[i];
		while (!dq.empty() && dq.back().first >= arr[i] )dq.pop_back();
		dq.push_back({ arr[i],i });
		v.push_back(dq.front().first);
	}
	for (ll i = 0; i < N; i++) cout << v[i] << " ";
	return 0;
}