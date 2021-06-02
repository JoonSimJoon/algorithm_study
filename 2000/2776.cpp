#include <iostream>
#include <set>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		set<int> s;
		set<int>::iterator iter;
		int N,M,a;
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>a;
			s.insert(a);
		}
		cin>>M;
		for(int i=0;i<M;i++){
			cin>>a;
			iter = s.find(a);
			if(iter!=s.end()) cout<<"1\n";
			else cout<<"0\n";
		}
	}
	return 0;
}
