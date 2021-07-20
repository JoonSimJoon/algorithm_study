#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int dp[101];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    fill(dp,dp+101,MAX);
    dp[0]=0;
    vector<int> v = {1,10,25};
    for(int i =1; i <= 99; i++){
        for(int x : v){
            if(i-x>=0)dp[i]=min(dp[i],dp[i-x]+1);
        }
    }
    while(t--){
        ll n;
        cin >> n;
        ll ans= 0;
        while(n){
            ans += dp[n%100];
            n/=100;
        }
        cout << ans<<"\n";
    }
}
