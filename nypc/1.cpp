#include <iostream>
using namespace std;
#define ll long long

ll a,b,c;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>a>>b>>c;
	a--;
	ll N = c/a;
	if( c%a> 0) N++;
	cout<<N;
	return 0;
}