#include <algorithm>
#include <iostream>
using namespace std;
#define  ll long long
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll i,N,M,cnt1=1,cnt2=1;
	cin>>N>>M;
	for(int i=M+1;i<=N;i++){
		cnt1*=i;
		while(cnt2<=N-M){
			if(cnt1%cnt2==0){
				cnt1=cnt1/cnt2;
				cnt2++;
			}else break;
		}
	}
	cout<<cnt1;
	return 0;
}
