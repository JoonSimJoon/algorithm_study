#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long

set<ll> s;
set<ll>::iterator it;
ll N,K,A,sum,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	s.insert(0);
	for(ll i=0;i<N;i++){
		cin>>A;
		sum+=A;
		ll tt = K-sum;
		it = s.find(tt);
		if(*it==tt){
			ans++;
		}
		
	}
	return 0;
}