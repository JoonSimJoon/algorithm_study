#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
#define ll long long
int inf = 987654321;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	int arr[550];
	int dp[550][550];
	while(T--){
		int N;
		cin>>N;
		memset(arr,0,sizeof(arr));
		memset(dp,0,sizeof(dp));
		
		for(int i=0;i<N;i++){
			cin>>arr[i];
			if(i!=0) arr[i]+=arr[i-1];
		}
		sort(arr,arr+N);
		for(int i=1;i<N;i++){
			for(int j=0;j+i<N;j++){
				int x = i+j;
				int ps;
				if(j==0) ps=arr[x];
				else ps = arr[x]-arr[j-1];
				dp[j][x]=inf;
				for(int k=j;k<x;k++){
					dp[j][x]=min(dp[j][x],dp[j][k]+dp[k+1][x]+ps);
				}

			}
		}
		cout<<dp[0][N-1]<<"\n";
	}
	return 0;
}