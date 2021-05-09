#include <iostream>
#include <algorithm>
using namespace std;
int arr[1010],dp[1010][3],ans=-1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	for(int i=0;i<N;i++){
		dp[i][0]=1;
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]) dp[i][0]=max(dp[i][0],dp[j][0]+1);
		}
	//	cout<<dp[i][0]<<" ";
	}
	for(int i=N-1;i>=0;i--){
		dp[i][1]=1;
		for(int j=N-1;j>i;j--){
			if(arr[j]<arr[i]) dp[i][1]=max(dp[i][1],dp[j][1]+1);
		}
	//	cout<<dp[i][1]<<" ";
	}
	for(int i=0;i<N;i++){
		ans=max(ans,dp[i][0]+dp[i][1]-1);
	}
	cout<<ans<<"\n";
	return 0;
}
