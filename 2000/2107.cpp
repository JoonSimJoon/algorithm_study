#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct s {
	int first, second;
};
bool cp(s a, s b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

vector<s> v;
s q;
int N,ans=-1;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> q.first >> q.second;
		v.push_back(q);
	}
	sort(v.begin(), v.end(),cp);
	for (int i = 0; i < N; i++) {
		int cnt=0;
		for (int j = i + 1; j < N; j++) {
			//if (v[i].second < v[j].first) break;
			if (v[i].first<v[j].first && v[i].second>v[j].second) {
				cnt++;
			}
		}
		if (ans < cnt) ans = cnt;
	}
	cout << ans << "\n";
	return 0;
}