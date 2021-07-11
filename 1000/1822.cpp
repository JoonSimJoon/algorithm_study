#include <iostream>
#include <set>
using namespace std;

set<int> s;
set<int>::iterator it;
int x;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>x;
		s.insert(x);
	}
	for(int i=0;i<M;i++){
		cin>>x;
		it= s.find(x);
		if(it!=s.end()) s.erase(it);
	}
	cout<<s.size()<<"\n";
	for(it=s.begin();it!=s.end();it++){
		cout<<*it<<" ";
	}
	return 0;
}