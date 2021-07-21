#include <iostream>
#include <map>
using namespace std;
const int x = 10000000;
map<int,int> m;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin>>N;
	for(int a,i=0;i<N;i++){
		cin>>a;
		m[a+x]++;
	}
	int M;
	cin>>M;
	for(int a,i=0;i<M;i++){
		cin>>a;
		cout<<m[a+x]<<" ";
	}
	return 0;
}