#include <iostream>
using namespace std;

int N,K;
int arr[60][60];
int visited[60][60];
const int INF = 987654321;
int dfs(int x,int y,int cnt,int ans,int dis){
	if(K==-1) return INF;
	else{
		if(arr[x][y]==0){

		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
		}
	}
	dfs(0,0,0);

	return 0;
}