#include <iostream>
#include <string.h>
using namespace std;
#define ll long long

ll N,M,flag;
ll arr[300];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	memset(arr,-1,sizeof(arr));
	for(int a,b,c,i=0;i<M;i++){
		cin>>a>>b>>c;
		if(c==0){
			if(arr[b]==-1) arr[b]=a;
			else flag=1;
		}else{
			if(arr[b]==-1) flag=1;
			else{
				if(a-arr[b]<60){
					flag=1;
				}
				arr[b]=-1;
			}
		}
	}
	for(int i=0;i<=N;i++){
		if(arr[i]!=-1) flag=1;
	}
	if(flag) cout<<"NO";
	else cout<<"YES";
	return 0;
}