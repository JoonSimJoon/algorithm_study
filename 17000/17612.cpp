#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long
struct s{
	ll key,val,num;
	bool operator()(s a,s b){
		if(a.val==b.val) return a.num>b.num;
		else return a.val>b.val;
	}
};
bool cmps(s a,s b){
	if(a.val==b.val) return a.num>b.num;
	else return a.val<b.val;
}
vector<s> v;
priority_queue<s,vector<s>,s> pq;
ll N,M,ans,cnt=1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(ll i=0;i<N;i++){
		s tmp;
		cin>>tmp.key>>tmp.val;
		tmp.num=i+1;
		if(i<M){
			pq.push(tmp);
			continue;
		}
		tmp.val+=pq.top().val;
		tmp.num=pq.top().num;
		pq.push(tmp);
		v.push_back(pq.top());
		pq.pop();
	}
	while(!pq.empty()){
		v.push_back(pq.top());
		pq.pop();
	}
	sort(v.begin(),v.end(),cmps);
	for(int i=0;i<N;i++){
		ans+=cnt*v[i].key;
		cnt++;
	}
	cout<<ans<<"\n";
	return 0;
}
