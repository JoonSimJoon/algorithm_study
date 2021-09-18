#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

ll N,cnt,ans,a,b,c;
ll arr[300010]; //arr:자기가 도착점인갯수
vector<ll> v[300010]; //자신에서 도달 가능한 노드
ll visited[300010]={0, };
vector<ll> ls;
queue<ll> q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(ll i=1;i<N;i++){
		cin>>a>>b>>c;
		if(c==0){
			v[a].push_back(b);
			v[b].push_back(a);
		}else{
			v[a].push_back(b);
			arr[b]++;
		}
	}
	for(ll i=1;i<=N;i++){
		if(arr[i]==0) ls.push_back(i);
	}
	ll vl = ls.size();
	for(ll tt=0;tt<vl;tt++){
		cnt=1;
		q=queue<ll>();
		memset(visited,0,sizeof(visited));
		q.push(ls[tt]);
		visited[ls[tt]]=1;
		while(!q.empty()){
			ll now = q.front();
			q.pop();
			ll vn = v[now].size();
			for(ll i=0;i<vn;i++){
				if(visited[v[now][i]]==0){
					visited[v[now][i]]=1;
					q.push(v[now][i]);
					cnt++;
				}
			}
		}
		if(cnt==N) ans++;
	}
	cout<<ans;
	return 0;
}