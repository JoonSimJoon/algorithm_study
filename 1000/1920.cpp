#include <iostream>
#include <algorithm>
using namespace std;
int arr[100010],f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	sort(arr,arr+N);
	int M;
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>f;
		int ans=0;
		int st=0;
		int en=N;
		int m=(st+en)/2;
		while(st<en){
			m=(st+en)/2;
			if(arr[m]==f){
				ans=1;
				break;
			}else if(arr[m]<f){
				st=m+1;
			}else{
				en=m;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}