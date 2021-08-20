#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

ll N,sum,ans,cnt;
ll arr[200010];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	ll ssum = sum/N;
	ll mod = sum%N;
	sort(arr,arr+N);
	reverse(arr,arr+N);
	for(int i=0;i<N;i++){
		if(arr[i]>ssum){
			cnt++;
			ans+=arr[i]-ssum;
		} 
	}
	if(cnt>mod) ans-=mod;
	else ans-=cnt;
	cout<<ans;
	return 0;
}