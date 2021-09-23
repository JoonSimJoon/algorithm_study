#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll N,ans;
vector<ll> v;
vector<ll> tmp;
void Divide(ll st, ll en);
void Combine(ll st, ll en);

void Divide(ll st, ll en){
	if(st==en){
		return;
	}
	ll mid = (st+en)/2;
	Divide(st,mid);
	Divide(mid+1,en);
	Combine(st,en);
	return;
}

void Combine(ll st, ll en){
	ll mid = (st+en)/2;
	ll stx = st;
	ll enx = mid+1;
	ll len = en-st+1;
	while(len){
		len--;
		if(enx==en+1){
			tmp.push_back(v[stx]);
			stx++;
		}else if(stx==mid+1){
			tmp.push_back(v[enx]);
			enx++;
			ans+=mid-stx+1;
			//cout<<stx-st+1<<"\n";
		}else if(v[stx]<=v[enx]){
			tmp.push_back(v[stx]);
			stx++;
		}else if(v[stx]>v[enx]){
			tmp.push_back(v[enx]);
			enx++;
			ans+=mid-stx+1;
			//cout<<stx-st+1<<"\n";
		}
	}
	for(ll i=st;i<=en;i++){
		v[i]=tmp[i-st];
		//cout<<v[i]<<" ";
	}
	//cout<<"*\n";
	tmp.clear();
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(ll a,i=0;i<N;i++){
		cin>>a;
		v.push_back(a);
	}
	Divide(0,N-1);
	cout<<ans;
	return 0;
}