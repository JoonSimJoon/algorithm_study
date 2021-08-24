#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
vector<int> ans[120];
ll N,M;
pair<int,int> arr[200];
pair<int,int> brr[200];

int cp(pair<int,int> a, pair<int,int> b){
	return a.second<b.second;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>arr[i].first;
		arr[i].second=i;
	}
	sort(arr,arr+N);
	reverse(arr,arr+N);
	for(int i=0;i<M;i++){
		cin>>brr[i].first;
		brr[i].second=i;
	}
	sort(brr,brr+M);
	reverse(brr,brr+M);
	for(int i=0;i<N;i++){
		for(int k=0;k<M;k++){
			if(arr[i].first==0) break;
			if(ans[brr[k].second].empty()){
				ans[brr[k].second].push_back(arr[i].second+1);
				arr[i].first--;
			}else{
				if(ans[brr[k].second].size()>=brr[k].first) continue;	
				ans[brr[k].second].push_back(arr[i].second+1);
				arr[i].first--;
			}
		}
	}

	for(int i=0;i<M;i++){
		int vl = ans[i].size();
		cout<<vl<<" ";
		for(int j=0;j<vl;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}