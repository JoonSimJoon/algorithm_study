#include <iostream>
using namespace std;

int N;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(1){
		int arr[10]={0, },x=0,flag=0;
		cin>>N;
		if(N==0) break;
		while(N>0){
			arr[x]=N%10;
			N/=10;
			x++;
		}
		for(int i=0;i<x;i++){
			if(arr[i]!=arr[x-i-1]){
				flag=1;
				break;
			}
		}
		if(flag==0) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}