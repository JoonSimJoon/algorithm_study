#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

int N, K;
int par[100010];
int rnk[100010];
int arr[2010][2010];

void init(){
	for(int i=1; i<=100000; i++) par[i] = i, rnk[i] = 1;
}

int find(int v){
	if(v == par[v]) return v;
	return par[v] = find(par[v]);
}

bool merge(int u, int v){
	u = find(u), v = find(v);
	if(u == v) return true;

	if(rnk[u] > rnk[v]) swap(u, v);
	par[u] = v;
	if(rnk[u] == rnk[v]) rnk[v]++;
	return false;
}

queue<p> q, qq;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

inline bool can(int i, int j){
	return (0<i && i<=N && 0<j && j<=N);
}

void bfs_union(){
	while(!q.empty()){
		int i = q.front().first;
		int j = q.front().second;
		qq.push(q.front());
		q.pop();

		for(int it=0; it<4; it++){
			int ii = i + di[it];
			int jj = j + dj[it];
			if(!can(ii, jj)) continue;
			if(arr[ii][jj] && arr[i][j] != arr[ii][jj]){
				if(!merge(arr[i][j], arr[ii][jj])){
					K--;
				}
			}
		}
	}
}

void bfs_propagation(){
	while(!qq.empty()){
		int i = qq.front().first;
		int j = qq.front().second;
		qq.pop();

		for(int it=0; it<4; it++){
			int ii = i + di[it];
			int jj = j + dj[it];
			if(!can(ii, jj)) continue;
			if(!arr[ii][jj]){
				arr[ii][jj] = arr[i][j]; q.push({ii, jj});
			}else if(arr[i][j] != arr[ii][jj]){
				if(!merge(arr[i][j], arr[ii][jj])){
					K--;
				}
			}
		}
	}
}

int main(){
	cin >> N >> K;
	for(int i=1; i<=K; i++){
		int a, b; scanf("%d %d", &a, &b);
		arr[a][b] = i;
		q.push({a, b});
	}
	init();
	int ans = 0;
	while(K > 1){
		bfs_union();
		if(K == 1){
			cout << ans; return 0;
		}
		bfs_propagation();
		ans++;
	}
	cout << ans;
}

