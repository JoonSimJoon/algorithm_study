#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int N;
string a;
vector<string> v;
int cmp(string x,string y){
	string aa=x+y;
	string bb=y+x;
	return aa>bb;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end(),cmp);
	
	//reverse(v.begin(),v.end());
	if(v[0]=="0" && N>1) cout<<"0";
	else{
		for(int i=0;i<N;i++){
			cout<<v[i];
		}
	}
	return 0;
}
