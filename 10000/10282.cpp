#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		int N,D,C;
		cin>>N>>D>>C;
		vector<pair <int,int> > v[N+1];
		for(int i=0;i<N;i++){
			int a,b,c;
			cin>>a>>b>>c;
			v[b].push_back({a,c});
		}
		
	}
	return 0;
}
