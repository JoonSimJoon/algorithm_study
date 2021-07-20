#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int dp[320][320],flag;
int dx[9]={1,2,1,2,-1,-2,-1,-2, };
int dy[9]={2,1,-2,-1,2,1,-2,-1, };
queue< pair<int,int> > q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		flag=0;
		q=queue<pair<int,int> >();
		memset(dp,-1,sizeof(dp));
		int N;
		int a,b,x,y;
		cin>>N;
		cin>>a>>b;
		cin>>x>>y;
		if(a==x && b==y){
			cout<<"0\n";
			continue;
		}
		dp[a][b]=0;
		q.push({a,b});
		while(!q.empty()){
			int nowx=q.front().first;
			int nowy=q.front().second;
			q.pop();
			for(int nextx,nexty,i=0;i<8;i++){
				nextx=nowx+dx[i];
				nexty=nowy+dy[i];
				if(nextx>=N || nextx<0 ||nexty>=N || nexty<0 ) continue;
				if(dp[nextx][nexty]!=-1) continue;
				else{
					dp[nextx][nexty]=dp[nowx][nowy]+1;
					q.push({nextx,nexty});
				}
				if(nextx==x && nexty==y){
					cout<<dp[nextx][nexty]<<"\n";
					flag=1;
					break;
				}

			}
			if(flag==1) break;
		}
	}
	return 0;
}