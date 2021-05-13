#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
priority_queue<int,vector<int>, greater<int> > pq;
vector<int> v[32010];
int arr[32010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		arr[y]++;
	}
	for(int i=1;i<=N;i++){
		if(arr[i]==0) pq.push(i);
	}
	while(!pq.empty()){
		int nd = pq.top();
		pq.pop();
		cout<<nd<<" ";
		int vl = v[nd].size();
		for(int i=0;i<vl;i++){
			arr[v[nd][i]]--;
			if(arr[v[nd][i]]==0) pq.push(v[nd][i]);
		}
	}
	return 0;
}
