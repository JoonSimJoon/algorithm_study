#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
vector<int> v[20010];
queue<int> q;
int arr[20010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,flag;
	cin>>t;
	while(t--){
		flag=0;
		for(int i=0;i<20010;i++) v[i].clear();
		q=queue<int>();
		memset(arr,0,sizeof(arr));
		int N,M;
		cin>>N>>M;
		for(int a,b,i=0;i<M;i++){
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int ik = 1;ik<=N;ik++){
			if(arr[ik]==0){
				q.push(ik);
				arr[ik]=1;
				while(!q.empty()){
					int now = q.front();
					q.pop();
					int vl = v[now].size();
					for(int next,i=0;i<vl;i++){
						next = v[now][i];
						if(arr[next]==0){
							arr[next]=-1*arr[now];
							q.push(next);
						}
						else if(arr[next]==arr[now]){
							flag=1;
							break;
						}
					}
					if(flag==1) break;
				}			
			}
			if(flag==1) break;
		}
			
		if(flag==1) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}