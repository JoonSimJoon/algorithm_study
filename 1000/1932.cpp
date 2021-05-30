#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[510][510];
int dp[510][510];
int ans=-1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){
			cin>>arr[i][j];
		}
	}
	dp[0][0]=arr[0][0];
	for(int i=1;i<N;i++){
		for(int j=0;j<=i;j++){
			if(j==0) dp[i][j]=arr[i][j]+dp[i-1][j];
			else{
				dp[i][j]=arr[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
			}
		}
	}
	for(int i=0;i<N;i++){
		ans=max(ans,dp[N-1][i]);
	}
	cout<<ans;
	return 0;
}
