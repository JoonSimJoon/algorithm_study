#include <iostream>
#include <string>
using namespace std;
#define ll long long
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		ll cnt=1;
		ll N,M,K,D,ans=0;
		cin>>N>>M>>K>>D;
		ll x=N*((M*(M-1))/2);
		ll y = M*M*((N*(N-1))/2); 
		if(x*K*cnt+y*cnt>D) cout<<"-1\n";
		else{
			ll ans = (D/(x*K+y));
			cout<<ans*(x*K+y)<<"\n";
		}
	}
}

