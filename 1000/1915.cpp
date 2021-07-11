//#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int N,M,big;
int arr[2010][2010];
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	//cin>>N>>M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	for(int i=1;i<N;i++){
		for(int j=1;j<M;j++){
			if(arr[i][j]!=0){ 
				arr[i][j]+=min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]));
			}

		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(big<arr[i][j]) big=arr[i][j];

		}
	}
	//cout<<big*big<<"\n";
	printf("%d\n",big*big);
	return 0;
}