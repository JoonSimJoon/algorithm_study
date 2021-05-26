#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, ans,a; 
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for(int i=n-k;i<n;i++) ans+=v[i];
	cout << ans - k * (k - 1) / 2 << '\n';
}
