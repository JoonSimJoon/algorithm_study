#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		int N,flag=1;
		string a;
		v.resize(0);
		cin>>N;
		for (int i = 0; i < N; i++){
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		for (int i = 1; i < N; i++){
			int ss = min(v[i-1].size(),v[i].size());
			for (int j = 0; j < ss; j++){
				if(v[i-1][j]==v[i][j] && j==ss-1) flag=0;
				else if(v[i-1][j]!=v[i][j]) break;
			}
		}
		if(flag==0) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}	