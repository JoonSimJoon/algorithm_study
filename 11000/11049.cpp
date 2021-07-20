#include <iostream>
#include <vector>
using namespace std;
const int inf = 987654321;
int N;
vector< pair<int,int> > v;
int dp[520][520];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int a,b,i=0;i<N;i++){
		cin>>a>>b;
		v.push_back({a,b});
	}
	for(int i=1;i<N;i++){
		for(int s=0;s+i<N;s++){
			int e = i+s;
			dp[s][e]=inf;
			for(int k=s;k<=e;k++){
				dp[s][e]=min(dp[s][e],dp[s][k]+dp[k+1][e]+v[s].first*v[k].second*v[e].second);
			}
		}
	}
	cout<<dp[0][N-1];
	return 0;
}