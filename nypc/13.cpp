#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll N,M;
vector<ll> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(ll a,i=0;i<N;i++){
		cin>>a;
		v.push_back(a);
	}

	
	return 0;
}