#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
#define ll long long

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	int arr[550];
	while(T--){
		int N,cnt;
		ll ans=0;
		cin>>N;
		cnt=N-1;
		memset(arr,0,sizeof(arr));
		for(int i=0;i<N;i++){
			cin>>arr[i];
		}
		sort(arr,arr+N);
		ans+=arr[0]*cnt;
		for(int i=1;i<N;i++){
			ans+=arr[i]*cnt;
			cnt--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}