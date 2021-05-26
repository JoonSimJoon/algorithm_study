#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int N,ans=1;
	cin>>N;
	int x= int(log2(N));
	for(int i=0;i<x;i++){
		ans*=2;
	}
	cout<<ans;
	
	
	
	return 0;
}
