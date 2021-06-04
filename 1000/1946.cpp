#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		int N,cnt=1,m;
		pair<int,int> p;
		vector<pair<int,int> > v;
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>p.first>>p.second;
			v.push_back(p);
		}
		sort(v.begin(),v.end());
		m=v[0].second;
		for(int i=1;i<N;i++){
			if(v[i].second<m){
				cnt++;
				m=v[i].second;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
