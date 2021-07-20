#include <iostream>
using namespace std;
int ans[120][15];
int inf = 1000000000;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin>>N;
	ans[1][0]=1;
	for(int i=1;i<10;i++){
		ans[1][i]++;
		ans[1][13]++;
	}
	for(int i=2;i<=N;i++){
		ans[i][0]=ans[i-1][1]%inf;
		for(int j=1;j<10;j++){
			ans[i][j]=ans[i-1][j-1]%inf+ans[i-1][j+1]%inf;
			ans[i][j]%=inf;
			ans[i][13]+=ans[i][j]%inf;
			ans[i][13]%=inf;
		}
	}
	cout<<ans[N][13]<<"\n";
	return 0;

}