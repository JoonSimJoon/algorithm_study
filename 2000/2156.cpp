#include <iostream>
#include <algorithm>
using namespace std;

int dp[10010];
int arr[10010];
int N;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	dp[0] = arr[0];
	dp[1] = arr[0]+arr[1];
    for (int i=2; i<N; i++) {
        dp[i] = dp[i-1];
        dp[i] = max(dp[i], dp[i-2]+arr[i]);
        dp[i] = max(dp[i], dp[i-3]+arr[i-1]+arr[i]);
    }
    cout<<dp[N-1]<<"\n";
	return 0;
}