#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long 
ll N;
vector<ll> v;
int main(){
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin>>N;
	for(ll a,i=0;i<N;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	
	return 0;
}