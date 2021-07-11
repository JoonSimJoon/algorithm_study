#include <iostream>

using namespace std;
int arr[100010][4];
int dp[100010][4][3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}
	for(int i=0;i<3;i++){
		dp[0][i][0]=arr[0][i];
		dp[0][i][1]=arr[0][i];
	}
	for(int i=1;i<N;i++){
		if(dp[i-1][0][0]>dp[i-1][1][0]){
			dp[i][0][0]=dp[i-1][0][0]+arr[i][0];
		}else dp[i][0][0]=dp[i-1][1][0]+arr[i][0];
		if(dp[i-1][0][0]>=dp[i-1][1][0] && dp[i-1][0][0]>=dp[i-1][2][0]){
			dp[i][1][0]=dp[i-1][0][0]+arr[i][1];
		}else if(dp[i-1][1][0]>=dp[i-1][0][0] && dp[i-1][1][0]>=dp[i-1][2][0]){
			dp[i][1][0]=dp[i-1][1][0]+arr[i][1];
		}else  dp[i][1][0]=dp[i-1][2][0]+arr[i][1];		
		if(dp[i-1][2][0]>dp[i-1][1][0]){
			dp[i][2][0]=dp[i-1][2][0]+arr[i][2];
		}else dp[i][2][0]=dp[i-1][1][0]+arr[i][2];
		
		if(dp[i-1][0][1]<dp[i-1][1][1]){
			dp[i][0][1]=dp[i-1][0][1]+arr[i][0];
		}else dp[i][0][1]=dp[i-1][1][1]+arr[i][0];
	
		if(dp[i-1][0][1]<=dp[i-1][1][1] && dp[i-1][0][1]<=dp[i-1][2][1]){
			dp[i][1][1]=dp[i-1][0][1]+arr[i][1];
		}else if(dp[i-1][1][1]<=dp[i-1][0][1] && dp[i-1][1][1]<=dp[i-1][2][1]){
			dp[i][1][1]=dp[i-1][1][1]+arr[i][1];
		}else  dp[i][1][1]=dp[i-1][2][1]+arr[i][1];		
		
		if(dp[i-1][2][1]<dp[i-1][1][1]){
			dp[i][2][1]=dp[i-1][2][1]+arr[i][2];
		}else dp[i][2][1]=dp[i-1][1][1]+arr[i][2];
		
		




	}
	cout<<max(dp[N-1][1][0],max(dp[N-1][2][0],dp[N-1][0][0]))<<" "<<min(dp[N-1][1][1],min(dp[N-1][2][1],dp[N-1][0][1]))<<"\n";
	return 0;
}