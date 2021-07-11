#include <iostream>
#include <string.h>
using namespace std;
int dp[520][520];
int arr[520][520];
int dx[4]= {0,0,1,-1};
int dy[4]={1,-1,0,0};
int N;

int dfs(int posx,int posy){
	if (dp[posx][posy]!=-1) return dp[posx][posy];
	dp[posx][posy] = 1;
	int nextx,nexty;
	for(int i=0;i<4;i++){
		nexty=posy+dy[i];
		nextx=posx+dx[i];
		if(nextx<0 || nextx>=N || nexty<0 || nexty>=N) continue;
		if(arr[nextx][nexty]<arr[posx][posy]){
			dp[posx][posy] = max(dp[posx][posy], dfs(nextx, nexty) + 1);

		}
	}
	return dp[posx][posy];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
		ans = max(ans, dfs(i, j));

	cout<<ans<<"\n";
	return 0;

}