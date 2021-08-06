#include <iostream>
using namespace std;
#define ll long long
int dx[5]={0,0,1,-1};
int dy[5]={1,-1,0,0};
ll N,T,ans1=-1,ans2=-1;
ll arr[120][120];
int visited[120][120];
void dfs(int nowx,int nowy,int cnt1,int cnt2){
	if(nowx==N-1 && nowy==N-1){
		if(ans1*T + ans2 > cnt1*T + cnt2 || ans1==-1){
			ans1=cnt1;
			ans2=cnt2;
			return;
		}
	}

	for(int nextx,nexty,d=0;d<4;d++){
		nextx=nowx+dx[d];
		nexty=nowy+dy[d];
		if(nextx<0 || nextx>=N || nexty<0 || nexty>=N) continue;
		else{
			if(visited[nextx][nexty]==1) continue;
			else{
				visited[nextx][nexty]=1;
				int x=0;
				if(cnt1%3==2) x=arr[nextx][nexty];
				dfs(nextx,nexty,cnt1+1,cnt2+x);
				visited[nextx][nexty]=0;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>T;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
		}
	}
	visited[0][0]=1;
	dfs(0,0,0,0);

	cout<<T*ans1+ans2<<"\n";
	return 0;
}