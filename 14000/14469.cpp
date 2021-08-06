#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,cnt;
int cp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first) return a.second<b.second;
	else return a.first<b.first;
}
vector<pair <int,int> > v;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for (int a, b, i = 0; i < N; i++){
		cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end(),cp);
	for(int i=0;i<N;i++){
		if(cnt<v[i].first){
			cnt=v[i].first+v[i].second;
		}else{
			cnt+=v[i].second;
		}
	}
	cout<<cnt;
	return 0;
}