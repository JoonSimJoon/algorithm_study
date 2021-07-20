#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int par[10010];
int depth[10010];
int arr[10010];
queue<int> q;
vector<int> v[10010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		q=queue<int>();
		for(int i=0;i<10010;i++) v[i].clear();
		memset(depth,0,sizeof(depth));
		memset(arr,0,sizeof(arr));
		int N;
		cin>>N;
		for(int a,b,i=0;i<N-1;i++){
			cin>>a>>b;
			arr[b]=a;
			v[a].push_back(b);
		}
		int root;
		for(int i=1;i<=N;i++){
			if(arr[i]==0){ 
				root=i;
				break;
			}
		}
		depth[root]=1;
		q.push(root);
		while(!q.empty()){
			int now = q.front();
			q.pop();
			int vl = v[now].size();
			for(int next,i=0;i<vl;i++){
				next=v[now][i];
				depth[next]=depth[now]+1;
				q.push(next);
			}
		}
		int a,b;
		cin>>a>>b;
		while(a!=b){
			 if(depth[a]==depth[b]){
			 	a=arr[a];
			 	b=arr[b];
			 }else if(depth[a]>depth[b]){
			 	a=arr[a];
			 }else b=arr[b];
		}
		cout<<a<<"\n";
	}
	return 0;
}