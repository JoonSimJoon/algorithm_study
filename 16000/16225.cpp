#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long

ll N,ans;
vector< pair<ll,ll> > v;
priority_queue<ll> pq;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(ll a,i=0;i<N;i++){
		cin>>a;
		v.push_back({0,a});
	}
	for(ll b,i=0;i<N;i++){
		cin>>b;
		v[i].first=b;
	}
	sort(v.begin(),v.end());
	for(ll i=0;i<N;i+=2){
		if(i==0){
			ans+=v[i].second;
		}else{
			pq.push(v[i].second);
			pq.push(v[i-1].second);
			ans += pq.top();
			pq.pop();
		}
	}
	cout<<ans<<"\n";
	return 0;
}