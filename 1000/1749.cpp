#include <iostream>
using namespace std;
#define ll long long

ll a,N,M,ans;
ll dp[300][300];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin>>a;
			dp[i][j]=a+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
	ans=dp[1][1];
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			for(int k=i;k<=N;k++){
				for(int g=j;g<=M;g++){
					ans=max(dp[k][g]-dp[i-1][g]-dp[k][j-1]+dp[i-1][j-1],ans);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}