#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	string s;
	s="asdasdasd";
	int N,c1=0,c2=0;
	cin>>N;
	for(int i=2;i<=N;i++){
		int k=i;
		while(k%2==0 || k%5==0){
			if(k%2==0) k/=2,c1++;
			if(k%5==0) k/=5,c2++;
		
		}
		
	}
	cout<<min(c1,c2)<<"\n";
	return 0;
}