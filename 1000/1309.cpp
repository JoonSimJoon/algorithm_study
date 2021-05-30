#include <iostream>
using namespace std;
int dp[100010]={1,3,7,17, };

int N;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=4;i<=N;i++){
		dp[i]=dp[i-1]*2+dp[i-2];
		dp[i]%=9901;
	}
	cout<<dp[N];
	return 0;
}
