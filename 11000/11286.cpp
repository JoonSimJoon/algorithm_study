#include <queue>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
struct s{
	ll val;
	bool operator()(s a,s b){
		if(a.val*a.val==b.val*b.val) return a.val>b.val;
		else return a.val*a.val>b.val*b.val;
	}
};

priority_queue<s, vector<s>, s> pq;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N;
	cin>>N;
	for(ll i=0;i<N;i++){
		s x;
		cin>>x.val;
		if(x.val==0){
			if(pq.empty()) cout<<"0\n";
			else{
				cout<<pq.top().val<<"\n";
				pq.pop();
			}
		}else{
			pq.push(x);
		}
	}
	return 0;
}
