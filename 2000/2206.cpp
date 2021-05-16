#include <iostream>
#include <queue>
#include <string>
using namespace std;

int map[1010][1010];
int dp[1010][1010][3];
int dx[5]={0,0,1,-1};
int dy[5]={1,-1,0,0};
int N,M;
const int inf = 1e9+15;
string a;
queue<pair<pair<int, int> , int> > q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>a;
		for(int j=0;j<M;j++){
			map[i][j]=a[j]-'0';
			dp[i][j][0]=dp[i][j][1]=inf;
		}
	}
	q.push({{0,0},0});
	dp[0][0][0]=dp[0][0][1]=1;
	while(!q.empty()){
		pair<pair<int,int>, int> nd = q.front();
		pair<pair<int,int>, int> nx;
		q.pop();
		for(int i=0;i<4;i++){
			nx.first.first=nd.first.first+dx[i];
			nx.first.second=nd.first.second+dy[i];
			nx.second=nd.second;
			if(nx.first.first>=0 &&  nx.first.first<N && nx.first.second>=0 && nx.first.second<M ){
				if(map[nx.first.first][nx.first.second]==1){
					if(nx.second==1) continue;
					else nx.second=1;
				}
				if(dp[nx.first.first][nx.first.second][nx.second]<=dp[nd.first.first][nd.first.second][nd.second]+1) continue;
				q.push(nx);
				dp[nx.first.first][nx.first.second][nx.second]=dp[nd.first.first][nd.first.second][nd.second]+1;
				if(nx.first.first==N-1 && nx.first.second==M-1){
					while(!q.empty()) q.pop();
					break;
				}
			}
		}
	}
	int ans = min(dp[N-1][M-1][0],dp[N-1][M-1][1]);
	if(ans==inf) cout<<"-1\n";
	else cout<<ans<<"\n";
	return 0;
}
