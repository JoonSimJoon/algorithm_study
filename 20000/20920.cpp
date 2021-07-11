#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std; 
#define ll long long unsigned
#define pp pair<ll,string>
int cp(pp a, pp b){
	if(a.first==b.first){
		if(a.second.length()==b.second.length())
			return a.second<b.second;
		else return a.second.length()>b.second.length();
	}else return a.first>b.first;
}


vector<pp> v;
pp s;
string A;
ll N,M;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(ll i=0;i<N;i++){
		cin>>s.second;
		s.first=0;
		if(s.second.length()>=M){
			v.push_back(s);
		}
	}
	sort(v.begin(),v.end(),cp);
	ll vl = v.size();
	ll tmp=0;
	v[tmp].first++;
	for(ll i=1;i<vl;i++){
		if(v[i-1].second==v[i].second) v[tmp].first++;
		else tmp=i, v[tmp].first++;
	}
	sort(v.begin(),v.end(),cp);
	for(ll i=0;i<vl;i++){
		if(v[i].first==0) break;
		else {
			//cout<<v[i].first<<" ";
			cout<<v[i].second<<"\n";
		}
	}
	
	return 0;
}