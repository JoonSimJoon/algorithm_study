//#include <iostream>
//#include <string>
//#include <string.h>
//#include <algorithm>
//#include <vector>
//using namespace std;
//#define ll long long
//int N;
//ll ans;
//vector<string> arr1;
//vector<string> arr2;
//string a;
//
//int find(int l, int r, string now) {
//	if (l == r) return 1;
//	else {
//		int m = (l + r) / 2;
//		int k = now.compare(arr2[m]);
//		if (k < 0) {
//			return find(l, m, now);
//		}
//		else if (k == 0) {
//			return m;
//		}
//		else {
//			return find(m + 1, r, now);
//		}
//	}
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> a;
//		arr1.push_back(a);
//		reverse(a.begin(), a.end());
//		arr2.push_back(a);
//	}
//	
//	sort(arr1.begin(), arr1.end());
//	sort(arr2.begin(), arr2.end());
//
//	/*for (int i = 0; i < N; i++) {
//		cout << arr1[i] << " " << arr2[i] << "\n";
//	}*/
//	for (int i = 0; i < N; i++) {
//		a = arr1[i];
//		reverse(a.begin(), a.end());
//		int cntt = find(0, N - i, a);
//		arr2.erase(arr2.begin() + cntt);
//		ans += cntt;
//	}
//	cout << ans << "\n";
//	return 0;
//}

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int n, seg[400040];
long long r;
string s[100010];
pair<string, int> rs[100010];
int update(int pos, int val, int node, int x, int y) {
    if (y < pos || pos < x)return seg[node];
    if (x == y)return seg[node] = val;
    int mid = (x + y) >> 1;
    return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}
int query(int lo, int hi, int node, int x, int y) {
    if (y < lo || hi < x)return 0;
    if (lo <= x && y <= hi)return seg[node];
    int mid = (x + y) >> 1;
    return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s, s + n);
    for (int i = 0; i < n; i++) {
        reverse(s[i].begin(), s[i].end());
        rs[i] = { s[i],i };
    }
    sort(rs, rs + n);
    for (int i = 0; i < n; i++) {
        r += (long long)query(rs[i].second, n - 1, 1, 0, n - 1);
        update(rs[i].second, 1, 1, 0, n - 1);
    }
    cout << r;
    return 0;
}
