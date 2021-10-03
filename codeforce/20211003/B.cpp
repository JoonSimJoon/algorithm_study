#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define ll long long
vector<ll> v;
vector< pair<ll,ll> > arr;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	ll T;
	cin>>T;
	while(T--){
		ll n,x,cnt=0,flag=0;
		cin>>n>>x;
		v=vector<ll >();
		arr=vector<pair <ll,ll> >();
		for (ll a, i = 0; i < n; i++){
			cin>>a;
			v.push_back(a);
			arr.push_back({a,i});
		}
		for(ll i=1;i<n;i++){
			if(v[i]<v[i-1]){
				flag=1;
				break;
			}
		}
		if(flag==0 || x<=n/2){
			cout<<"YES\n";
			continue;	
		}else{
			flag=0;
			sort(arr.begin(),arr.end());
			for(ll i=0;i<n;i++){
				//cout<<arr[i].first<<" "<<arr[i].second<<"\n";
				if(  abs(i-arr[i].second)!=0 && arr[i].first!=arr[arr[i].second].first && abs(i-arr[i].second)<x){
					flag=1;
					break;
				}
			}
			if(flag==0) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}