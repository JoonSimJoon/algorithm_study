#include <iostream>
using namespace std;
#define ll long long

ll dp[55]={1,1,3,5,  };

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin>>N;
	for(int i=4;i<=N;i++){
		dp[i]=(dp[i-2]+dp[i-1]+1)%1000000007;
	}
	cout<<dp[N];
	return 0;
}
