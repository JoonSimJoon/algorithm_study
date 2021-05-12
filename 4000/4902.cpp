#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,tcnt=1;
	while(cin>>N){
		int ans=0;
		if(N==0)break;
		int dp[160010]={0, };
		for(int i=1;i<=N*N;i++){
			cin>>dp[i];
		}
		
		
		cout<<tcnt<<". "<<ans<<"\n";
		tcnt++;
	}
	return 0;
}
