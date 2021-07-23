#include <iostream>
using namespace std;
const int INF=987654321;
int arr[120][120];
int N,M;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//fill(&arr[0][0],&arr[119][119],INF);   
	cin>>N>>M;
	for(int a,b,c,i=0;i<M;i++){
		cin>>a>>b>>c;
		if(arr[a][b]==0) arr[a][b]=c;
		arr[a][b]=min(arr[a][b],c);
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				if(j==k || arr[j][i]==0 || arr[i][k]==0) continue;
				if(arr[j][k]==0) arr[j][k]=arr[j][i]+arr[i][k];
				else arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
			}
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			 cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}