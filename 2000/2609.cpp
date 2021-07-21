#include <iostream>
using namespace std;


int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin>>N>>M;
	int ans = gcd(N,M);
	cout<<ans<<" "<<(M/ans)*N<<"\n";
	return 0;	
}