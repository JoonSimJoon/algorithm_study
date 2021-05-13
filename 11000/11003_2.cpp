#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
struct s{
	ll key,value;
	bool operator()(s a, s b){
		if(a.value==b.value){
			return a.key>b.key;
		}
		return a.value>b.value;
	}
};

ll N,L,a;
vector<ll> v;
priority_queue<s, vector<s>, s > pq;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>L;
	for(ll i=1;i<=N;i++){
		cin>>a;
		s x;
		x.value=a;
		x.key=i;
		pq.push(x);
		while(pq.top().key<=i-L) pq.pop();	
		cout<<pq.top().value<<" ";
	}
	return 0;
}
