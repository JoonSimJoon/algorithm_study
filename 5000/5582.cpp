#include <iostream>
#include <string>
using namespace std;
string a,b;
int dp[4010][4010],ans=-1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>a>>b;
	int al = a.length();
	int bl = b.length();
	for(int i=1;i<=al;i++){
		for(int j=1;j<=bl;j++){
			if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			ans = max(ans,dp[i][j]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}