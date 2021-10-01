#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define ll long long

ll N,K;
vector< pair<ll,ll> > v;
vector<ll> c;

int main(){
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin>>N>>K;
	for(ll a,b,i=0;i<N;i++){
		cin>>a>>b;
		v.push_back({a,b});
	}
	for(ll a,i=0;i<K;i++){
		cin>>a;
		c.push_back(a);
	}
	sort(v.begin(),v.end());
	sort(c.begin(),c.end());	
	ll res=0;
	ll idx=0;
	priority_queue<ll> pq;
	for(ll i=0;i<K;i++){
		while(idx<N && v[idx].first<=c[i]){
			pq.push(v[idx].second);
			idx++;
		}
		if(!pq.empty()){
			res+=pq.top();
			pq.pop();
		}
	}
	cout<<res<<"\n";
	return 0;
}