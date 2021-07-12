#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long

ll N,M,P,ans=1;
ll pt[2010][2010];
vector<ll> v1;
vector<ll> v2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//memset(pt,-1,sizeof(pt));
	cin>>N>>M>>P;
	for(ll i=0;i<=P;i++){
		for(ll j=0;j<=i;j++){
			if(i==0 || j==0 || i==j) pt[i][j]=1;
			else pt[i][j]=pt[i-1][j-1]%P+pt[i-1][j]%P;
			pt[i][j]%=P;
			//cout<<pt[i][j]<<" ";
		}
		//cout<<"\n";
	}
	while(N!=0 && M!=0 ){
		ans*=pt[N%P][M%P];
		N/=P;
		M/=P;
		ans%=P;
	}
	cout<<ans<<"\n";
	return 0;
}