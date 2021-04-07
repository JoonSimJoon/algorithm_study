#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define fr first
#define sc second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piii;

int arr[220];
set<ll> s;
int src, snk, nc;
int adj[220][220];
bool chk[220];
int pth[220], pc;

int gcd(int x, int y){
	return y ? gcd(y, x%y) : x;
}

bool cmp(int x, int y){
	if ((x & 1) ^ (y & 1)){
		if (x & 1) return true;
		else return false;
	}
	return x < y;
}

bool dfs(int now, int idx){
	chk[now] = true;
	pth[idx] = now;
	if (now == snk){
		pc = idx;
		return true;
	}
	for (int i = 0; i < nc; i++){
		if (adj[now][i] == 0 || chk[i]) continue;
		if (dfs(i, idx+1)) return true;
	}
	return false;
}

int main(){
	Fast;
	for (ll i = 1; i <= 2000000; i++) s.insert(i*i);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr+1, arr+n+1, cmp);
	int od = 1, ev = 1;
	for (int i = n; i > 0; i--){
		if (arr[i] & 1){
			ev = i+1;
			break;
		}
	}
	src = 0, snk = n+1, nc = n+2;
	for (int i = od; i < ev; i++) adj[src][i] = 1;
	for (int i = ev; i <= n; i++) adj[i][snk] = 1;
	for (int i = od; i < ev; i++){
		for (int j = ev; j <= n; j++){
			ll x = arr[i], y = arr[j];
			if (gcd(x, y) != 1) continue;
			if (s.count(x*x + y*y)) adj[i][j] = 1;
		}
	}
	int ans = 0;
	while (dfs(src, 0)){
		for (int i = 0; i < nc; i++) chk[i] = false;
		for (int i = 0; i < pc; i++){
			int x = pth[i], y = pth[i+1];
			adj[x][y] -= 1;
			adj[y][x] += 1;
		}
		ans += 1;
	}
	cout << ans;
}
