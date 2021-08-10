#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
vector<int> v[110];
queue<int> q;
int visited[110];
int N,M,ans,ansi,cnt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int a,b,i=0;i<M;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	ans=1000000;
	ansi=0;
	for(int tt=1;tt<=N;tt++){
		cnt=0;
		memset(visited,-1,sizeof(visited));
		q=queue<int>();
		visited[tt]=0;
		q.push(tt);
		while(!q.empty()){
			int now = q.front();
			q.pop();
			int nl = v[now].size();
			for(int i=0;i<nl;i++){
				if(visited[v[now][i]]==-1){
					cnt+=visited[now]+1;
					visited[v[now][i]]=visited[now]+1;
					q.push(v[now][i]);
				}
			}
		}
		if(ans>cnt){
			ans=cnt;
			ansi=tt;
		}
	}
	cout<<ansi;
	return 0;
}