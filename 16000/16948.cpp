#include <iostream>
#include <queue>
#define ll long long
using namespace std;
struct s{
	int x,y,cnt;
};
int dx[7]={-2,-2,0,0,2,2};
int dy[7]={-1,1,-2,2,-1,1};

int arr[210][210];
int visited[210][210];
int N,ans=-1;
int x1,y1,x2,y2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	cin>>x1>>y1>>x2>>y2;
	queue<s> q;
	s aa;
	aa.x=x1;
	aa.y=y1;
	aa.cnt=0;
	q.push(aa);
	while(!q.empty()){
		s now = q.front();
		q.pop();
		if(now.x==x2 && now.y==y2){
			ans=now.cnt;
			break;
		}
		else{
			s next;
			for(int i=0;i<6;i++){
				next.x=now.x+dx[i];
				next.y=now.y+dy[i];
				if(next.x<0 || next.y<0 || next.x>=N || next.y>=N) continue;
				else{
					if(visited[next.x][next.y]==1) continue;
					else{
						visited[next.x][next.y]=1;
						next.cnt = now.cnt+1;
						q.push(next);
					}
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}