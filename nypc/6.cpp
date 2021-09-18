#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
priority_queue <pair <ll,ll> > pq;
ll N,K,cnt;
vector<ll> v;
ll chk[300010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	for(ll a,i=0;i<N;i++){
		cin>>a;
		v.push_back(a);
		pq.push({-a,i});
	}
	while(!pq.empty()){
		ll i;
		int now=pq.top().second;
		pq.pop();
		if(chk[now]==1) continue;
		chk[now]=1;
		cnt++;
		i = now-1;
		while(i>=0){
			if(v[now]+K<v[i] || v[now]>v[i]) break;
			else{
				chk[i]=1;
				i--;
			}
		}
		i=now+1;
		while(i<N){
			if(v[now]+K<v[i] || v[now]>v[i]) break;
			else{
				chk[i]=1;
				i++;
			}
		}
	}
	cout<<cnt;
	return 0;
}