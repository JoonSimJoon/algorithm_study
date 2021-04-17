#include <iostream>
using namespace std;
int N,M,ans;
int arr[140];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;i++){ 
		cin>>arr[i];
	}
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			for(int k=j+1;k<N;k++){

				if(arr[i]+arr[j]+arr[k] <=M && (M-arr[i]-arr[j]-arr[k])<=(M-ans)){
					ans=arr[i]+arr[j]+arr[k];
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}