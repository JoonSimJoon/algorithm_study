#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf=1010;
int N,a,ans;
int dp[1010];
int arr[1010];
int mm[1010];
vector<int> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	for(int i=0;i<N;i++){
		mm[i]=i;
		int mem=i;
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]){
				if(dp[i]<dp[j]+1){
					dp[i]=dp[j]+1;
					mem=j;
				}
			}
		}
		mm[i]=mem;
		if(dp[i]>ans){
			ans=dp[i];
			a=i;
		}
	}
	for(int i=0;i<ans;i++){
		v.push_back(arr[a]);
		a=mm[a];
	}
	cout<<ans<<"\n";
	reverse(v.begin(),v.end());
	for(int i=0;i<ans;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
