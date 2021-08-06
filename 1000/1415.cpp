#include <set>
#include <iostream>
#include <vector>
using namespace std;


set<int> s;
set<int>::iterator it;
vector<int> v;
int prime[500010],N,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=2;i<=500000;i++){
		for(int j=2;i*j<=500000;j++){
			prime[i*j]=1;
		}
	}
	cin>>N;
	for(int a,i=0;i<N;i++){
		cin>>a;
		v.clear();
		if(i==0){
			s.insert(a);
			continue;
		}
		for(it = s.begin();it!=s.end();it++){
			v.push_back(a+*it);
		}
		int vl = v.size();
		for(int j=0;j<vl;j++){
			s.insert(v[j]);
		}
		s.insert(a);
	}
	for(it = s.begin();it!=s.end();it++){
		if(prime[*it]==0) ans++;
	}
	cout<<ans<<"\n";
	return 0;
}