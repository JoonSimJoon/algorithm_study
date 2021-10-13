#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define ll long long


vector<ll> v;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	ll T;
	cin>>T;
	while(T--){
		ll arr[4],xnt=0;
		for(ll i=0;i<3;i++){
			cin>>arr[i];
		}
		ll mx = max(arr[0],max(arr[1],arr[2]));
		for(ll i=0;i<3;i++){
			if(mx == arr[i]) xnt++;
		}
		for(ll i=0;i<3;i++){
			if(mx == arr[i]){
				if(xnt>1) cout<<"1 ";
				else cout<<"0 ";
			}else{
				cout<<mx-arr[i]+1<<" ";
			}
		}
		cout<<"\n";
	}
	return 0;
}