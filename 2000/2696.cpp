#include <iostream>
#include <set>
using namespace std;
set<int> s;
set<int>::iterator it;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T,a;
	cin>>T;
	while(T--){
		s.erase(s.begin(),s.end());
		int N;
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>a;
			s.insert(a);
			if(i%2==0){
				it=s.begin();
				for(int j=0;j<i/2;j++) it++;
					cout<<*it<<" ";
			}
			if(i%19==0) cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}