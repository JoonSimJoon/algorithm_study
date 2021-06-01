#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
ll N,a,b,ans,big;
vector<pair<int,int> > v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(ll i=0;i<N;i++){
		cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	for(ll i=0;i<N;i++){
		if(i==0) ans+=v[i].second-v[i].first,big=v[i].second;
		else{
			if(big>=v[i].second) continue;
			else{
				if(big<=v[i].first){
					ans+=v[i].second-v[i].first,big=v[i].second;
				}
				else{
					ans+=v[i].second-big;
					big=v[i].second;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
