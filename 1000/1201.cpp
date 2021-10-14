#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;

ll N,M,K;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M>>K;
	if(!(M+K-1<=N) || !(N<=M*K)){
		cout<<"-1\n";
		return 0;
	}else{
		vector<ll> v(N);
		for(ll i=0;i<N;++i){
			v[i]=i+1;
		}
		int idx = 0;
         for (int i = 1; i <= M; i++){
                 int temp = min(idx + K, N - M + i);
                 reverse(v.begin() + idx, v.begin() + temp);
                 idx = temp;
         }
         for (int i = 0; i < N; i++)
                 cout << v[i] << " ";
         cout << "\n";


	}
	return 0;
}