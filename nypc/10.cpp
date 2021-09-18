    #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

ll N,K,ans=-1,tmp=0;
vector<ll> v;
ll ssum[200010];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	for(ll a,i=0;i<N;i++){
		cin>>a;
		v.push_back(a);
	}
	for(ll j=0;j<K;j++){
		for(ll k=0;k<j;k++){
			if(v[j]-v[k]<0) tmp-=v[j]-v[k];
			else tmp+=v[j]-v[k];
		}
	}
	ans=tmp;
	for(ll i=1;i<=N-K;i++){
		for(ll j=0;j<K-1;j++){
			if(v[i-1]-v[i+j]<0) tmp+=v[i-1]-v[i+j];
			else tmp-=v[i-1]-v[i+j];
		}
		for(ll j=0;j<K-1;j++){
			if(v[i+K-1]-v[i+j]<0) tmp-=v[i+K-1]-v[i+j];
			else tmp+=v[i+K-1]-v[i+j];
		}
		//cout<<tmp<<"\n";
		if(tmp>ans) ans=tmp;
	}
	cout<<ans;
	return 0;
}