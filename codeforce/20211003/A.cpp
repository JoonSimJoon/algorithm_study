#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define ll long long


vector<ll> v;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	ll T;
	cin>>T;
	while(T--){
		ll n,h,cnt=0;
		cin>>n>>h;
		v=vector<ll>();
		for (ll a, i = 0; i < n; i++){
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		if(h<=v[0]) cnt=1;
		else{
			if(h%(v[0]+v[1])==0){
				cnt=2*(h/(v[0]+v[1]));
			}
			else if(h%(v[0]+v[1])<=v[0]){
				cnt=2*(h/(v[0]+v[1]))+1;
			}else{
				cnt=2*(h/(v[0]+v[1]))+2;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}