    #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

ll N,K,cnt;
vector<ll> v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	for(ll a,i=0;i<N;i++){
		cin>>a;
		v.push_back(a);
	}
	ll st=0;
	cnt=1;i
	for(ll i=0;i<N;i++){
		if(v[i]>v[st]+K || v[st]>v[i]){
			st=i;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}