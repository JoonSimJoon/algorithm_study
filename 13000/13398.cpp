#include <iostream>
using namespace std;
#define ll long long
ll N,ans;
ll dp[100010][4];
ll a[100010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(ll i=0;i<N;i++){
		cin>>a[i];
	}
	dp[0][0] = a[0];
	dp[0][1] = a[0];

	ans = max(dp[0][0], dp[0][1]);
	for (ll i = 1; i < N; i++)
	{
		dp[i][0] = max((ll)0, dp[i - 1][0]) + a[i];
		dp[i][1] = max(dp[i - 1][1] + a[i], dp[i - 1][0]);
		ans = max(max(dp[i][0],dp[i][1]), ans);
	}
	cout<<ans;
	return 0;
}