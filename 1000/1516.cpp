#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

ll N,x;
vector< vector<ll> > v(510);
queue<ll> q;
ll arr[510][4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>arr[i][0];
		while(1){
			cin>>x;
			if(x==-1) break;
			else{
				v[x].push_back(i);
				arr[i][1]++;
			}
		}
	}
	for(int i=1;i<=N;i++){
		if(arr[i][1]==0) q.push(i), arr[i][2]=arr[i][0];
	}
	while(!q.empty()){
		ll idx = q.front();
		q.pop();
		int vl = v[idx].size();
		for(int i=0;i<vl;i++){
			arr[v[idx][i]][1]--;
			arr[v[idx][i]][2] = max(arr[v[idx][i]][2], arr[idx][2]+arr[v[idx][i]][0]);
			if(arr[v[idx][i]][1]==0) q.push(v[idx][i]);
		}
	}
	for(int i=1;i<=N;i++) cout<<arr[i][2]<<"\n";
	return 0;
}