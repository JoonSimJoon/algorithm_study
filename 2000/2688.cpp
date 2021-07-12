#include <iostream>
using namespace std;
#define ll long long
ll dp[70][12];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<10;i++){
		dp[1][i]=1;
		dp[1][11]+=dp[1][i];
	}
	for(int i=2;i<65;i++){
		for(int j=0;j<10;j++){
			for(int k=j;k<10;k++){
				dp[i][j]+=dp[i-1][k];
			}
			dp[i][11]+=dp[i][j];
		}
	}
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		
		cout<<dp[N][11]<<"\n";
	}
	return 0;
}