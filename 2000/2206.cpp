#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct s{
	int x,y;
	int smash=0;
	int cnt=0;
};


string a;
int map[1010][1010];
int visited[1010][1010];
int dx[5]={0,0,1,-1};
int dy[5]={1,-1,0,0};
int N,M;
queue<s> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>a;
		for(int j=0;j<M;j++){
			map[i][j]=a[j]-'0';
		}
	}
	s a;
	a.x=0;
	a.y=0;
	a.smash=0;
	a.cnt=0;
	q.push(a);
	while(!q.empty()){
		s nd,ndn;
		nd=q.front();
		q.pop();
		visited[nd.x][nd.y]=1;
		for(int i=0;i<4;i++){
			ndn.x=nd.x+dx[i];
			ndn.y=nd.y+dy[i];
			ndn.smash=nd.smash;
			ndn.cnt=nd.cnt+1;
			if(ndn.x<0 || ndn.x>=N || ndn.y<0 || ndn.y>=M) continue;
			else{
				if(visited[ndn.x][ndn.y]==1 ) continue;
				if(map[ndn.x][ndn.y]==0){
					q.push(ndn);
				}else{
					if(ndn.smash==0){
						ndn.smash=1;
						q.push(ndn);
					}
				}
			}
		}
	}
	return 0;
}
