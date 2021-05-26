#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define ll long long
ll n;
ll s[100010];
ll ans,a[100010];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=2;i<=n-1;i++) ans=max(ans,s[n-1]-a[1]+a[i]);
	for(int i=2;i<=n-1;i++) ans=max(ans,s[i-1]-a[1]+2*(s[n]-s[i]));
	for(int i=2;i<=n-1;i++) ans=max(ans,2*s[i-1]+s[n-1]-s[i]);
	cout<<ans;
	return 0;
}
