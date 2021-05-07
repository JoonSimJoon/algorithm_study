#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dp[1000010]={0,0, };

int main(){
	cin>>N;
	for(int i=2;i<=N;i++){
		dp[i]=dp[i-1]+1;
		if(i%2==0) dp[i]=min(dp[i/2]+1,dp[i]);
		if(i%3==0) dp[i]=min(dp[i/3]+1,dp[i]);
	}
	cout<<dp[N]<<"\n";
	return 0;
}