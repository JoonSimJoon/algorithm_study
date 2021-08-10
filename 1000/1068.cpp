#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,K;
int cnt;
vector<int> v[100];
int check[100];
queue<int> q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for (int a,i = 0; i < N; i++){
		cin>>a;
		if(a!=-1) v[a].push_back(i);
		check[i] = a;
	}
	for(int i=0;i<N;i++){
		if(v[i].size()==0) cnt++;
	}
	cin>>K;
	int par = check[K];
	if(v[par].size()==1) cnt++;
	q.push(K);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(v[now].empty()) cnt--;
		else{
			int vl = v[now].size();
			for(int i=0;i<vl;i++){
				q.push(v[now][i]);
			}
		}
		
	}
	cout<<cnt;
	return 0;
}