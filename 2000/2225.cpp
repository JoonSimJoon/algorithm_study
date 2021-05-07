#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const ll MX = 1e9;
ll N,K;
ll dp[240][240];
ll f(int num,int k){
	if(k==1) return 1;
	else{
		ll ans=0;
		for(int i=0;i<=num;i++){
			if(dp[num-i][k-1]==0) dp[num-i][k-1]=f(num-i,k-1)%MX;
			ans+=dp[num-i][k-1]%MX;
			ans=ans%MX;
		}
		return ans;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	ll ans = f(N,K);
	cout<<ans<<"\n";
	return 0;
}