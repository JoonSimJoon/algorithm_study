#include <iostream>
#include <queue>
#include <string>
using namespace std;

int map[1010][1010];
int visited[1010][1010];
int cnt=0,ans=0;
int dx[5]={0,0,1,-1};
int dy[5]={1,-1,0,0};
int N,M;

int bfs(int x,int y){
	int maxc=0;
	visited[x][y]=cnt+1;
	queue< pair<int,int> > q;
	q.push({x,y});
	while(!q.empty()){
		maxc++;
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nextx = nowx+dx[i];
			int nexty = nowy+dy[i];
			if(nextx>=0 && nextx<N && nexty>=0 && nexty<M && visited[nextx][nexty]==0 && map[nextx][nexty]==1){
				visited[nextx][nexty]=cnt+1;
				q.push({nextx,nexty});
			}
		}
	}
	cnt++;
	return maxc;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==1 && visited[i][j]==0){
				int a = bfs(i,j);
				ans = max(a,ans);
			}
		}
	}
	cout<<cnt<<"\n"<<ans<<"\n";
	return 0;
}
