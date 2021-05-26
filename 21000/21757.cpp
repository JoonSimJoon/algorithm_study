#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#define ll long long

ll N,a,sum,ans;
vector<ll> v,ssum;
ll pfx[100010],sfx[100010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a;
		sum+=a;
		v.push_back(a);
		ssum.push_back(sum);
	}	
	if(sum%4!=0){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<N;i++) pfx[i]=pfx[i-1]+(ssum[i]==sum/4);
	for(int i=N-2;i>=0;i--) sfx[i]=sfx[i+1]+(ssum[i]==3*sum/4);
	for(int i=1;i<N-1;i++) ans+=(ssum[i]==2*sum/4)*pfx[i-1]*sfx[i+1];
	cout<<ans;
	return 0;
}
