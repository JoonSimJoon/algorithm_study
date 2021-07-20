#include <iostream>
using namespace std;
#define ll long long

ll N,a,sum;
vector<ll> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a;
		v.push_back(a);
		sum+=a;
	}
	if(sum%2==1){
		cout<<"-1";
	}else{
		sort(v.begin(),v.end());
		

	}
	return 0;
}