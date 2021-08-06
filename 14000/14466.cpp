#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int dx[5]={0,0,-1,1};
int dy[5]={1,-1,0,0};
int road[102][102][102][102];
int arr[111][111];
int visited[111][111];
int N,K,R,ans,cnt;
vector<pair<int,int> > v;
queue<pair<int,int> > q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K>>R;
	for (int a,b,c,d,i = 0; i < R; i++){
		cin>>a>>b>>c>>d;
		road[a][b][c][d]=1;
		road[c][d][a][b]=1;
	}
	for (int a,b,i = 0; i < K; i++){
		cin>>a>>b;
		//arr[a][b]=1;
		v.push_back({a,b});
	}
	for (int i = 0; i < K-1; i++){
		cnt=0;
		memset(visited,0,sizeof(visited));
		q=queue<pair<int,int> >();
		int nrex=v[i].first;
		int nrey=v[i].second;
		visited[nrex][nrey]=1;
		q.push({nrex,nrey});
		while(!q.empty()){
			int nowx=q.front().first;
			int nowy=q.front().second;
			q.pop();
			for(int nextx,nexty,d=0;d<4;d++){
				nextx=nowx+dx[d];
				nexty=nowy+dy[d];
				if(nextx>N || nextx<=0 || nexty>N || nexty<=0) continue;
				else{
					if(visited[nextx][nexty]==1 || road[nowx][nowy][nextx][nexty]==1 || road[nextx][nexty][nowx][nowy]==1 ) continue;
					else{
						//cout<<nextx<<" "<<nexty<<"*\n";
						visited[nextx][nexty]=1;
						q.push({nextx,nexty});
					}
				}
			}
		}
		for(int j=i+1;j<K;j++){
			if(visited[v[j].first][v[j].second]==0) ans++;
		}
	}
	cout<<ans;

	return 0;
}