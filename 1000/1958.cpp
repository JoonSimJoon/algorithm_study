#include <string>
#include <iostream>
using namespace std;

	int dp[101][101][101]={0, };
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a,b,c;
	cin>>a>>b>>c;
	int al = a.length();
	int bl = b.length();
	int cl = c.length();
	for(int i=1;i<=al;i++){
		for(int j=1;j<=bl;j++){
			for(int k=1;k<=cl;k++){
				if(a[i-1] == b[j-1] && a[i-1]==c[k-1]){
					dp[i][j][k] = dp[i-1][j-1][k-1]+1;
					
				}
				else{
					dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
				}
			}
		}
	}
	cout<<dp[al][bl][cl]<<" ";
	return 0;
}
