#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;
vector<p> v;

int main(){
	v.resize(26);
	string s; cin >> s;
	for(int i=0; i<52; i++){
		int now = s[i] - 'A';
		if(v[now].x == 0) v[now].x = i+1;
		else v[now].y = i+1;
	}

	int ans = 0;
	int n = 26;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int s1 = v[i].x;
			int e1 = v[i].y;
			int s2 = v[j].x;
			int e2 = v[j].y;
			if(s1 < s2 && s2 < e1 && e1 < e2) ans++;
		}
	}
	cout << ans;
}