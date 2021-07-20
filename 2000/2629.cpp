#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N,M,a;
set<int> s;
vector<int> v;
set<int>::iterator it;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a;
		if(i==0) s.insert(a);
		else{
			for(it=s.begin();it!=s.end();it++){
				v.push_back(a-*it);
				v.push_back(a+*it);
			}
			int vl = v.size();
			for(int i=0;i<vl;i++){
				if(v[i]>=0) s.insert(v[i]);
				else s.insert(-v[i]);
			}
			v.clear();
			s.insert(a);
		}
	}
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>a;
		if(s.find(a)==s.end()){
			cout<<"N ";
		}
		else cout<<"Y ";
	}
	return 0;
}