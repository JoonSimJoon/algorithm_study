#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define ll long long


vector<ll> v;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	ll T;
	cin>>T;
	while(T--){
		ll xcnt=0, ycnt=0, flag=0;
		string a,mem;
		cin>>a;
		mem=a;
		ll sl = a.size();
		for(ll i=sl-1;i>=0;i--){
			if(flag ==0 && a[i]=='0'){
				flag++;
			} 
			else if(flag== 1 && (a[i]=='0' || a[i]=='5')){
				flag++;
				break;
			}
			else xcnt++;
		}
		flag=0;
		for(ll i=sl-1;i>=0;i--){
			if(flag ==0 && a[i]=='5'){
				flag++;
			} 
			else if(flag== 1 && (a[i]=='2' || a[i]=='7')){
				flag++;
				break;
			}
			else ycnt++;
		}
		if(xcnt<ycnt) cout<<xcnt<<"\n";
		else cout<<ycnt<<"\n";
	}
	return 0;
}