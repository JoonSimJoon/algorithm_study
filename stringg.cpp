#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;
int main(){
	string a;
	for(int i=0;i<26;i++){
		cin>>a;
		v.push_back(a);
	}
	for(int i=0;i<26;i++){
		cout<<"\'"<<v[i]<<"\',";
	}
	return 0;
}
