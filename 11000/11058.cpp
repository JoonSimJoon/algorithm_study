#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
ll dp[1000]={0,1,2,3,4,5,6, };
ll N;

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>N;
	for(int i=7;i<=N;i++){
		dp[i]=max(max(dp[i-3]*2,dp[i-4]*3),dp[i-5]*4);
	}
	cout<<dp[N]<<"\n";
}