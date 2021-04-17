#include <iostream>
using namespace std;
int N,M,D;

int arr[20][20];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M>>D;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<arr[i][j];
		}
		cout<<"\n";

	}
	return 0;
}