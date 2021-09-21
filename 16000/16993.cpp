#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll N,M;
ll arr[100010];
ll seg[400010];

ll init(ll st, ll en, ll idx){
	if(st==en){
		seg[idx]=arr[st];
		return seg[idx];
	} 
	ll mid = (st+en)/2;
	seg[idx]=init(st,mid,idx*2)+init(mid+1,en,idx*2+1);
	return seg[idx];
}

ll query(ll st, ll en, ll left, ll right, ll idx){
	if (left > en || right < st) return -100000000;
	//if(st==en) return seg[idx];
	if (left <= st && en <= right) return seg[idx]; 
	int mid = (st + en) / 2;
	return max(query(st, mid, left, right, idx*2),max(query(mid+1, en, left, right, idx*2+1),seg[idx*2]+seg[idx*2+1]));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(ll i=1;i<=N;i++){
		cin>>arr[i];
	}
	init(0,N-1,1);
	cin>>M;
	while(M--){
		ll a,b,ans;
		cin>>a>>b;
		ans = query(0,N-1,a,b,1);
		cout<<ans<<"\n";
	}
	return 0;
}
