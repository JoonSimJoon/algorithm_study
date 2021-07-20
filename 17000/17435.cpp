#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[505050][22];
int n, q;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++) cin >> dp[i][0];

	for(int j=1; j<22; j++)
        for(int i=1; i<=n; i++)
            dp[i][j] = dp[ dp[i][j-1] ][j-1];

	cin >> q;
    while(q--){
        ll n, x; cin >> n >> x;
        for(int i=0; n; i++){
        	if(n & 1) x = dp[x][i];
        	n >>= 1;
		}
        cout << x << "\n";
    }
}
