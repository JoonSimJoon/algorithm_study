#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll gcd(ll x, ll y){
	if(y==0) return x;
	else return gcd(y,x%y);
}
vector<int> v;
ll a,b,c;
//A+=A
//A+=B
//B+=A
//B+=B
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>a>>b;
	c=gcd(a,b);
	a=a/c;
	b=b/c;
	while(a!=1 || b!=1){
		while(a%2==0){
			v.push_back(4);
			a/=2;
		}
		while(b%2==0){
			v.push_back(1);
			b/=2;
		}
		if(a<b){
			v.push_back(3);
			v.push_back(1);
			b=(a+b)/2;
		}
		if(a>b){
			v.push_back(2);
			v.push_back(4);
			a=(a+b)/2;
		}
		c=gcd(a,b);
		a=a/c;
		b=b/c;
	}
	ll vl = v.size();
	cout<<vl<<"\n";
	for(ll i=0;i<vl;i++){
		if(v[i]==1){
			cout<<"A+=A\n";
		}
		else if(v[i]==2){
			cout<<"A+=B\n";
		}
		else if(v[i]==3){
			cout<<"B+=A\n";
		}
		else if(v[i]==4){
			cout<<"B+=B\n";
		}
	}
	return 0;
}