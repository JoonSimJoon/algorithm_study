#include <iostream>
using namespace std;
#define ll long long

vector<ll> v;
ll N;
ll cnt;
pair<ll,ll> now;
ll xnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(ll a,i=0;i<N;i++){
		cin>>a;
		v.push_back(a);
	}
	for(ll i=0;i<N;i++){
		if(xnt==0){
			now.first=1;
			now.second=v[i];
			xnt++;
		}
		if(now.second)

		if(xnt==3){
			cnt+=now.second*7;
			xnt=0;

		}

	}
	return 0;
}