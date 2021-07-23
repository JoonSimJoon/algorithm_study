#include <iostream>
#include <string>
using namespace std;

int N,M;
string a;
int arr[60][60];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>a;
		for(int j=0;j<M;j++){
			if(a[j]=='W') arr[j][i]=1;
			else arr[j][i]=0;
		}
	}
	swap(N,M);
	int ans=50*50;
	for(int i=0;i<=N-8;i++){
		for(int j=0;j<=M-8;j++){
			int xcnt=0,ycnt=0;
			for(int x=i;x<i+8;x++){
				for(int y=j;y<j+8;y++){
					if(x%2==y%2){
						if(arr[x][y]==1) xcnt++;
						else ycnt++;
					}else{
						if(arr[x][y]==1) ycnt++;
						else xcnt++;
					}
				}
			}
			ans=min(ans,min(xcnt,ycnt));

		}
	}
	cout<<ans<<"\n";
	return 0;
}